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
        cout<<"a.x="<<razor.getStuff()->getAcceleration().m_x<<", a.y="<<razor.getStuff()->getAcceleration().m_y<<endl;
    }
    
    return 0;
}