#include "Arduino.h"
#include "Defines.h"
#include "SynthChatterbox.h"

SynthChatterbox::SynthChatterbox(Module* inputs[])
{
  ModuleChatBot *chat_bot = new ModuleChatBot();
  
  chat_bot->word_input = inputs[PARAM1_INPUT];
  chat_bot->formant_scale_input = inputs[PARAM2_INPUT];
  chat_bot->pitch_input = inputs[SR_INPUT];
  chat_bot->trigger_input = inputs[RESET_INPUT];
  
  this->last_module = chat_bot;
}
