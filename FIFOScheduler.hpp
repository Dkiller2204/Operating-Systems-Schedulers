#pragma once
#include "Scheduler.hpp"

class FIFOScheduler :
	public Scheduler
{
public:
	FIFOScheduler(std::string name);
	~FIFOScheduler();

	void arrive(Job job);
	std::string update();
	std::string handleCompletion();
};

