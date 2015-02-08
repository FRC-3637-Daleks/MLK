#ifndef _KINEMATICS_H_
#define _KINEMATICS_H_

#include "Cartesian.h"

class Kinematics
{
private:
	Cartesian position, velocity, acceleration;
	
public:
	Kinematics(const Cartesian &iPosition, const Cartesian &iVelocity): position(iPosition), velocity(iVelocity) {};
	Kinematics(const Kinematics &other): position(other.position), velocity(other.velocity), acceleration(other.acceleration) {};
	
public:
	void update(const Cartesian& currentAcceleration);
	void getVelocity() const {return velocity;};
	void getPosition() const {return position;};	
};



#endif _KINEMATICS_H_