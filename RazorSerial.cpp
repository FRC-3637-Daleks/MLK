#include <sstream>

#include "RazorSerial.h"

const bool RazorSerial::update()
{
    using std::stringstream;
    
    if(input == nullptr)
        return false;
   
    char buf[255];
    input->getline(buf, 255);
    float roll, pitch, yaw;
    int x, y, z;
    
    sscanf(buf, "!ANG:%f,%f,%f,ACC:%d,%d,%d", &roll, &pitch, &yaw, &y, &x, &z);
    Cartesian accel(x, y, z);
    
    if(calibrations++ < 40)
        us.update(accel, true);
    else
        us.update(accel);
    
    return true;
}

const Kinematics * const RazorSerial::getStuff()
{
    if(!update())
        return NULL;
    
    return &us;
}