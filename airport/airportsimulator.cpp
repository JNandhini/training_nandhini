 #pragma warning(disable:4996) 
 #include"airport.h" 
 #include<future>
 airport Airport;　
 void call();
 void calling();
 int main()
 {
 airport Airport; 
 Airport.get_details();
 async(call);
 async(calling);
 Airport.queue.display();
 system("pause");
 cin.ignore(1000,'\n');
 }
 void call()
 {
 std::chrono::seconds minute(90);
 std::chrono::time_point<std::chrono::system_clock>start, end;
 start = chrono::system_clock::now(); 
 std::time_t start_time = std::chrono::system_clock::to_time_t(start);
 cout << ctime(&start_time);
 end = std::chrono::system_clock::now() + minute; 
 std::time_t end_time = std::chrono::system_clock::to_time_t(end); 
 while (std::chrono::system_clock::now() < end)
 {
 Airport.request_generation();
 }
 }
 void calling()
 {
 std::chrono::seconds minute(9);
 std::chrono::time_point<std::chrono::system_clock>start, end;
 start = chrono::system_clock::now(); 
 std::time_t start_time = std::chrono::system_clock::to_time_t(start);
 cout << ctime(&start_time);
 end = std::chrono::system_clock::now() + minute; 
 std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 while (std::chrono::system_clock::now() < end)
 {
 Airport.allocation_of_runway();
 }
 } 
