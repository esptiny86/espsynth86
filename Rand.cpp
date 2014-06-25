#include "Arduino.h"
#include "Rand.h"

Rand::Rand()
{
	x = 132456789;
	y = 362436069;
	z = 521288629;
}

uint32_t Rand::xorshift96()
{

	uint32_t t;

	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;

	t = x;
	x = y;
	y = z;
	z = t ^ x ^ y;

	return z;
}

void Rand::seed(uint32_t seed)
{
	x = seed;
	y = 362436069;
	z = 521288629;	
}

uint32_t Rand::random(uint32_t min, uint32_t max)
{
	return (uint32_t) ((((xorshift96() & 0xFFFF) * (max-min))>>16) + min);
}

// Return a random number between 0 and max-1, inclusive
uint32_t Rand::random(uint32_t max)
{
	return (uint32_t) (((xorshift96() & 0xFFFF) * max)>>16);
}

// Return a random number between 0 and 4095, inclusive
uint32_t Rand::random()
{
	return (uint32_t) (((xorshift96() & 0xFFFF) * 4096)>>16);
}

