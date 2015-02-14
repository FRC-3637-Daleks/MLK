#ifndef _KINEMATICS_H_
#define _KINEMATICS_H_

#include <queue>
#include <math.h>
#include "Cartesian.h"

#define MAGNITUDE_GRAVITY 248
#define DEGREES_TO_RADIANS(x) ((x)/180.0*M_PI)

using std::queue;

class Kinematics
{
private:
	Cartesian position, velocity, acceleration, gravity;
    int calibration;  // Number of acceleration values to store
    queue<Cartesian> gravs;
	
public:
	Kinematics(const Cartesian &iPosition=Cartesian(), const Cartesian &iVelocity=Cartesian(), const int max=10): position(iPosition), velocity(iVelocity), calibration(10) {};
	Kinematics(const Kinematics &other): position(other.position), velocity(other.velocity), acceleration(other.acceleration), calibration(10) {};
	
public:
    void setGravity(const Cartesian accel);
    void calibrateGravity(const Cartesian g);   // arguments in degrees
    const int getCalibration() const {return calibration;};
	void update(const Cartesian& rawAcceleration, const bool calibrate=false);
    const Cartesian getAcceleration() const {return acceleration;};
	const Cartesian getVelocity() const {return velocity;};
	const Cartesian getPosition() const {return position;};
    
public:
    void setPosition(const Cartesian &pos) {position = pos;};
    void resetVelocity() {velocity();};
    void resetGravity();
};



#endif /*_KINEMATICS_H_*/