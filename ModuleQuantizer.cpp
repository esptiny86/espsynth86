#include "Arduino.h"
#include "ModuleQuantizer.h"
#include "defines.h"
#include "Scales.h"

uint16_t ModuleQuantizer::compute()
{
	uint32_t cv;
	uint32_t scale = this->readInput(this->scale_input, 0, 4);

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
	}
}