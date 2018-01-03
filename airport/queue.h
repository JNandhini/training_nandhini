#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"airport.h"
using namespace std;
class queueclas
{
public:
	int iterate=0;
	vector<Request> landing;
	vector<Request> takeoff;
public:
	void push(Request reque);
	void pop();
	void display();
	Queueclas();
	~Queueclas();
};
