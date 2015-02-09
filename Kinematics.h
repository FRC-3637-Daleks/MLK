#ifndef _KINEMATICS_H_
#define _KINEMATICS_H_

#include <math.h>
#include "Cartesian.h"

#define MAGNITUDE_GRAVITY 248
#define DEGREES_TO_RADIANS(x) ((x)/180.0*M_PI)

class Kinematics
{
private:
	Cartesian position, velocity, acceleration, gravity;
    int calibration;  // the higher this is the less easily gravity can be averaged
	
public:
	Kinematics(const Cartesian &iPosition=Cartesian(), const Cartesian &iVelocity=Cartesian()): position(iPosition), velocity(iVelocity), calibration(0) {};
	Kinematics(const Kinematics &other): position(other.position), velocity(other.velocity), acceleration(other.acceleration), calibration(0) {};
	
public:
    void calibrateGravity(const double roll, const double pitch, const double yaw);   // arguments in degrees
    const int getCalibration() const {return calibration;};
	void update(const Cartesian& rawAcceleration);
    const Cartesian getAcceleration() const {return acceleration;};
	const Cartesian getVelocity() const {return velocity;};
	const Cartesian getPosition() const {return position;};
    
public:
    void setPosition(const Cartesian &pos) {position = pos;};
    void resetVelocity() {velocity();};
};



#endif /*_KINEMATICS_H_*/