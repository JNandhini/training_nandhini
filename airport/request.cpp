#include "Request.h"
#include"Airport.h"
#include<ctime>
using namespace std;
void Request::set_flightid(int FlightId)
{
	
	this->FlightId;
}
int Request::get_flightid()
{
	return this->FlightId;
}
void Request::set_flightstate(string state)
{
	this->state;
}
string Request::get_flightstate()
{
	return this->state;
}
void Request::set_flighttime(int time)

	this->time;
}
int Request::get_flighttime()
{
	return this->time;
}
void Request::set_flightname(string FlightName)
{
	this->FlightName;
}
string Request::get_flightname()
{
	return this->FlightName;
}

Request::Request()
{
}

　
Request::~Request()
{
}
