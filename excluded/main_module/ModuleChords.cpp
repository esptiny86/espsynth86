#include "Arduino.h"
#include "ModuleChords.h"
#include "Defines.h"
#include "GlobalScales.h"
#include "GlobalChords.h"

ModuleChords::ModuleChords()
{
	// Initialize all inputs
	this->root_note_input = NULL;
	this->chord_input = NULL;

	// Instantiate all outputs
	this->note_1_output = new ModuleOutput(this);
	this->note_2_output = new ModuleOutput(this);
	this->note_3_output = new ModuleOutput(this);    
}

uint16_t ModuleChords::compute()
{
	uint16_t root_note_input = this->readInput(this->root_note_input, 0, 60);
	uint16_t chord_input = this->readInput(this->chord_input, CONVERT_TO_5_BIT);  // 0 - 31

	this->note_1_output->value = NOTES[CHROMATIC[(uint8_t) min((root_note_input + CHORDS[chord_input][0]),60)]];
	this->note_2_output->value = NOTES[CHROMATIC[(uint8_t) min((root_note_input + CHORDS[chord_input][1]),60)]];
	this->note_3_output->value = NOTES[CHROMATIC[(uint8_t) min((root_note_input + CHORDS[chord_input][2]),60)]];

	return(this->note_3_output->value);
}