#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Request.h"
#include"Queueclas.h"
class Airport
{
public:
	Request request; 
	Queueclas queue;
	int iterator = 0;
	int iterate = 0;
	bool runway1 = 0;
	int runway2 = 0;
	bool busy=true;
	bool idle = false;
	string AirportName;
	vector<Request> landing;
	vector<Request> takeoff;
	
public:
	void get_details();
	void allocation_of_runway();
	void request_generation();
         Airport();
	~Airport();
};
