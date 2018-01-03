#include "queueclas.h"

#include<iostream>

using namespace std;

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

void queueclas::display()

{

	if (!landing.empty())

	{

		for (iterate = 0; iterate < landing.size(); iterate++)

		{

			cout << landing[iterate].get_flightid() << endl;

			cout << landing[iterate].get_flightstate() << endl;

			cout << landing[iterate].get_flighttime() << endl;

		}

	}

	if (!takeoff.empty())

	{

		for (iterate = 0; iterate < takeoff.size(); iterate++)

		{

			cout << takeoff[iterate].get_flightid() << endl;

			cout << takeoff[iterate].get_flightstate() << endl;

			cout << takeoff[iterate].get_flighttime() << endl;

		}

	}

}


    
