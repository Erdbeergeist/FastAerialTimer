#pragma once
#pragma comment( lib, "pluginsdk.lib" )

#include <string>
#include <chrono>
#include <iostream>
#include <fstream>
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "utils/parser.h"

class FastAerialTimer : public BakkesMod::Plugin::BakkesModPlugin
{
public:
	virtual void onLoad();
	virtual void onUnload();

	float t0;
	bool timing_started = false;
	bool timer_state = false;
	float best_session = -1;
	float all_time_best = -1;
	std::string savefile_path = "bakkesmod/data/fastaerialtimer.data";
	std::fstream AllTimeBestFile;

private:
	void onJump();
	void onCollision();
	void saveBestTime(float time);
	void resetAllTimeBest();
	void toggleOnOff();
};

