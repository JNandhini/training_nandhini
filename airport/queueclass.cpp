#include "Queueclas.h"
#include<iostream>
using namespace std;
void Queueclas::push(Request req)
{
	if (state == "landing")
	{
		landing.push_back(req);
	}
	if (state == "takeoff")
	{
		takeoff.push_back(req);
	}
}

void Queueclas::pop()
{
	for (iterate = 0; iterate < landing.size(); iterate++)
	{
		cout << landing[iterate].get_flightid();		
		cout << landing[iterate].get_flightstate();
		cout << landing[iterate].get_flighttime();
	}
	for (iterate = 0; iterate < takeoff.size(); iterate++)
	{
		cout << takeoff[iterate].get_flightid();
		cout << takeoff[iterate].get_flightstate();
		cout << takeoff[iterate].get_flighttime();
	}
	landing.pop_back();
}
bool Queueclas::isempty()
{
	if (landing.empty())
	{
		cout << "queue is empty";
		return 0;
	}
}
