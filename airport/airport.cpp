#pragma warning(disable:4996)
#include "airport.h" 

//get the airport name

void airport::get_details()
{
	cout << "Enter the Airport Name" << endl;
	cout << "The Airport Name is" << endl;
	cin.ignore();
	getline(cin, AirportName);
	cout << endl;
}

//generates the runway request autonatically

void airport::request_generation()
{ 
	std::chrono::time_point<std::chrono::system_clock> start;
	srand(time(0));
	chrono::seconds minutes((rand() % 9) + 10);
	string first[1] = { "Air" };
	string second[4] = { "ways", "line", "india", "jet" };
	FlightTime = (rand() % 90) + 30;

	//request time

	start = std::chrono::system_clock::now();
	time_t StartTime = std::chrono::system_clock::to_time_t(start);
	cout << endl << ctime(&StartTime);
	request.FlightId = (rand() % 9000) + 1000;
	request.FlightTime = StartTime;
	cout << "The flight id is" << endl;
	cout << request.FlightId;
	request.set_flightid(request.FlightId);
	state1 = rand() % 2;
	if (state1 == 0)
	{
		request.state = "takeoff";
	}
	else
	{
		request.state = "landing";
	}
	cout << "\nThe state of the flight is";
	cout << endl << request.state; 
	request.set_flightstate(request.state);
	request.FlightName = first[rand() % 1] + second[rand() % 4];
	request.set_flightname(request.FlightName);
	cout << "\nThe flight id " << request.FlightId << " is requesting for runnway\n";
	cout << "The request Time is " << ctime(&StartTime);
	request.set_flighttime(request.FlightTime);
	cout << "The flightname is " << request.FlightName << endl;
	
	//checking the state and pushing into the queue

	if (request.state == "landing")
	{
		
		queue.push(request);
	}
	else
	{
	
		queue.push(request);
	}
	count++;
	this_thread::sleep_for(chrono::seconds(FlightTime));
}

//checking availability and allocating the runway for request 

int airport::allocation_of_runway()
{
	chrono::seconds min(9);

	std::chrono::time_point<std::chrono::system_clock>start,end;
	start = chrono::system_clock::now();
	static int CheckTime = 0;
	static int duration = 0;
	static int difference = 0;
	static int difference1 = 0;
	int ElapsedTime = 0;
	int ElapseTime = 0;

	//checking the landing queue for empty

	if (!queue.landing.empty())
	{
		if (runway1 == idle)
		{
			iterate = 0;
			runway1 =  queue.landing[iterate].get_flightid();
			cout << "\nRunway1 is allocated to landing queue flightid"<< queue.landing[iterate].get_flightid() << endl;
			time_t rawtime;
			time(&rawtime);
			CheckTime = rawtime + 900; 
			start = chrono::system_clock::now();
			std::time_t start_time = std::chrono::system_clock::to_time_t(start);
			end = chrono::system_clock::now() + min;
			ElapsedTime = rawtime - queue.landing[iterate].get_flighttime();
			difference = ElapsedTime + difference;
			
			total++;
			//queue.pop();
			queue.pop();
			iterate++;
			cout << endl << "The elapsed time is " << ElapsedTime<<" seconds";
		}
		else if (runway2 == idle)
		{
			iterate = 0;
			runway2 =  queue.landing[iterate].get_flightid();
			cout << "\nRunway2 is allocated to landing queue flightid"<< queue.landing[iterate].get_flightid() << endl;
			start = chrono::system_clock::now();
			time_t rawtime;
			time(&rawtime);
			duration = rawtime+900;
			end = chrono::system_clock::now();
			std::time_t Startime = std::chrono::system_clock::to_time_t(start);
			ElapseTime = rawtime - queue.landing[iterate].get_flighttime();
			difference = ElapseTime + difference;
			cout << endl << "\nThe elapsed time for the request is " << ElapseTime << " seconds";
			
			total++;
			queue.pop();
			iterate++;
	}
	}

	//checking for takeoff queue 

	else if (!queue.takeoff.empty())
	{
		if (runway1 == idle)
		{
			iterator = 0;
			runway1 = queue.takeoff[iterator].get_flightid();
			cout << "Runway1 is allocated to takeoff queue  flightid\n" << queue.takeoff[iterator].get_flightid() << endl;
			start = chrono::system_clock::now();			
			time_t rawtime;
			time(&rawtime);
			CheckTime = rawtime+900;
			time_t start_time = std::chrono::system_clock::to_time_t(start);
			end = chrono::system_clock::now();
			ElapsedTime = rawtime - queue.takeoff[iterator].get_flighttime();
			difference1 = ElapsedTime + difference1;
			cout << endl << "The elapsed time is" << ElapsedTime << " seconds";
			total1++;
				queue.pop();
			iterator++;
			
		}

		else if (runway2 == idle)
		{
			iterator = 0;
			runway2 =   queue.takeoff[iterator].get_flightid();
			cout << "Runway2 is allocated to takeoff queue flightid\n" << queue.takeoff[iterator].get_flightid() << endl;
			start = chrono::system_clock::now();
			std::time_t Start_time = std::chrono::system_clock::to_time_t(start);
			time_t rawtime;
			time(&rawtime);
			duration = rawtime+900;
			end = chrono::system_clock::now();
			ElapseTime = rawtime - queue.takeoff[iterator].get_flighttime();
			difference1 = ElapseTime + difference1;
			cout << endl << "The elapsed time is " << ElapseTime << " seconds";
			total1++; 
			queue.pop();
			iterator++;
			
		}
	}
time_t rawtime;
time(&rawtime);

//checking for runway 

if (rawtime == CheckTime)
{
	CheckTime = 0;
	runway1 = 0;
	return 0;
}
else if (rawtime == duration)
{
	duration = 0;
	runway2 = 0;
	return 0;
}
if (rawtime == CheckTime)
{
	CheckTime = 0;
	runway1 = 0;
	return 0;
}
else if (rawtime == duration)
{
	duration = 0;
	runway2 = 0;
	return 0;
}
 }
