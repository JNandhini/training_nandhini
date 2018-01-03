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

	//concurrent execution of function

	async(call);
	async(calling);
	Airport.queue.display();
	cin.ignore(1000, '\n');
}

//executes the function for certain duration

void call()
{
	std::chrono::minutes minute(120);
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
	cout << "\nThe Total request is "<< Airport.count;
	cout << "\nThe request completed in landing queue is " << Airport.total;
	cout << "\nThe request completed in takeoff queue is " << Airport.total1;
	Airport.queue.display();

}

//executes the function for certain duration

void calling()
{
	std::chrono::minutes minute(120);
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
