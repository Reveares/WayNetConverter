#pragma once
#include <string>
#include <vector>
#include <memory>

struct Waypoint
{
	Waypoint(std::string name, double x, double y, double z, double dX, double dZ)
		: name(name), x(x), y(y), z(z), dX(dX), dZ(dZ) {}

	std::string name;
	double x, y, z;
	double dX, dZ;
	std::vector<std::string> connections;
};

struct Way
{
	int objectId;
	std::shared_ptr<Waypoint> waypoint;
};
