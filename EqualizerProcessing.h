#pragma once

#include "fftw3.h"
#include "State.h"

const int buffer_frame_count = 44100;

class EqualizerProcessing
{
public:
	EqualizerProcessing();
	~EqualizerProcessing();
	void processBuffer(float* input_buffer, State* state, float* outputBuffer, int size);
	double EqualizerProcessing::recalc_scale(int scale);
	int EqualizerProcessing::recalc_scale(double scale);
private:
	float *input, *output;
	fftwf_complex* out;
	fftwf_plan fft, ifft;
};
