#pragma warning(disable:4996)
#include "Airport.h" 
//Airport airport;
Request request;
/*
void calling()
{
	airport.allocation_of_runway();
}

/*void call()
{

	airport.allocation_of_runway1();
}
void sleep()
{
	airport.request_generation();

　
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
	
	/*srand(time(0));
	chrono::seconds m(2);
	string first[1] = { "Air" };
	string second[4] = { "ways", "line", "india", "jet" };
	this_thread::sleep_for(chrono::seconds(m));
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	time_t StartTime = std::chrono::system_clock::to_time_t(start);
	end = chrono::system_clock::now() + m;
	time_t end_time = chrono::system_clock::to_time_t(end);*/
	//	cout << endl << ctime(&StartTime);
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
		//cout << "The request Time is " << ctime(&StartTime);
		//request.set_flighttime(StartTime);
		cout << "The flightname is " << request.FlightName << endl;
		requet.push_back(request);
		count++;
		//allocation_of_runway();
		//async(calling);

	}

　
　
		
				

void Airport::allocation_of_runway()

{
	static double ElapsedTime = 0;
	static double ElapseTime = 0;
	chrono::seconds min(15);
	std::chrono::time_point<std::chrono::system_clock>start, end;
	start = chrono::system_clock::now();
	end = start + min;
	if (runway1 == idle)
	{
		if (queue.landing.empty() && queue.takeoff.empty())
		{

			runway1 = request.FlightId;
			cout << "Runway1 is allocated to\n" << request.FlightId << endl;
			//async(sleep);
			request_generation();
			
			this_thread::sleep_for(chrono::seconds(5));
			runway1 = 0;

		}
		else if (!queue.landing.empty())
		{

			runway1 = 1;// queue.landing[iterate].get_flightid();
			cout << "Runway1 is allocated to queue\n";// << queue.landing[iterate].get_flightid() << endl;
			queue.push(request);
			//async(sleep);
			this_thread::sleep_for(chrono::seconds(5));
			//queue.pop();
			queue.pop();
			iterate++;
			allocation_of_runway1();
			//queue.landing.erase(queue.landing.begin());
			end = chrono::system_clock::now();
			chrono::duration <double>elapse_time = end - start;
			cout << endl << elapse_time.count();
			ttime = elapse_time.count();
			ElapsedTime = ttime + ElapsedTime;
			difference = ElapsedTime;
			cout << endl << difference;
			runway1 = 0;

		}

　
		else if (queue.landing.empty())
		{
			if (!queue.takeoff.empty())
			{
				if (request.state != "landing")
				{
					runway1 = queue.takeoff[iterator].get_flightid();
					cout << "Runway1 is allocated to queueee\n" << endl;
					queue.push(request);
					//async(call);
					allocation_of_runway1();
					this_thread::sleep_for(chrono::seconds(5));
					//queue.pop(); 
					queue.pop();
					iterate++;
					end = chrono::system_clock::now();
					chrono::duration <double>elapse_time = end - start;
					ttime = elapse_time.count();
					ElapseTime = ttime + ElapseTime;
					difference1 = ElapseTime;
					cout << endl << difference;
					runway1 = 0;
				}
				else
				{
					runway2 = request.FlightId;
					cout << "Runway2 is allocated " << endl;
                    queue.push(request);
					this_thread::sleep_for(chrono::seconds(5));
					runway2 = 0;
				}
			}

		}

			}
		

	
	else if (runway1 != 0)
	{
		cout << "The runway1 is already allocated" << endl;
		cout << "Request cannot be honored right now\n" << endl;
	//	async(call);
			allocation_of_runway1();
		

	}
}

	 void Airport::allocation_of_runway1()
	 {
	 chrono::minutes min(15);
	 static double ElapseTime=0;
	 static double ElapsedTime = 0;
	 chrono::time_point<std::chrono::system_clock>start, end, s1tim;
	 start = chrono::system_clock::now();
	 if (runway2 == idle)
	 {

		 if (queue.landing.empty() && queue.takeoff.empty())
		 {

			 end = start + min;
			 runway2 = request.FlightId;
			 cout << "Runway2 is allocated  " << request.FlightId << endl;
			 //			time_t s1tim = chrono::system_clock::to_time_t(end);
			 request_generation();
			 this_thread::sleep_for(chrono::seconds(5));
			 runway2 = 0;
		 }
		 else if (!queue.landing.empty())
		 {
			
			 runway2 = 1;// queue.landing[iterator].get_flightid();
			 cout << "Runway2 is allocated to queue";// << queue.landing[iterator].get_flightid() << endl;
			 queue.push(request);
			 this_thread::sleep_for(chrono::seconds(5));
			 runway2 = 0;
			 iterator++;
			 cout << iterator;
			// queue.landing.erase(queue.landing.begin());
			 cout << "iterator" << iterator;
			 end = chrono::system_clock::now();
			 chrono::duration <double>elapsed_time = end - start;
			 cout << endl << elapsed_time.count();
			 ttime = elapsed_time.count();
			 ElapsedTime = ttime + ElapsedTime;
			 difference = ElapsedTime;
			 cout << endl << difference;
			 runway2 = 0;
		 }

　
		 else if (queue.landing.empty())
		 {
			 if (!queue.takeoff.empty())
			 {

				 if (request.state != "landing")
				 {
					 runway2 = queue.takeoff[iterate].get_flightid();
					 cout << "Runway2 is allocated to queuee\n" << queue.takeoff[iterate].get_flightid() << endl;
					 queue.push(request);
					 this_thread::sleep_for(chrono::seconds(5));
					 //queue.pop(); 
					 queue.pop();
					 //async(call);
					 iterate++;
					 cout << iterate;
					 end = chrono::system_clock::now();
					 chrono::duration <double>elapse_time = end - start;
					 //cout << endl << elapse_time.count(); 
					 ttime = elapse_time.count();
					 ElapseTime = ttime + ElapseTime;
					 difference1 = ElapseTime;
					 cout << endl << difference;
					 runway1 = 0;
				 }
				 else
				 {
					 runway2 = request.FlightId;
					 cout << "Runway2 is allocated " << endl;
					 queue.push(request);
				 }
			 }
		 }
	 }

	else if (runway1 != 0 || runway2 != 0)
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
	}

	else if (runway2 != 0)
	{
		cout << "The runway2 is allocated" << endl;
		cout << "Request cannot be honored right now\n";
	}
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

//void calling();

//void sleep();


int main()

{

	Airport airport;

	//Airport air;

	async(call);


	std::chrono::seconds ms(90);

	std::chrono::time_point<std::chrono::system_clock>start, end;

    start = chrono::system_clock::now();

	std::time_t start_time = std::chrono::system_clock::to_time_t(start);

	cout << ctime(&start_time);

	end = std::chrono::system_clock::now() + ms; // this is the end point 

std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	//airport.get_details();

	//while (std::chrono::system_clock::now() < end) // still less than the end? 

	//{

//		airport.request_generation();

    

	//}


	//async(sleep);


	/*auto f=async(&Airport::request_generation, &airport);

    auto p=async(&Airport::allocation_of_runway,&air);

	f.get();

	p.get();

	air.allocation_of_runway();*/

   // async(calling);

	//cout << ctime(&end_time);

	//system("pause");

	cin.ignore(1000,'\n');


}

void call()

{

	cout << "hai0";

	//airport.request_generation();

	/*time_t minutes;

	tm *ltm = localtime(&minutes);

	while (minutes > minutes + 1800)

	{

	break;

	}*/


}
