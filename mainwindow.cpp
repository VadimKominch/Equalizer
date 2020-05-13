#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "RtAudio.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "State.h"

//left and right channel of signal
static float left[44100];
static float right[44100];
static EqualizerProcessing* equalizer = new EqualizerProcessing();
State* MainWindow::state = new State();

// Two-channel sawtooth wave generator.
int inout(void* outputBuffer, void* inputBuffer, unsigned int nBufferFrames,
    double streamTime, RtAudioStreamStatus status, void* userData)
{
    unsigned long* bytes = (unsigned long*)userData;


    if (status) std::cout << "Stream over/underflow detected." << std::endl;
    //unsigned int* bytes = (unsigned int*)userData;

    // prepare channel  fft data
    for (size_t i = 0; i < buffer_frame_count; ++i)
    {
        left[i] = reinterpret_cast<float*>(inputBuffer)[2 * i];
        right[i] = reinterpret_cast<float*>(inputBuffer)[2 * i + 1];
    }
    //4701
    // process channel 
    equalizer->processBuffer(left,MainWindow::state,left,buffer_frame_count);
    
    equalizer->processBuffer(right, MainWindow::state,right,buffer_frame_count);

    //concat two channels together
    for (size_t i = 0; i < buffer_frame_count; ++i)
    {
        reinterpret_cast<float*>(outputBuffer)[2 * i] = left[i];
        reinterpret_cast<float*>(outputBuffer)[2 * i + 1] = right[i];
    }
    return 0;
}

float recalc_scale(int scale)
{
    double res = pow(10., scale / 20.0);
    return (float)res;
}



MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if (audio.getDeviceCount() < 1) {
        std::cout << "\nNo audio devices found!\n";
        return;
    }
    
    RtAudio::StreamParameters iParameters,oParameters;
    iParameters.deviceId = audio.getDefaultInputDevice();
    iParameters.nChannels = 2;
    oParameters.deviceId = audio.getDefaultOutputDevice();
    oParameters.nChannels = 2;
    unsigned int sampleRate = 44100;
    unsigned int data = 0,bufferFrames = 44100;
    try {
        audio.openStream(&oParameters, &iParameters, RTAUDIO_FLOAT32,
            sampleRate, &bufferFrames, &inout, (void*)&data);

        data = bufferFrames * oParameters.nChannels * sizeof(RTAUDIO_FLOAT32);

        audio.startStream();
    }
    catch (RtAudioError & e) {
        e.printMessage();
        return;
    }
}

MainWindow::~MainWindow()
{
    
    try {
        // Stop the stream
        audio.stopStream();
    }
    catch (RtAudioError & e) {
        e.printMessage();
    }
    if (audio.isStreamOpen()) audio.closeStream();
    delete(state);
    delete ui;
}

void MainWindow::setUpFrequences()
{
    float _scales[6];
    for (int i = 0; i < ui->horizontalLayout->count(); ++i) {
        QSlider* sl = ((QSlider*)ui->horizontalLayout->itemAt(i)->widget());
        _scales[i] = recalc_scale(sl->value());
    }

    state->setScales(_scales);
}

void MainWindow::on_pushButton_2_clicked()
{
    float _scales[6];
    for (int i = 0; i < ui->horizontalLayout->count(); ++i) {
        QSlider* sl = ((QSlider*)ui->horizontalLayout->itemAt(i)->widget());
        _scales[i] = recalc_scale(sl->value());
    }

    state->setScales(_scales);
}




void MainWindow::on_pushButton_clicked()
{
    ui->verticalSlider->setValue(0);
    ui->verticalSlider_2->setValue(0);
    ui->verticalSlider_3->setValue(0);
    ui->verticalSlider_4->setValue(0);
    ui->verticalSlider_5->setValue(0);
    ui->verticalSlider_6->setValue(0);
    setUpFrequences();
}
