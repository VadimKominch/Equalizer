#pragma once

class State
{

public:
	~State();
	State();
	void setScales(float _scales[6]);
	float* getScales();
	int getFrequencyBorders(int num);
private:
	//hardcoded frequencies
	float scales[6];
	int frequncy_borders[7] = {0, 50, 100, 1000, 5000, 10000, 22050};
//	void getScalesFromWidget(Ui::MainWindow* ui);

};

//add borders for all frequencies
