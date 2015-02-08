#ifndef _CARTESIAN_H_
#define _CARTESIAN_H_

#include <stdlib.h>

struct Cartesian
{
public:
	double x, y, z;
	
public:
	Cartesian(const double ix=0.0, const double iy=0.0, const double iz=0.0);
	Cartesian(const Cartesian &other);
	
public:
	Cartesian& add(const Cartesian& other);
	
public:
	static const Cartesian Add(const Cartesian& lArg, const Cartesian& rArg);
	static const Cartesian Diff(const Cartesian& lArg, const Cartesian& rArg);
};

#endif /*_CARTESIAN_H_*/