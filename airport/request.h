#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<chrono>
#include<ctime>
using namespace std;

class Request
{
public:
	Airport airport;
	time_t now;
	time_t StartTime;
	tm *ltm = localtime(&now);
	int FlightId = 0;
	int hour = 0;
	int minutes = 0;
	int time=0;
	string state;
	string FlightName;
	int seconds = 0;
	int count = 0;
public:
	void set_flightid(int FlightId);
	int get_flightid();
	void set_flightstate(string state);
	string get_flightstate();
	void set_flighttime(int time);
	int get_flighttime();
	void set_flightname(string FlightName);
	string get_flightname(); 
	void request_generation();
	Request();
	~Request();
};

　
　
