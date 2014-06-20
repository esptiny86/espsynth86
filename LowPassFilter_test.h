/*
 * LowPassFilter.h
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
 */

#ifndef LOWPASS_H_
#define LOWPASS_H_

// we are using .n fixed point (n bits for the fractional part)
#define FX_SHIFT 12
#define SHIFTED_1 ((byte) 4095)

/* A resonant low pass filter for audio signals. */

class LowPassFilter
{

private:
	uint32_t q;
	uint32_t f;
	uint32_t fb;
	int32_t buf0,buf1;

public:

	// constructor
	LowPassFilter()
	{
          buf0 = 0;
          buf1 = 0;
	}

	void setCutoffFreq(uint32_t cutoff)
	{
		f = cutoff;
		fb =  q + fxmul(q, SHIFTED_1 - cutoff);
	}

	void setResonance(uint32_t resonance)
	{
		q = resonance;
	}

	uint32_t next(uint32_t in)
	{
		buf0 += fxmul(((in - buf0) + fxmul(fb, buf0-buf1)), f);
		buf1 += fxmul(buf0-buf1, f); // could overflow if input changes fast
		return buf1;
	}

	int32_t fxmul(int32_t a, int32_t b)
	{
		return ((a*b)>>FX_SHIFT);
	}
};

#endif
