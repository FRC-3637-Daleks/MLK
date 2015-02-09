#ifndef _CARTESIAN_H_
#define _CARTESIAN_H_

#include <stdlib.h>

struct Cartesian
{
public:
	double m_x, m_y, m_z;
	
public:
	constexpr Cartesian(const double ix=0.0, const double iy=0.0, const double iz=0.0): m_x(ix), m_y(iy), m_z(iz) {};
	Cartesian(const Cartesian &other);
    void operator() (const double ix=0.0, const double iy=0.0, const double iz=0.0);
    Cartesian& operator= (const Cartesian& other);
	
public:
	Cartesian& add(const Cartesian& other);
	
public:
	static const Cartesian Add(const Cartesian& lArg, const Cartesian& rArg);
	static const Cartesian Diff(const Cartesian& lArg, const Cartesian& rArg);
};

#endif /*_CARTESIAN_H_*/