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
	
	int FlightId = 0;
	string state;
	int FlightTime=0;
	string FlightName;
	public:
	void set_flightid(int FlightId);
	int get_flightid();
	void set_flightstate(string state);
	string get_flightstate();
	void set_flighttime(int time);
	int get_flighttime();
	void set_flightname(string FlightName);
	string get_flightname(); 
	Request();
	~Request();
};

　
　
