#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<chrono>
#include<ctime>
using namespace std;

　
//contains the details of request to the airport

class Request
{
public:

	int FlightId = 0;
	string FlightName;
	int FlightTime = 0;
	string state;
public:
	void set_flightid(int FlightId);
	int get_flightid();
	void set_flightname(string FlightName);
	string get_flightname();
	void set_flightstate(string state);
	string get_flightstate();
	void set_flighttime(int FlightTime);
	int get_flighttime();
	void request_generation();

};

　
　
