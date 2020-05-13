#include "EqualizerProcessing.h"
#include "EqualizerProcessing.h"
#include <cmath>
#include <string.h>

EqualizerProcessing::EqualizerProcessing()
{
    out = fftwf_alloc_complex(sizeof(fftwf_complex)*buffer_frame_count);
    input = fftwf_alloc_real(buffer_frame_count);
    output = fftwf_alloc_real(buffer_frame_count);
    fft = fftwf_plan_dft_r2c_1d(buffer_frame_count, input, out, FFTW_ESTIMATE);
    ifft = fftwf_plan_dft_c2r_1d(buffer_frame_count, out, output, FFTW_ESTIMATE | FFTW_PRESERVE_INPUT);
    //out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * buffer_frame_count);
}

EqualizerProcessing::~EqualizerProcessing()
{
    fftwf_destroy_plan(fft);
    fftwf_destroy_plan(ifft);
    fftwf_free(out);
    fftwf_free(input);
    fftwf_free(output);
}



void EqualizerProcessing::processBuffer(float* buffer, State* state, float* outputBuffer, int N)
{
    memcpy(input,buffer,sizeof(float)*buffer_frame_count);
    fftwf_execute(fft);
    float* scales;
    scales = state->getScales();
    int left_border = state->getFrequencyBorders(0);
    int right_border;
    for (int i = 0;i < 6;i++)
    {
        right_border = state->getFrequencyBorders(i+1);

        for (int j = left_border; j < right_border; j++)
        {
            //real part lies in zero element of each cell
            //scale it to the value of scale index
            //scale for buffer_count
            out[j][0] = out[j][0] * *(scales + i)/buffer_frame_count;
            out[j][1] = out[j][1] * *(scales + i)/buffer_frame_count;

        }
            left_border = right_border;
    }
    fftwf_execute(ifft);
    memcpy(outputBuffer,output,sizeof(float)*buffer_frame_count);
    
}


double EqualizerProcessing::recalc_scale(int scale)
{
    double res = pow(10., scale / 20.0);
    return res;
}

int EqualizerProcessing::recalc_scale(double scale)
{
    double res = log10(scale) * 20;
    return static_cast<int>(res);
}