#ifndef Rand_h
#define Rand_h

//
// Based on the Mozzy (http://sensorium.github.io/Mozzi/) random number code, which in 
// turn is based on George. (2003). Xorshift RNGs. http://www.jstatsoft.org/v08/i14/xorshift.pdf
//

class Rand
{
  public:
    Rand();

	uint32_t xorshift96();
	void seed(uint32_t seed);
	uint32_t random(uint32_t min, uint32_t max);
	uint32_t random(uint32_t max);
	uint32_t random();
  
  private:
  	unsigned long x,y,z;
  	// uint16_t random_number_table[4095];
  	// uint16_t seed_value;
  	// uint16_t step;
};

#endif