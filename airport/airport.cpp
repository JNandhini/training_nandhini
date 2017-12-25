#include "Airport.h"
#include<vector>
void Airport:: get_details()
{
	cout << "Enter the Airport Name" << endl;
	cout << "The Airport Name is" << endl;
	cin.ignore();
	getline(cin,AirportName);
	cout << endl;
	cout << "Enter the FlightName" << endl;
	cin.ignore();
	getline(cin,FlightName);
	cout << endl;
}
void Airport::request_generation()
{
    chrono::minutes m(2);
	cout << request.ltm->tm_sec;
	request.hour = request.ltm->tm_hour;
	//seconds = ltm->tm_sec;
	request.seconds = request.now + 500;  
	
	//tim = seconds+tim;
	this_thread::sleep_for(chrono::seconds(request.seconds));
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	request.StartTime = std::chrono::system_clock::to_time_t(start);
	end=chrono::system_clock::now()+m;
	time_t end_time=chrono::system_clock::to_time_t(end);
	cout<<ctime(&StartTime);
	cout<<end;
	if(start<end)
	{
		request.FlightId = (rand() % 9000) + 1000;
		cout << "The flight id is" << endl;
		cout << request.FlightId;
		request.set_flightid(request.FlightId);
		cout << "Enter the  state of the flight/// as landing or takeofff" << endl;
		cin.ignore();
		getline(cin,request.state);
		request.set_flightstate(request.state);
		cout << "\nThe flight id" << request.FlightId << "is requesting for runnway\n";
		cout << "The request Time is" << request.seconds;
		request.set_flighttime(ctime(&StartTime ));
		requet.push_back(request);
         	allocation_of_runway(request.FlightId, request.state, request.time);
	}
	else
	{
		cout<<"The program exits the limit\n";
	}
     
}
void Airport :: allocation_of_runway(int Flightid,string state,int time)
{ 
	if (runway1 == busy)
	{          
		cout << "The runway1 is allocated"<<endl;
		cout << "Request cannot be honored right now\n" << endl;
		
		
	}
	else if (runway1==idle)
	{     chrono::minutes min(15);
	 
		runway1 = request.FlightId;
		cout << "Runway is allocated to\n" << request.FlightId<<endl;
		time_t time=chrono::high_resolution_clock::now()+min;
		this_thread::chrono::minutes(15);
		
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
		time_t time=chrono::high_resolution_clock::now()+min;
		this_thread::chrono::minutes(15);
		
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
void Airport::checking_for_runway_availablity(chrono::seconds ms)
{
	if(queue.landing! =isempty())
	{ allocation_of_runway();
          for(int count=0;count<queue.landing.size();count++)
	  {    cout<<"\nThe number of flights in landing queue is\n";
		  cout<<queue.landing.at(count);
	  }
	}
	if(queue.takeoff!=isempty())
	{
		allocation_of_runway();
		for(int count=0;count<queue.takeoff.size();count++)
		{
			cout<<"The number of flights in takeoff queue is\n";
			cout<<queue.takeoff.at(count);
		}
	}
}

}
int main()
{
	std::chrono::seconds ms(4);
  std::chrono::time_point<std::chrono::high_resolution_clock>start, end;
 start=chrono::high_resolution_clock::now(); 
  std::time_t start_time = std::chrono::high_resolution_clock::to_time_t(start);
  cout<<ctime(&start_time);
        end = std::chrono::high_resolution_clock::now() + ms; // this is the end point
    std::time_t end_time = std::chrono::high_resolution_clock::to_time_t(end);
    
    while(std::chrono::high_resolution_clock::now() < end) // still less than the end?
    {   
    airport.request_generation();
} cout<<ctime(&end_time);
   
Airport::Airport()
{
}

　
Airport::~Airport()
{
}
