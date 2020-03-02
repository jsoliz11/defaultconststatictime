#include <iostream>
#include "Time2.h"

using namespace std;

int main()
{
    cout << "Number of Time2 Objects are: " << Time2::getCounter() << endl;
    //Time2::counter = 10; //this is an error. can't change private variable directly.
    {
        const int i = 2;
        Time2 anyTime(10, 52, 0, "Good Time");
        cout << "Number of Time2 Objects are: " << anyTime.getCounter() << endl;
        ++anyTime;
        cout << anyTime.getSecond() << endl;
        ++anyTime;
        anyTime.printTime();
        cout << "Number of Time2 Objects are: " << anyTime.getCounter() << endl;
        cout << "++++++++++++++++++++++++++++++" << endl;
        //cout << "Number of Time2 Objects are: " << anyTime::counter << endl;
    }

    cout << "Number of Time2 Objects are: " << Time2::getCounter() << endl;
    /*i += 3; //This is an error*/
    const Time2 noon(12, 0, 0, "Noon");
    cout << "Number of Time2 Objects are: " << noon.getCounter() << endl;
    const Time2 evening(17, 0, 0, "evening");
    cout << "Number of Time2 Objects are: " << evening.getCounter() << endl;
    cout << "==================================" << endl;
    //noon.setHour(10);//This is an error. Only const member functions can be used on const objects.
    cout << noon.getName()<< endl;
    cout << noon.getHour()<< endl;
    cout << "Only const member functions may act on const objects." << endl;
    cout << "Once a member function is changing the internal attributes, it cannot be declared const." << endl;
    cout << "Learning Default values, consts and statics within class" << endl;
    Time2 anyTimes(21, 0, 25, "Random");
    anyTimes.printTime();
    anyTimes - 5;
    anyTimes.printTime();
    return 0;
}
