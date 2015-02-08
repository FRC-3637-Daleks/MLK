#include "Cartesian.h"

Cartesian::Cartesian(const double ix, const double iy, const double iz): x(ix), y(iy), z(iz) {};

Cartesian::Cartesian(const Cartesian &other): x(other.x), y(other.y), z(other.z) {};

Cartesian& Cartesian::add(const Cartesian &other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

const Cartesian Cartesian::Add(const Cartesian& lArg, const Cartesian &rArg)
{
	return Cartesian(lArg.x + rArg.x, lArg.y + rArg.y, lArg.z + rArg.z);
}

const Cartesian Cartesian::Diff(const Cartesian& lArg, const Cartesian &rArg)
{
	return Cartesian(lArg.x - rArg.x, lArg.y - rArg.y, lArg.z - rArg.z);
}
