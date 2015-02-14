#include <math.h>
#include "Kinematics.h"

void Kinematics::calibrateGravity(const Cartesian g)
{
    if(calibration == 0)
        return;
    Cartesian sumGrav(gravity.m_x*gravs.size(), gravity.m_y*gravs.size(), gravity.m_z*gravs.size());
    sumGrav.add(g);
    gravs.push(g);
    if(gravs.size() >= calibration)
    {
        sumGrav.subtract(gravs.front());
        gravs.pop();
    }
    gravity(sumGrav.m_x/gravs.size(), sumGrav.m_y/gravs.size(), sumGrav.m_z/gravs.size());
}

void Kinematics::resetGravity()
{
    while(!gravs.empty()) gravs.pop();
}

void Kinematics::update(const Cartesian& rawAcceleration, const bool calibrate)
{
    if(calibrate)
        calibrateGravity(rawAcceleration);
	acceleration = Cartesian::Diff(rawAcceleration, gravity);
	auto halfVel(velocity);                 // old velocity
	velocity.add(getAcceleration());      // new velocity
	halfVel.add(velocity);
	halfVel(halfVel.m_x/2.0, halfVel.m_y/2.0, halfVel.m_z/2.0);   // average of the two
	position.add(halfVel);  // new position
}



