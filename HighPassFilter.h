/*
 * HighPassFilter.h
 *
 * Derived from Tim's Lowpass Filter code.
 * Here's Tim's original license for the low-pass filter:
 *
 * Copyright 2012 Tim Barrass
 *
 * This file is part of Mozzi.
 *
 * Mozzi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Mozzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Mozzi.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 */

#ifndef HIGHPASS_H_
#define HIGHPASS_H_

// we are using .n fixed point (n bits for the fractional part)
#define FX_SHIFT 8
#define SHIFTED_1 ((unsigned char) 255)

/** A resonant high pass filter for audio signals.
*/
class HighPassFilter
{

public:


	/** Constructor.
	*/
	HighPassFilter(){
          buf0 = 0;
          buf1 = 0;
	}


	/** Set the cut off frequency,
	@param cutoff use the range 0-255 to represent 0-8192 Hz (AUDIO_RATE/2).
	Be careful of distortion at the lower end, especially with high resonance.
	*/
	void setCutoffFreq(unsigned char cutoff)
	{
		f = cutoff;
		fb = q+ucfxmul(q, SHIFTED_1 - cutoff);
	}


	/** Set the resonance.  If you hear unwanted distortion, back off the resonance.
	@param resonance in the range 0-255.
	*/
	void setResonance(unsigned char resonance)
	{
		q = resonance;
	}

	/** Calculate the next sample, given an input signal.
	@param in the signal input.
	@return the signal output.
	@note Timing: about 11us.
	*/
	//	10.5 to 12.5 us, mostly 10.5 us (was 14us)
	inline
	int next(int in)
	{
		buf0+=fxmul(((in - buf0) + fxmul(fb, buf0-buf1)), f);
		buf1+=ifxmul(buf0-buf1, f); // could overflow if input changes fast
		return(in - buf0);
	}


private:
	unsigned char q;
	unsigned char f;
	unsigned int fb;
	int buf0,buf1;

	// multiply two fixed point numbers (returns fixed point)
	inline
	unsigned int ucfxmul(unsigned char a, unsigned char b)
	{
		return (((unsigned int)a*b)>>FX_SHIFT);
	}
	
		// multiply two fixed point numbers (returns fixed point)
	inline
	int ifxmul(int a, unsigned char b)
	{
		return ((a*b)>>FX_SHIFT);
	}
	
	// multiply two fixed point numbers (returns fixed point)
	inline
	long fxmul(long a, int b)
	{
		return ((a*b)>>FX_SHIFT);
	}


};

#endif /* HIGHPASS_H_ */
