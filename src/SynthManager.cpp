#include "SynthManager.h"

SynthManager::SynthManager()
{
    this->index = 0;
    this->oscReader = NULL;
    this->multiplexer = NULL;
}

void SynthManager::attachOscReader(OSCBundleReader *osc_reader)
{
    this->oscReader = osc_reader;
}

void SynthManager::attachMultiplexer(AnalogMultiplexerPin *multi_plexer)
{
    this->multiplexer = multi_plexer;
}

void SynthManager::addSynth(SynthExtended *synth)
{
    this->synthCollection.push_back(synth);
    synth->setup();
}

void SynthManager::setSynth(int idx)
{
    this->index = idx;
}

void SynthManager::slowLoop()
{
  static uint8_t idx = 0;
  //skip if no pot input needed

  Input_Manager * inputManager = &this->synthCollection[index]->inputManager;

  if ( inputManager->pot.size() > 0)
  {
    //Read analog multiplexer
    inputManager->pot[idx]->setValue(multiplexer->read(inputManager->pot[idx]->pot_index,NOISE));
    //Round robin reading
    idx++;
    if (idx > (inputManager->pot.size()-1) ) idx = 0;
  }
}

void SynthManager::run()
{
    static uint16_t counter = 0;
    static int16_t cycle = 0;

    if (this->synthCollection.size() == 0) return;

    SynthExtended * synth = this->synthCollection[index];

    synth->run(cycle++);


    if ( this->oscReader != NULL ) this->oscReader->readToInputManager(&synth->inputManager);

    if (this->multiplexer != NULL) {
        // read potentiometer
        if (counter > SAMPLINGFREQUENCY / 250)
        {
          counter = 0;
          slowLoop();
        }

        counter++;
    }


}
