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
	const Cartesian getVelocity() const {return velocity;};
	const Cartesian getPosition() const {return position;};
    
public:
    void setPosition(const Cartesian &pos) {position = pos;};
    void resetVelocity() {velocity = Cartesian();};
};



#endif /*_KINEMATICS_H_*/