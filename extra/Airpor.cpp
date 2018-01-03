#pragma warning(disable:4996)
#include "Airport.h" 

　
void Airport::get_details()
{
	cout << "Enter the Airport Name" << endl;
	cout << "The Airport Name is" << endl;
	cin.ignore();
	getline(cin, AirportName);
	cout << endl;
	cout << "Enter the FlightName" << endl;
	cin.ignore();
	getline(cin, FlightName);
	cout << endl;
}
void Airport::request_generation()
{
	srand(time(0));
	chrono::seconds m(2);
	string first[1] = { "Air" };
	string second[4] = { "ways", "line", "india", "jet" };
		cout << request.ltm->tm_sec;
	//request.hour = request.ltm->tm_hour;
	//seconds = ltm->tm_sec; 
	//request.seconds = request.now + 500;

	//tim = seconds+tim; 
	this_thread::sleep_for(chrono::seconds(m));
	//this_thread::sleep_for(chrono::seconds(request.seconds));
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	time_t StartTime = std::chrono::system_clock::to_time_t(start);
	end = chrono::system_clock::now() + m;

	time_t end_time = chrono::system_clock::to_time_t(end);
//	cout << endl << ctime(&StartTime);

	request.FlightId = (rand() % 9000) + 1000;
	cout << "The flight id is" << endl;
	cout << request.FlightId;
	request.set_flightid(request.FlightId);
	state1 = rand()%2;
	if (state1 == 0)
	{
		request.state = "takeoff";
	}
	else
	{
		request.state = "landing";
	}
	cout << "\nThe state of the flight is";
	cout << endl<< request.state;
	request.set_flightstate(request.state);
	request.FlightName = first[rand() % 1] + second[rand() % 4];
	request.set_flightname(request.FlightName);
	cout << "\nThe flight id " << request.FlightId << " is requesting for runnway\n";
	cout << "The request Time is " << ctime(&StartTime);
	request.set_flighttime(StartTime);
	cout << "\The flightname is " << request.FlightName << endl;

	requet.push_back(request);
	count++;
	allocation_of_runway();
}
void Airport::allocation_of_runway()

{
	static double ElapsedTime=0;
	static double ElaspseTime=0;
	chrono::seconds min(15);
	 chrono::time_point<std::chrono::system_clock>start, end;
			start = chrono::system_clock::now();
	if (runway1 == idle)
	{
		if (queue.landing.empty()&&queue.takeoff.empty())
		{
		
			runway1 = request.FlightId;
			cout << "Runway1 is allocated to\n" << request.FlightId << endl;
			runway1 = 0;
			async(call);
		}
		else if(!queue.landing.empty())
		{
			
			runway1 = queue.landing[iterate].get_flightid();
			cout << "Runway1 is allocated to queue\n" << queue.landing[iterate].get_flightid() << endl;
			queue.push(request);		
			this_thread::sleep_for(chrono::seconds(15));
			//queue.pop();
			queue.pop();
			iterate++;
			async(call);
			end = chrono::system_clock::now();
			chrono::duration <double>elapse_time = end - start;
			//cout << endl << elapse_time.count();
			ttime = elapse_time.count();
			ElapsedTime = ttime + ElapsedTime;
			difference = ElapsedTime;
			cout << endl << difference;
			runway1 = 0 ;
			
		}
		else if(queue.landing.empty())
		{
			if(!takeoff.landing.empty())
			{
		        runway1 = queue.takeoff[iterator].get_flightid();
			cout << "Runway1 is allocated to queue\n" << queue.takeoff[iterate].get_flightid() << endl;
			queue.push(request);		
			this_thread::sleep_for(chrono::seconds(15));
			//queue.pop();
			queue.pop();
			iterate++;
			async(call);
			end = chrono::system_clock::now();
			chrono::duration <double>elapse_time = end - start;
			//cout << endl << elapse_time.count();
			ttime = elapse_time.count();
			ElapseTime = ttime + ElapseTime;
			difference1 = ElapseTime;
			cout << endl << difference;
			runway1 = 0 ;

	}
	
	
	else if(runway1 !=0)
	{
		cout << "The runway1 is allocated" << endl;
		cout << "Request cannot be honored right now\n" << endl;
	        async(allocation_of_runway1);

	}
		}
　
	 void Airport::allocation_of_runway1()
	 {
		 chrono::minutes min(15);
		 static double ElapseTime=0;
		 chrono::time_point<std::chrono::system_clock>start, end, s1tim;
		 start = chrono::system_clock::now();
	         end = start + min;
		 if (runway2 == idle)
		 {

			 if (queue.landing.empty())
			 {
				 
				 runway2 = request.FlightId;
				 cout << "Runway2 is allocated  " <<   request.FlightId<< endl;
				 //			time_t s1tim = chrono::system_clock::to_time_t(end);
				 //this_thread::sleep_for(chrono::seconds(15));
				 runway2 = 0;
				 async(cal);
			 }
			 else
			 {

				 runway2 = queue.landing[iterator].get_flightid();
				 cout << "Runway2 is allocated" << queue.landing[iterator].get_flightid() << endl;
				 queue.push(requet[count]);
				 this_thread::sleep_for(chrono::seconds(15));
				 runway2 = 0;
				 iterator++;
				 queue.landing.erase(queue.landing.begin());
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

		 }
		  else if(queue.landing.empty())
		{
			if(!takeoff.landing.empty())
			{
		        runway1 = queue.takeoff[iterator].get_flightid();
			cout << "Runway1 is allocated to queue\n" << queue.takeoff[iterate].get_flightid() << endl;	
			this_thread::sleep_for(chrono::seconds(15));
			//queue.pop();
			queue.pop();
			async(call);
			end = chrono::system_clock::now();
			chrono::duration <double>elapse_time = end - start;
			//cout << endl << elapse_time.count();
			ttime = elapse_time.count();
			ElapseTime = ttime + ElapseTime;
			difference1 = ElapseTime;
			cout << endl << difference;
			runway1 = 0 ;

	}
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
		 }

		else if (runway2!=0)
		{
			cout << "The runway2 is allocated" << endl;
			cout << "Request cannot be honored right now\n";

　
		}
		  }
		 void Airport::calculate_elapsedtime()
		 {   
			 difference=dfference/iterator;
			 difference1=difference1/iterate;
			 
		 }
		 /*void Airport::checking_for_runway_availablity()
{
if (queue.landing[0] !=0 )
{ allocation_of_runway();
for (int count = 0; count<queue.landing.size(); count++)
{    cout << "\nThe number of flights in landing queue is\n";
cout << queue.landing.at(count);
}
}
if (queue.takeoff != isempty())
{
allocation_of_runway();
for (int count = 0; count<queue.takeoff.size(); count++)
{
cout << "The number of flights in takeoff queue is\n";
cout << queue.takeoff.at(count);
}
}
*/
Airport airport;
void calling();
void check_for_runway();
void calling()
{
	airport.allocation_of_runway();
}
void check_for_runway()
{
	this_thread::sleep_for(chrono::seconds(9));
	time_t minutes;
	tm *ltm = localtime(&minutes);
	while (minutes > minutes + 1800)
	{
		break;
	}
	
}
int main()
{
	
	
	std::chrono::seconds ms(90);
	std::chrono::time_point<std::chrono::system_clock>start, end;
	start = chrono::system_clock::now();
	std::time_t start_time = std::chrono::system_clock::to_time_t(start);
	cout << ctime(&start_time);
	end = std::chrono::system_clock::now() + ms; // this is the end point 
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	//airport.get_details();
   while(std::chrono::system_clock::now() < end) // still less than the end? 
	{
		airport.request_generation();
		
	}  
	

	async(calling);
	//thread t2(calling);

	//t2.join();
	
		cout << ctime(&end_time);
	system("pause");

}

　
　
 
