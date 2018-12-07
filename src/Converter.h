#pragma once
#include "Waypoint.h"
#include <string>
#include <vector>
#include <map>

class Converter
{
public:
	void read(const std::string fileName);
	void write(const std::string fileName) const;

private:
	std::vector<std::string> split(const std::string line) const;

	std::map<int, std::shared_ptr<Waypoint>> waypoints;
};