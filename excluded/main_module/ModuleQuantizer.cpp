#include "Arduino.h"
#include "ModuleQuantizer.h"
#include "Defines.h"
#include "GlobalScales.h"

uint16_t ModuleQuantizer::compute()
{
	uint32_t cv;
	uint32_t scale = this->readInput(this->scale_input, 0, 15);

	// The NOTES array and scale arrays are defined in Scales.h/Scales.cpp

	switch(scale) {
		case 0:
			cv = this->readInput(this->cv_input, 0, 60);
			return(NOTES[CHROMATIC[cv]]);
		case 1:
			cv = this->readInput(this->cv_input, 0, 36);
			return(NOTES[IONIAN[cv]]);
		case 2:
			cv = this->readInput(this->cv_input, 0, 35);
			return(NOTES[DORIAN[cv]]);
		case 3:
			cv = this->readInput(this->cv_input, 0, 35);
			return(NOTES[LYDIAN[cv]]);
		case 4:
			cv = this->readInput(this->cv_input, 0, 35);
			return(NOTES[PHRYGIAN[cv]]);
		case 5:
			cv = this->readInput(this->cv_input, 0, 35);
			return(NOTES[MIXOLYDIAN[cv]]);			
		case 6:
			cv = this->readInput(this->cv_input, 0, 35);
			return(NOTES[AEOLIAN[cv]]);			
		case 7:
			cv = this->readInput(this->cv_input, 0, 35);
			return(NOTES[LOCRIAN[cv]]);
		case 8:
			cv = this->readInput(this->cv_input, 0, 25);
			return(NOTES[MAJOR_PENTATONIC[cv]]);
		case 9:
			cv = this->readInput(this->cv_input, 0, 25);
			return(NOTES[MINOR_PENTATONIC[cv]]);
		case 10:
			cv = this->readInput(this->cv_input, 0, 30);
			return(NOTES[BLUES[cv]]);
		case 11:
			cv = this->readInput(this->cv_input, 0, 40);
			return(NOTES[DIMINISHED[cv]]);
		case 12:
			cv = this->readInput(this->cv_input, 0, 40);
			return(NOTES[ARABIAN[cv]]);
		case 13:
			cv = this->readInput(this->cv_input, 0, 15);
			return(NOTES[MAJOR[cv]]);
		case 14: 
			cv = this->readInput(this->cv_input, 0, 15);
			return(NOTES[MINOR[cv]]);
		case 15: 
			cv = this->readInput(this->cv_input, 0, 42);
			return(NOTES[PRISM[cv]]);
	}
}