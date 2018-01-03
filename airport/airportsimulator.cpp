 #pragma warning(disable:4996) 
 #include"Airport.h" 
 #include<future>
 Airport airport;　
 void call();
 void calling();
 int main()
 {
 Airport airport; 
 airport.get_details();
 async(call);
 async(calling);
 airport.queue.display();
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
 airport.request_generation();
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
 airport.allocation_of_runway();
 }
 } 
