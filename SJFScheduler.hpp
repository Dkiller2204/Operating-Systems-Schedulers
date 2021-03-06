#pragma once
#include "Scheduler.hpp"
#include <algorithm>
class SJFScheduler :
	public Scheduler
{
public:
	SJFScheduler(std::string name);
	~SJFScheduler();

	void arrive(Job job);
	std::string update();
	std::string handleCompletion();
};

