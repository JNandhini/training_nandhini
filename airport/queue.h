#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Request.h"
using namespace std;

//stores the request in queue

class queueclas
{
public:
	vector<Request> landing;
	vector<Request> takeoff;
	int iterate = 0;
	int iterator = 0;
public:
	void push(Request reque);
	void pop();
	void display();
	
};
