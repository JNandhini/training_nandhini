#include "employee.h"
#include<regex>

//validate the user name for characters greater than 3

#include<ctime>
using namespace std;
void employee::set_id(int Id)
{
	
	this->Id;
}
int employee::get_id()
{
	return this->Id;
}
void employee::set_name(string name)
{
	this->name;
}
string employee::get_name()
{
	return this->name;
}
void employee::set_year(int year)
{
	this->year;
}
int employee::get_year()
{
	return this->year;
}
void employee::set_Department(string Department)
{
	this->Department;
}
string employee::get_department()
{
	return this->Department;
}
void employee::set_pay(int pay)
{
	this->pay;
}
int employee::get_year()
{
	return this->pay;
}
void employee::validate_name()
{
	 if (!(cin.fail()) && (name.size() > 3))
	{
		EmpName.push_back(name);
	}
	else  
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Enter the name with atleast 3 characters";
		cin >> name;
		validate_name();
	}

}

//validate year and then add the year in vector

void employee::validate_year()
{
	if (cin.fail())

	{
		cin.clear();
		cin.ignore(10000, '\n');
		
	}
	if ((year > 0 && year >= 1900 && year <= 2017))
	{
	     employ.set_year(year);	
	}
    else
	{
		cin.clear();
		cout << "wrong input  ";
		cout << endl;
		cout << "Enter the year correctly\n";
		cin >> year;
		validate_year();
	}
}

　
//validate pay greater than 100	
	

void employee::validate_pay()
{
	if (cin.fail())

	{
		cin.clear();
		cin.ignore(10000, '\n');
	}
	if (pay > 100 )
	{
		set_pay(pay);       
	}
	else
	{
		cin.clear();
		cout << "wrong input  ";
		cout << endl;
		cout << "Enter the pay correctly\n";
		cin >> pay;
		validate_pay();
	}

}

//validate tha department for more than 4 characters

void employee::validate_department()
{

　
	if (!(cin.fail()) && (department.size() > 3))
	{
		
	}

	else
	{

		cin.clear();
		cout << "input a string with length greater than 3\n";
		cout << "enter the department\n";
		cin >> department;
		validate_department();
	}
	}
