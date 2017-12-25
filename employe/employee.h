#pragma once
#include<iostream>
#include <vector>
#include<string>
#include<regex>
using namespace std;

//employee class stores the details of employee

class employee 
{
public:
	int id = 101;
	string value = "EMP";
	string name;
	int year=0;
	float pay=0.0;
	string department;
	
 public:
	 void validate_name();
	 void validate_year();
	 void validate_pay();
	 void validate_department();
	 
};
