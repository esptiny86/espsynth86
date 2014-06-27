/*
 * LowPassButterworthFilter.h
 */

#ifndef LOWPASS_BUTTERWORTH_H_
#define LOWPASS_BUTTERWORTH_H_


class LowPassFilterButterworth
{

public:


	/** Constructor.
	*/
	LowPassFilterButterworth()
	{
		q = 0;
		p = 0;
		f = 0;

		b0 = 0;
		b1 = 0;
		b2 = 0;
		b3 = 0;
		b4 = 0;

		t1 = 0;
		t2 = 0;
	}


	/** Set the cut off frequency,
	@param cutoff use the range 0-255 to represent 0-8192 Hz (AUDIO_RATE/2).
	Be careful of distortion at the lower end, especially with high resonance.
	*/
	void setFC(int32_t fc, int32_t res)
	{
		q = 4096-fc;
		p = (((3277*fc)>>12)*q)>>12;
		f = p + p - 4096;
		q = (res*(4096+((2048*((q*(4096-q+((22938*((q*q)>>12))>>12)))>>12))>>12)))>>12;
	}

	uint32_t next(int32_t input)
	{
		uint32_t out;
		input -= (q*b4)>>12;
		t1 = b1;
		b1=(((input+b0)*p)>>12)-((b1*f)>>12);
		t2 = b2;
		b2=(((b1+t1)*p)>>12)-((b2*f)>>12);
		t1=b3;
		b3=(((b2+t2)*p)>>12)-((b3*f)>>12);
		b4=(((b3+t1)*p)>>12)-((b4*f)>>12);
		b4 = b4-((((((b4*b4)>>12)*b4)>>12)*683)>>12);
		b0 = input;
		out = b4;
		return out;
	}


private:
	uint32_t q;
	uint32_t p;
	uint32_t f;
	uint32_t b0;
	uint32_t b1;
	uint32_t b2;
	uint32_t b3;
	uint32_t b4;
	uint32_t t1;
	uint32_t t2;	
};

#endif /* LOWPASS_BUTTERWORTH_H_ */
