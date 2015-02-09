#include <math.h>
#include "Kinematics.h"

void Kinematics::calibrateGravity(const double roll, const double pitch, const double yaw)
{
    Cartesian sumGrav(gravity.m_x*calibration, gravity.m_y*calibration, gravity.m_z*calibration);
    sumGrav.add(Cartesian(MAGNITUDE_GRAVITY*sin(roll), MAGNITUDE_GRAVITY*sin(pitch), MAGNITUDE_GRAVITY*cos(yaw)));
    calibration++;
    gravity(sumGrav.m_x/calibration, sumGrav.m_y/calibration, sumGrav.m_z/calibration);
}

void Kinematics::update(const Cartesian& rawAcceleration)
{
	acceleration = Cartesian::Diff(rawAcceleration, gravity);
	auto halfVel(velocity);                 // old velocity
	velocity.add(getAcceleration());      // new velocity
	halfVel.add(velocity);
	halfVel(halfVel.m_x/2.0, halfVel.m_y/2.0, halfVel.m_z/2.0);   // average of the two
	position.add(halfVel);  // new position
}