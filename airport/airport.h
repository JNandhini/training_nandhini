#pragma once

#include<iostream>

#include<vector>

#include<string>

#include<thread>

#include<ctime>

#include<future>

#include"Request.h"

#include"queueclas.h"

class airport

{


　

public:

	Request request;

	queueclas queue;

public:

	int iterator = 0;

	int iterate = 0;

	int count = 0;

	double difference1 = 0;

	double ttime = 0;

	double difference = 0;

	int runway1 = 0;

	int runway2 = 0;

	bool busy = true;

	bool idle = false;

	int FlightTime = 0;

	//int StartTime = 0;

	string first[1];

	string second[4];

	int state1 = 0;

	string AirportName;

	void get_details();

	int allocation_of_runway();

	void request_generation();


};

