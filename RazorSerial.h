#ifndef _RAZOR_SERIAL_H_
#define _RAZOR_SERIAL_H_

#include "Kinematics.h"

#include <iostream>

using std::istream;

class RazorSerial
{
private:
    istream *input;
    Kinematics us;
    
private:
    const bool update();
    
public:
    RazorSerial(istream * const in, const Cartesian initPos=Cartesian()): input(in), us(initPos) {};
    
public:
    const Kinematics * const getStuff();
};



#endif /*_RAZOR_SERIAL_H_*/