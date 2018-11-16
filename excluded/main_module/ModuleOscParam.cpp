#include "Arduino.h"
#include "ModuleOscParam.h"
#include "Defines.h"

ModuleOscParam::ModuleOscParam()
{
	// Initialize all module inputs to NULL
	this->waveform_input = NULL;
	this->pitch_input = NULL;
	this->fine_input = NULL;

	// Instantiate all outputs
	this->osc1_waveform = new ModuleOutput(this);
	this->osc2_waveform = new ModuleOutput(this);
	this->osc3_waveform = new ModuleOutput(this);

	this->osc1_pitch = new ModuleOutput(this);
	this->osc2_pitch = new ModuleOutput(this);
	this->osc3_pitch = new ModuleOutput(this);

	this->vca1_volume = new ModuleOutput(this);
	this->vca2_volume = new ModuleOutput(this);
	this->vca3_volume = new ModuleOutput(this);
}

uint16_t ModuleOscParam::compute()
{
	uint32_t select = readInput(this->waveform_input, CONVERT_TO_4_BIT);
	uint32_t pitch = readInput(this->pitch_input);
	uint32_t fine = readInput(this->fine_input,0,68);
	
	this->osc1_pitch->value = pitch;
	this->osc2_pitch->value = pitch + fine - 34;
	this->osc3_pitch->value = pitch - 819;

	switch(select)
	{
		case 0:
			this->osc1_waveform->value = 0<<7;
	        this->osc2_waveform->value = 0<<7;
	        this->osc3_waveform->value = 0<<7;
			
			this->vca1_volume->value = 4095;
	        this->vca2_volume->value = 4095;
	        this->vca3_volume->value = 2048;
			
			break;
		case 1:
			this->osc1_waveform->value = 0<<7;
	        this->osc2_waveform->value = 1<<7;
	        this->osc3_waveform->value = 0<<7;
			
			this->vca1_volume->value = 4095;
	        this->vca2_volume->value = 4095;
	        this->vca3_volume->value = 2048;
			
			break;
		case 2:
			this->osc1_waveform->value = 1<<7;
	        this->osc2_waveform->value = 1<<7;
	        this->osc3_waveform->value = 0<<7;
			
			this->vca1_volume->value = 4095;
	        this->vca2_volume->value = 4095;
	        this->vca3_volume->value = 2048;
			
			break;
		case 3:
		    this->osc1_waveform->value = 1<<7;
            this->osc2_waveform->value = 2<<7;
            this->osc3_waveform->value = 0<<7;
			
		    this->vca1_volume->value = 4095;
            this->vca2_volume->value = 4095;
            this->vca3_volume->value = 2048;
			
		    break;

		case 4:
		    this->osc1_waveform->value = 2<<7;
            this->osc2_waveform->value = 2<<7;
            this->osc3_waveform->value = 0<<7;
			
		    this->vca1_volume->value = 4095;
            this->vca2_volume->value = 3000;
            this->vca3_volume->value = 2048;
			
		    break;
		case 5:
		    this->osc1_waveform->value = 0<<7;
            this->osc2_waveform->value = 2<<7;
            this->osc3_waveform->value = 0<<7;
			
		    this->vca1_volume->value = 4095;
            this->vca2_volume->value = 3000;
            this->vca3_volume->value = 2048;
			
		    break;
		case 6:
		    this->osc1_waveform->value = 3<<7;
            this->osc2_waveform->value = 1<<7;
            this->osc3_waveform->value = 0<<7;
			
		    this->vca1_volume->value = 4095;
            this->vca2_volume->value = 3000;
            this->vca3_volume->value = 2048;
			
		    break;
		case 7:
		    this->osc1_waveform->value = 1<<7;
            this->osc2_waveform->value = 2<<7;
            this->osc3_waveform->value = 1<<7;
			
		    this->vca1_volume->value = 4095;
            this->vca2_volume->value = 4095;
            this->vca3_volume->value = 4095;
			
		    break;
		case 8:
		    this->osc1_waveform->value = 3<<7;
            this->osc2_waveform->value = 1<<7;
            this->osc3_waveform->value = 0<<7;
			
		    this->vca1_volume->value = 4095;
			this->vca2_volume->value = 4095;
			this->vca3_volume->value = 1024;
			
		    break;

		case 9:
		    this->osc1_waveform->value = 2<<7;
			this->osc2_waveform->value = 4<<7;
			this->osc3_waveform->value = 0<<7;
			
		    this->vca1_volume->value = 4095;
			this->vca2_volume->value = 4095;
			this->vca3_volume->value = 2048;
			
		    break;

		case 10:
		    this->osc1_waveform->value = 1<<7;
			this->osc2_waveform->value = 5<<7;
			this->osc3_waveform->value = 0<<7;
			
		    this->vca1_volume->value = 4095;
			this->vca2_volume->value = 3000;
			this->vca3_volume->value = 2048;
			
		    break;
		
		case 11:
		    this->osc1_waveform->value = 3<<7;
			this->osc2_waveform->value = 3<<7;
			this->osc3_waveform->value = 0<<7;
			
		    this->vca1_volume->value = 4095;
			this->vca2_volume->value = 4095;
			this->vca3_volume->value = 2048;
			
		    break;

		case 12:
		    this->osc1_waveform->value = 5<<7;
			this->osc2_waveform->value = 1<<7;
			this->osc3_waveform->value = 0<<7;
			
		    this->vca1_volume->value = 4095;
			this->vca2_volume->value = 3000;
			this->vca3_volume->value = 1024;
			
		    break;
		case 13:
			this->osc1_waveform->value = 6<<7;
	    	this->osc2_waveform->value = 3<<7;
			this->osc3_waveform->value = 0<<7;
			
		    this->vca1_volume->value = 4095;
	            this->vca2_volume->value = 4095;
	            this->vca3_volume->value = 2048;
			
		    break;
		case 14:
		    this->osc1_waveform->value = 6<<7;
			this->osc2_waveform->value = 7<<7;
			this->osc3_waveform->value = 3<<7;
			
		    this->vca1_volume->value = 4095;
			this->vca2_volume->value = 4095;
			this->vca3_volume->value = 3000;
			
		    break;
		    
		case 15:
		    this->osc1_waveform->value = 8<<7;
			this->osc2_waveform->value = 8<<7;
			this->osc3_waveform->value = 8<<7;
			
		    this->vca1_volume->value = 4095;
			this->vca2_volume->value = 4095;
			this->vca3_volume->value = 2048;
			
		    break;

	}

	return(this->osc1_waveform->value);
}
