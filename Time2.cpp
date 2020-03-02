#include "Time2.h"
using namespace std;
int Time2::counter = 0;
Time2::Time2(int h, int m, int s, string n)
:name(n)//This is how you initialize const values. (anyobject(value))
{
    counter++;
    try{
        setHour(h).setMinute(m).setSecond(s);
    }catch(const char* e){
        throw e;
    }

}

Time2::~Time2()
{
    counter--;
}

int Time2::getHour() const
{
    return hour;
}

int Time2::getMinute() const
{
    return minute;
}

int Time2::getSecond() const
{
    return second;
}

string Time2::getName() const
{
    return name;
}

int Time2::getCounter()
{
    return counter;
}

Time2& Time2::setHour(int h)
{
    if(h >= 0 && h <= 23)
    {
        hour = h;
       return *this;
    }
    else
    {
        throw "Invalid hour input.";
    }

}

Time2& Time2::setMinute(int m)
{
    if(m >= 0 && m <= 59)
    {
        minute = m;
       return *this;
    }
    else
    {
        throw "Invalid minute input.";
    }
    return *this;
}

Time2& Time2::setSecond(int s)
{
    if(s >= 0 && s <= 59)
    {
        second = s;
       return *this;
    }
    else
    {
        throw "Invalid second input.";
    }
    return *this;
}

Time2& Time2::printTime()
{
    cout << hour << " : " << minute << " : " << second << endl;
}

bool Time2::operator == (Time2 a)
{
    if(hour == a.getHour() && minute == a.getMinute() && second == a.getSecond()){
        return true;
    }else{
        return false;
    }
}

bool Time2::operator != (Time2 a)
{
    return !(*this == a);
}

Time2& Time2::operator ++ ()//add second
{
    if( second== 59 )
	{
		if( minute == 59 )
		{
			//cout<<endl<<"hh: "<<*hh<<" mm: "<<*mm<<" ss:"<<*ss<<endl;

			if(hour == 23){
				hour=0;
			}
			else{
                hour++;
                minute=0;
                second=0;
			}
		}
		else
		{
			minute++;
			second=0;
		}
	}
	else
	{
		second++;
	}
}

Time2 Time2::operator + (int a)
{
    int h, m, s;
    h = a / 3600;
    a = a % 3600;
    m = a / 60;
    s = a % 60;
    if((second + s) > 59)
        {
            second == 0;
            minute++;
        }
        else
        {
            second += s;
        }

    if ((minute + m) > 59)
    {
        minute = 0;
        hour++;
    }
    else{
        minute += m;
    }
    if((hour + h) > 23)
    {
        hour = 0;
    }
    else
    {
        hour += h;
    }

    cout << h << " " << m << " " << s << endl;
    return *this;
}


