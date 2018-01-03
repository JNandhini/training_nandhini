#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"Airport.h"
using namespace std;
class Queueclas
{
public:
	vector<Request> landing;
	vector<Request> takeoff;
public:
	void push(Request reque);
	void pop();
	Queueclas();
	~Queueclas();
};
