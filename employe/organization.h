#pragma once
#include<vector>
#include "employee.h"
#include "queueclass.h"

//peforming employee function as highestpay and  

class organization
{
public:
   	employee employ; 
	queueclass cqueue;
	int iterat=0;
	int value = 0;
	int Year=0;
    public:
	void employe_details();
    void name_by_year();
	void highest_pay();
	void display_by_ascending_order();
	void update_pay();
	void push_details();
	
};
