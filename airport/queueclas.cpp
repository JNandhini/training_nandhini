#include "queueclas.h"
#include<iostream>
using namespace std;

//pushes the request into the queue

void queueclas::push(Request req)
{
	if (req.state == "landing")
	{
		landing.push_back(req);
	}
	if (req.state == "takeoff")
	{
		takeoff.push_back(req);
	}
}

//removes the request allocated

void queueclas::pop()
{
	if (!landing.empty())
	{
		landing.erase(landing.begin());
	}
	if (!takeoff.empty())
	{
		takeoff.erase(takeoff.begin());
	}
}

//displays the request in queue

void queueclas::display()
{
	if (!landing.empty())
	{
		cout << "The request in landing queue is";
		for (iterate = 0; iterate < landing.size(); iterate++)
		{
			
			cout <<"\nThe flightid is"<< landing[iterate].get_flightid() << endl;
			cout <<"The flightstate is" <<landing[iterate].get_flightstate() << endl;
			cout <<"The flighttime is"<< landing[iterate].get_flighttime() << endl;
		}
	}
	if (!takeoff.empty())
	{
		cout << "The request in takeoff queue is";
		for (iterator = 0; iterator < takeoff.size(); iterator++)
		{
			
			cout << "\nThe flightid is"<< takeoff[iterator].get_flightid() << endl;
			cout <<"The flight state is"<< takeoff[iterator].get_flightstate() << endl;
			cout <<"The flight time is"<< takeoff[iterator].get_flighttime() << endl;
		}
	}
}
