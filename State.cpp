#include "State.h"

State::State()
{
	for (int i = 0; i < 6; i++)
	{
		scales[i] = 1;
	}
}


void State::setScales(float _scales[6]) 
{
	for (int i = 0; i < 6; i++)
	{
		scales[i] = _scales[i];
	}
}

float* State::getScales()
{
	return scales;
}

int State::getFrequencyBorders(int num)
{
	return frequncy_borders[num];
}

State::~State()
{
}
