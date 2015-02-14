#include <iostream>
#include "RazorSerial.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    
    RazorSerial razor(&cin);
    
    while(cin.peek() != '!')
        cout<<char(cin.get());
    
    cout<<"Razor initialized"<<endl;
    while(true)
    {
        cout<<"v.x="<<razor.getStuff()->getVelocity().m_x<<", v.y="<<razor.getStuff()->getVelocity().m_y<<endl;
    }
    
    return 0;
}