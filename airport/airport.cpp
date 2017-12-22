#include "Airport.h"
#include<vector>
void Airport:: get_details()
{
	cout << "Enter the Airport Name" << endl;
	cout << "The Airport Name is" << endl;
	cin >> AirportName;
	cout << endl;
	cout << "Enter the FlightName" << endl;
	cin >> FlightName;
	cout << endl;
}
void Airport::request_generation()
{

	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	request.StartTime = std::chrono::system_clock::to_time_t(start);
	cout << request.ltm->tm_sec;
	request.hour = request.ltm->tm_hour;
	//seconds = ltm->tm_sec;
	request.seconds = request.now + 5;
	//tim = seconds+tim;
	if (request.seconds < 7200)
	{
		request.FlightId = (rand() % 9000) + 1000;
		cout << "The flight id is" << endl;
		cout << request.FlightId;
		request.set_flightid(request.FlightId);
		cout << "Enter the state of the flight as landing or takeofff" << endl;
		cin >>request.state;
		request.set_flightstate(request.state);
		cout << "\nThe flight id" << request.FlightId << "is requesting for runnway\n";
		cout << "The request Time is" << request.seconds;
		request.set_flighttime(request.seconds);
		requet.push_back(request);
		allocation_of_runway(request.FlightId, request.state, request.time);
	}

}
void Airport :: allocation_of_runway(int Flightid,string state,int time)
{
	if (runway1 == busy)
	{
		cout << "The runway1 is allocated"<<endl;
		cout << "Request cannot be honored right now" << endl;
		
	}
	else if (runway1==idle)
	{
		runway1 = request.FlightId;
		cout << "Runway is allocated to" << request.FlightId<<endl;
		
	}

	else if (runway2 == busy)
	{
		cout << "The runway2 is allocated" << endl;
		cout << "Request cannot be honored right now\n";

	}
	else if (runway2 == idle)
	{
	
		runway2 = request.FlightId;
		cout << "  Runway2 is allocated" << endl;
		
	}
	else if (runway1 == busy&&runway2 == busy)
	{
		if (state == "landing")
		{
			iterator = iterator++;
			queue.push(landing[iterator]);
			
		}
		if (state == "takeoff")
		{
			iterate = iterate++;
			queue.push(takeoff[iterate]);
		}
	}

}
void Airport::checking_for_runway_availablity()
{

}
Airport::Airport()
{
}

　
Airport::~Airport()
{
}
