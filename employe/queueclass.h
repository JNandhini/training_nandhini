#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include "employee.h"

//queueclass contains the details of bench queue and project queue

class queueclass
{
public:
	
	int size = 0;
	int iterat = 0;
	vector<int> EmployId;
	vector<string> EmployName;
	vector<string> EmployDepartment;
	vector<int> BenchQueue;
	vector<int> ProjectQueue;
	int EmployeeId=0;
	int Id=0;
	int EmployeeToBench=0;
	int EmployeeToProject=0;
public:
	void copying_details(vector<int> EmpId, vector<string> EmpName, vector<string> EmpDepartment);
	void push_details();
	void pop_details();
	void add_employee();
	void remove_employee();
	void after_queue();

};
