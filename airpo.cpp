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
	 string first[1] = { "Air" };
	 string second[4] = { "ways", "line", "india", "jet" };
    chrono::seconds m(2);
 //	cout << request.ltm->tm_sec;
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
 	cout << endl<<ctime(&StartTime);
 	
 	request.FlightId = (rand() % 9000) + 1000;
 		cout << "The flight id is" << endl;
		 		cout << request.FlightId;
		 		request.set_flightid(request.FlightId);
				request.state = rand();
		 		cout << "\nEnter the  state of the flight  as landing or takeofff" << endl;
		 		cin.ignore();
		 		getline(cin, request.state);
		 		request.set_flightstate(request.state);
				FlightName = (first[rand() % 1] + second[rand() % 4]);
		 		cout << "\nThe flight id "  <<  request.FlightId <<  " is requesting for runnway\n";
				cout << "The request Time is " << ctime(&StartTime) << endl;
				request.set_flighttime(StartTime);
				cout << "The flight name is " << FlightName << endl;
				requet.push_back(request);

				allocation_of_runway();
		 	
	
	 }
 void Airport::allocation_of_runway()

 {
	 chrono::minutes min(15);
	 if(runway1 == busy)
	 {
		 cout << "The runway1 is allocated\n" << endl;
		 cout << "Request cannot be honored right now\n" << endl;

　
	 }
	 else if (runway1 == idle)
	 {
		 chrono::time_point<std::chrono::system_clock>start, end, stim;
		 start = chrono::system_clock::now();
		 end = start + min;
		 runway1 = request.FlightId;
		 cout << "Runway is allocated to\n" << request.FlightId << endl;
		 //		     	time_t stim = chrono::system_clock::to_time_t(end);
		 this_thread::sleep_for(chrono::seconds(15));
		 //queue.pop();
		 runway1 = 0;

	 }
	 else if (runway2 == idle)
	 	{
			chrono::time_point<std::chrono::system_clock>start, end, s1tim;
			start = chrono::system_clock::now();
			end = start + min;
			runway2 = request.FlightId;
			cout << "  Runway2 is allocated" << endl;
//			time_t s1tim = chrono::system_clock::to_time_t(end);
		    this_thread::sleep_for(chrono::seconds(15));
			runway2=0;
		
		}
	else if (runway2 == busy)
	{
		cout << "The runway2 is allocated" << endl;
		cout << "Request cannot be honored right now\n";

　
	}
	 	else if (runway1 != 0||runway2 !=0)
		 	{
		 		if (request.state == "landing")
			 		{
			 			

			 			queue.push(requet[iterator]);
                        iterator = iterator++;					
						//allocation_of_runway();
						
			
				 		}
		 		if (request.state == "takeoff")
			 		{
			 			iterate = iterate++;
			 			queue.push(requet[iterate]);
						//allocation_of_runway();
			 		}
		 	}
	
		

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

　
//}
 int main()
 {
	 Airport airport;

	 std::chrono::seconds ms(90);
	 std::chrono::time_point<std::chrono::system_clock>start, end;
	 start = chrono::system_clock::now();
	 std::time_t start_time = std::chrono::system_clock::to_time_t(start);
	 cout << ctime(&start_time);
	 end = std::chrono::system_clock::now() + ms; // this is the end point 
	 std::time_t end_time = std::chrono::system_clock::to_time_t(end);
     airport.get_details();
	 while (std::chrono::system_clock::now() < end) // still less than the end? 
	 {
		 airport.request_generation();
		 thread t1(airport);

		 
	 } cout << ctime(&end_time);
	 system("pause");

 }
			
