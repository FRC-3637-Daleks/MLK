#include "Kinematics.h"

void Kinematics::update(const Cartesian& currentAcceleration)
{
	acceleration = currentAcceleration;
	auto halfVel(velocity);
	velocity.add(currentAcceleration);
	halfVel.add(velocity);
	halfVel = Cartesian(halfVel.x/2.0, halfVel.y/2.0, halfVel.z/2.0);
	position += halfVel;
}