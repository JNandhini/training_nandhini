#include "Request.h"

using namespace std;

//assigns and return the flightid 

void Request::set_flightid(int FlightId)
{

	this->FlightId;
}
int Request::get_flightid()
{
	return this->FlightId;
}

//assigns and returns the flighttime

void Request::set_flightname(string FlightName)
{
	this->FlightName;
}
string Request::get_flightname()
{
	return this->FlightName;
}

//assigns and returns the flightstate

void Request::set_flightstate(string state)
{
	this->state;
}
string Request::get_flightstate()
{
	return this->state;
}

//assigns and returns the flightname

void Request::set_flighttime(int FlightTime)
{
	this->FlightTime;
}
int Request::get_flighttime()
{
	return this->FlightTime;
}
