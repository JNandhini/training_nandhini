#pragma warning(disable:4996)#include "Airport.h" 

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
chrono::seconds minutes((rand()%9)+10); 
string first[1] = { "Air" }; 
string second[4] = { "ways", "line", "india", "jet" };        
        FlightTime=(rand()%9)+10;
        
        //request start time 
        
        start = std::chrono::system_clock::now();
        time_t StartTime = std::chrono::system_clock::to_time_t(start);
        cout << endl <<"The Start time is"<< ctime(&StartTime); 
        request.FlightId = (rand() % 9000) + 1000;
        request.FlightTime=StartTime;
        cout << "The flight id is" << endl;
        cout << request.FlightId; request.set_flightid(request.FlightId); 
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
        cout << endl << request.state; request.set_flightstate(request.state);
        request.FlightName = first[rand() % 1] + second[rand() % 4];
        request.set_flightname(request.FlightName); 
        cout << "\nThe flight id " << request.FlightId << " is requesting for runnway\n";
        cout << "The request Time is " << ctime(&StartTime); 
        request.set_flighttime(request.FlightTime);
        cout << "Time" << endl << StartTime; 
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
 
 std::chrono::time_point<std::chrono::system_clock>start,starttime,startdur, end;
 start = chrono::system_clock::now();
 static int CheckTime=0;
 static int duration=0;
 
 
 //checking the landing queue for empty
 
if (!queue.landing.empty())
 {  
         if (runway1 == idle)  
         {
         runway1 = 1;// queue.landing[iterate].get_flightid(); 
         cout << "Runway1 is allocated to landing queue\n";// << queue.landing[iterate].get_flightid() << endl;
         iterate++;
         //queue.pop();
         queue.pop();  
         time_t rawtime;      
         time(&rawtime);
         CheckTime=rawtime;
         start = chrono::system_clock::now();    
         std::time_t start_time = std::chrono::system_clock::to_time_t(start);
         end = chrono::system_clock::now()+min; 
         chrono::duration <double>elapse_time = rawtime - request.FlightTime; 
         cout << endl <<"The elapsed time is "<<elapse_time.count();  
        }  
        else if (runway2 == idle) 
        {  
        runway2 = 1;// queue.landing[iterator].get_flightid();  
        cout << "Runway2 is allocated to landing queue";// << queue.landing[iterator].get_flightid() << endl; 
        starttime = chrono::system_clock::now();
        iterate++; 
        cout << iterator;  
        queue.pop();
        time_t rawtime;
        time(&rawtime);
        duration=rawtime;
        cout << "iterator" << iterator;  
        end = chrono::system_clock::now(); 
        std::time_t Starttime = std::chrono::system_clock::to_time_t(starttime);   
        chrono::duration <double>elapsed_time = rawtime- request.FlightTime;
        cout << endl <<"The elapsed time for the request is "<< elapsed_time.count(); 
        }
     }
     
     //checking for takeoff queue 
     
　　 else if (!queue.takeoff.empty()) 
   {
   if (runway1 == idle)
   {
   runway1 = 1;// queue.takeoff[iterator].get_flightid(); 
   cout << "Runway1 is allocated to takeoff queue\n";// << queue.takeoff[iterator].get_flightid() << endl;   
   start = chrono::system_clock::now(); 
   iterator++;  
   //queue.pop();    
   queue.pop();
   time_t rawtime;
   time(&rawtime);
   ChechkTime=rawtime;
   std::time_t start_time = std::chrono::system_clock::to_time_t(start); 
   end = chrono::system_clock::now();
   chrono::duration <double>elapse_time = rawtime - request.FlightTime;  
   cout << endl <<"The elapsed time is"<< elapse_time.count(); 
   }
   }
　　   else if (runway2 == idle)  
     {
     runway2 = 1;// queue.takeoff[iterate].get_flightid();
     cout << "Runway2 is allocated to takeoff queue\n";// << queue.takeoff[iterate].get_flightid() << endl;   
     starttime = chrono::system_clock::now();
     queue.pop();
     std::time_t Start_time = std::chrono::system_clock::to_time_t(starttime);
     iterator++;   
     cout << iterator; 
     time_t rawtime;            
     time(&rawtime); 
     duration=rawtime;
     end = chrono::system_clock::now(); 
     chrono::duration <double>elapse_time = rawtime-request.FlightTime;   
     cout << endl <<"The elapsed time is "<< elapse_time.count(); 
     }
     }
     time_t rawtime;             
     time(&rawtime); 
     if(rawtime==CheckTime) 
     {
     CheckTime=0;
     cout << "hai" << endl;
     runway1 = 0;
     return 0;
     }
     else if (rawtime==duration) 
     {
     duration=0;
     runway2 = 0;  
     return 0;
     }
     if (rawtime==CheckTime)
     {
     CheckTime=0;
     runway1 = 0;
     return 0;
     }
     else if (rawtime==duration) 
     {
     duration=0;
     runway2 = 0;
     return 0; 
     }
　}
