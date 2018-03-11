#include "Scheduler.hpp"

int Scheduler::timePassed = 1;
bool Scheduler::areCompleted = false;

Scheduler::Scheduler(std::string name) :name(name), isCompleted(false)
{
}

Scheduler::~Scheduler()
{
}

void Scheduler::arrive(Job job) {
	currentJobs.push_back(job);
	isCompleted = false;
}

std::string Scheduler::update() {
	if (!currentJobs.empty()) {
		std::string jobName = currentJobs.front().process();
		if (!jobName.empty() && !responseTimes[jobName]) {
			Job job = currentJobs.front();
			responseTimes[jobName] = (Scheduler::timePassed+1 - job.mArrival);
		}
		return jobName;
	}
	return "";
}

std::string Scheduler::handleCompletion() {
	if (!currentJobs.empty()) {
		std::string jobName = currentJobs.front().isCompleted();
		if (!jobName.empty()) {
			Job job = currentJobs.front();
			turnoverTimes[jobName] = (Scheduler::timePassed+1 - job.mArrival);
			currentJobs.pop_front();
			return jobName;
		}
	}
	else {
		isCompleted = true;
	}
	return "";
}

float Scheduler::processResponseTimeAverage() {
	float average;
	int turnoverSum = 0, counter = 0;

	std::map<std::string, int>::iterator it;
	for (it = turnoverTimes.begin(); it != turnoverTimes.end(); it++)
	{
		turnoverSum += it->second;
		counter++;
	}

	return turnoverSum / counter;
}

float Scheduler::processTurnoverTimeAverage() {
	float average;
	int responseSum = 0, counter = 0;

	std::map<std::string, int>::iterator it;
	for (it = responseTimes.begin(); it != responseTimes.end(); it++)
	{
		responseSum += it->second;
		counter++;
	}

	return responseSum / counter;
}