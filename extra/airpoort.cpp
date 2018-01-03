#pragma warning(disable:4996)
#include "Airport.h" 
//Airport airport;
Request request;

void Airport::get_details()
{
	cout << "Enter the Airport Name" << endl;
	cout << "The Airport Name is" << endl;
	cin.ignore();
	getline(cin, AirportName);
	cout << endl;
}
void Airport::request_generation()
{
	
	std::chrono::time_point<std::chrono::system_clock> start;
	srand(time(0));
	chrono::seconds m(3);
	string first[1] = { "Air" };
	string second[4] = { "ways", "line", "india", "jet" };
	this_thread::sleep_for(chrono::seconds(m));
	start = std::chrono::system_clock::now();
	time_t StartTime = std::chrono::system_clock::to_time_t(start);
	cout << endl << ctime(&StartTime);
	request.FlightId = (rand() % 9000) + 1000;
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
	StartTime = request.ltm->tm_hour;
	request.set_flighttime(StartTime);
	cout << "Time" << endl << StartTime;
	cout << "The flightname is " << request.FlightName << endl;
	//if (request.state == "landing")
	//{
		queue.push(request);
	//}
	//else
	//{
		//queue.push(request);
	//}

	//requet.push_back(request);
	count++;
	
	
}
int Airport::allocation_of_runway()

{

	chrono::seconds min(9);
	std::chrono::time_point<std::chrono::system_clock>start, end;
	start = chrono::system_clock::now();
	static double ElapsedTime = 0;
	static double ElapseTime = 0;
	int startd = 0;
	int endd = 9;
		
	if (!queue.landing.empty())
	{
		if (runway1 == idle)
		{
			runway1 = 1;// queue.landing[iterate].get_flightid();
			cout << "Runway1 is allocated to landing queue\n";// << queue.landing[iterate].get_flightid() << endl;
			//queue.pop();
			queue.pop();
			 localtime(&request.now);
			 cout << "yime " << request.now;
			start = chrono::system_clock::now();
			iterate++;
			end = chrono::system_clock::now() + min;
			chrono::duration <double>elapse_time = end - start;
			cout << endl << elapse_time.count();
			ttime = elapse_time.count();
			ElapsedTime = ttime + ElapsedTime;
			difference = ElapsedTime;
			cout << endl << difference;
			return 0;

			
			
		}
		else if (runway2 == idle)
		{
			runway2 = 1;// queue.landing[iterator].get_flightid();
			cout << "Runway2 is allocated to landing queue";// << queue.landing[iterator].get_flightid() << endl;
			start = chrono::system_clock::now();
			//queue.display();//queue.push(request);
			iterator++;
			cout << iterator;
			//	this_thread::sleep_for(chrono::seconds(9));

				queue.pop();
			cout << "iterator" << iterator;
			end = chrono::system_clock::now();
			chrono::duration <double>elapsed_time = end - start;
			//cout << endl << elapsed_time.count();
			ttime = elapsed_time.count();
			ElapsedTime = ttime + ElapsedTime;
			difference = ElapsedTime;
			cout << endl << difference;
			return 0;
		}
	}

　
　
	else if (!queue.takeoff.empty())
	{
		if (runway1 == idle)
		{
			//	if (request.state != "landing")
			//{
			runway1 = 1;// queue.takeoff[iterator].get_flightid();
			cout << "Runway1 is allocated to takeoff queue\n";// << queue.takeoff[iterator].get_flightid() << endl;
			start = chrono::system_clock::now();
			//	this_thread::sleep_for(chrono::seconds(9));
			//queue.pop(); 
			queue.pop();
			iterate++;
			end = chrono::system_clock::now();
			chrono::duration <double>elapse_time = end - start;
			ttime = elapse_time.count();
			ElapseTime = ttime + ElapseTime;
			difference1 = ElapseTime;
			cout << endl << difference;
			return 0;
			//}
			/*
		else
		{
		runway1 = request.FlightId;
		cout << "Runway2 is allocated " << endl;
		queue.push(request);

		}	}*/
		}

　
　
		/*else if (!queue.landing.empty())
		{

　
		}
		*/

　
		//	if (request.state != "landing")
		//	{
		else if (runway2 == idle)
		{
			runway2 = 1;// queue.takeoff[iterate].get_flightid();
			cout << "Runway2 is allocated to takeoff queue\n";// << queue.takeoff[iterate].get_flightid() << endl;
			start = chrono::system_clock::now();
			//	this_thread::sleep_for(chrono::seconds(9));

			//queue.push(request);
			// queue.pop(); 
			queue.pop();
			iterate++;
			cout << iterate;
			end = chrono::system_clock::now();
			chrono::duration <double>elapse_time = end - start;
			cout << endl << elapse_time.count();
			ttime = elapse_time.count();
			ElapseTime = ttime + ElapseTime;
			difference1 = ElapseTime;
			cout << endl << difference;
			return 0;
		}
	}

	if(chrono::system_clock::now()==start + min)
	{
		cout << "hai" << endl;
		runway1 = 0;
		return 0;
	}
	 if (chrono::system_clock::now()==start + min)
	{
		runway2 = 0;
		return 0;
	}
	if (start + min == chrono::system_clock::now())
	{
		runway1 = 0;
		return 0;
	}
	else if (start + min == chrono::system_clock::now())
	{
		runway2 = 0;
		return 0;
	}
	/*	else
		{
		runway2 = request.FlightId;
		cout << "Runway2 is allocated " << endl;
		this_thread::sleep_for(chrono::seconds(9));

		//queue.push(request);

		}*/

　
　
	/*
		 else if (runway1 != 0 && runway2 != 0)
		 {
		 if (request.state == "landing")
		 {
		 queue.push(request);
		 iterator = iterator++;
		 }
		 if (request.state == "takeoff")
		 {
		 iterate = iterate++;
		 queue.push(request);
		 }
		 }*/
	/*
	else if (runway2 != 0)
	{
	cout << "The runway2 is allocated" << endl;
	cout << "Request cannot be honored right now\n";

	}*/

	/*	 if (startd < endd)
		 {
		 cout << "The runway1 is already allocated" << endl;
		 cout << "Request cannot be honored right now\n" << endl;
		 startd++;
		 runway1 = 1;
		 if (startd == endd)
		 {
		 runway1 = 0;
		 }
		 }*/

　
}
		 
	 void Airport::calculate_elapsedtime()
	 {
		 difference = difference / iterator;
		 difference1 = difference1 / iterate;

	 }

	
#pragma warning(disable:4996)
#include"Airport.h"
#include<future>
Airport airport;

　
void call();
void calling();
void sleep();

int main()
{
	Airport airport;
	
    async(call);
	async(calling);
	airport.queue.display();
//	async(sleep);
	//airport.get_details();
/*	while (std::chrono::system_clock::now() < end) // still less than the end? 
	{
		airport.allocation_of_runway();

	}
	while (std::chrono::system_clock::now() < end) // still less than the end? 
	{
		airport.allocation_of_runway1();

	}
	//async(sleep);*/

	//async(&Airport::request_generation, &airport);
  // async(&Airport::allocation_of_runway,&airport);
	//async(&Airport::allocation_of_runway1,&airport);
   //	cout << ctime(&end_time);
	system("pause");
	cin.ignore(1000,'\n');

}
void call()
{
	std::chrono::seconds ms(90);
	std::chrono::time_point<std::chrono::system_clock>start, end;
	start = chrono::system_clock::now();
	std::time_t start_time = std::chrono::system_clock::to_time_t(start);
	cout << ctime(&start_time);
	end = std::chrono::system_clock::now() + ms; // this is the end point 
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	cout << "hai0";
	while (std::chrono::system_clock::now() < end) // still less than the end? 
	{
		airport.request_generation();

	}

//	airport.request_generation();
	/*time_t minutes;
	tm *ltm = localtime(&minutes);
	while (minutes > minutes + 1800)
	{
	break;
	}*/

}
void calling()
{
	std::chrono::seconds ms(9);
	std::chrono::time_point<std::chrono::system_clock>start, end;
	start = chrono::system_clock::now();
	std::time_t start_time = std::chrono::system_clock::to_time_t(start);
	cout << ctime(&start_time);
	end = std::chrono::system_clock::now() + ms; // this is the end point 
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	while (std::chrono::system_clock::now() < end) // still less than the end? 
	{
		airport.allocation_of_runway();
	}
}
/*
void sleep()
{
std::chrono::seconds ms(90);
std::chrono::time_point<std::chrono::system_clock>start, end;
start = chrono::system_clock::now();
std::time_t start_time = std::chrono::system_clock::to_time_t(start);
cout << ctime(&start_time);
end = std::chrono::system_clock::now() + ms; // this is the end point
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
while (std::chrono::system_clock::now() < end) // still less than the end?
{
airport.allocation_of_runway1();
}
*/
//airport.allocation_of_runway1();
//}/*
//void sleep()
//{
//airport.request_generation();

　
//this_thread::sleep_for(chrono::seconds(15));

/*chrono::seconds min(15);
std::chrono::time_point<std::chrono::system_clock>start, end;
start = chrono::system_clock::now();
end = chrono::system_clock::now() + min;
time_t endTime = std::chrono::system_clock::to_time_t(end);

this_thread::sleep_for(chrono::seconds(15));

airport.runway1 = request.FlightId;
cout << "hai";
cout << "end"<<ctime(&endTime);
}*/
　
　
　
 
