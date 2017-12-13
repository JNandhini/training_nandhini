#include "queueclass.h"
#include<vector>

//copies the employee class details into queueclass vector

void queueclass:: copying_details(vector<int> EmpId,vector<string> EmpName,vector<string> EmpDepartment)
{
EmployId.swap(EmpId);
EmployName.swap(EmpName);
EmployDepartment.swap(EmpDepartment);
}

//compares the id and adds into queueclass vector

void queueclass::push_details()
{
		int value = 0;
		cout << "Enter the employee in bench\n";
		cin >> EmployeeId;
		if (!cin.fail() && EmployeeId > 100)
		{
			for (iterat = 0; iterat < EmployId.size(); iterat++)
			{
				if (EmployId.at(iterat) == EmployeeId)
				{

					BenchQueue.push_back(EmployeeId);
					value++;
			   }
			}
			if (value == 0)
			{
				cout << "No records found\n";
			}
		}
		else
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "invalid Id ";
		}
		cout << "Enter the employee in project\n";
		cin >> Id;
		if (!cin.fail() && Id>100)
		{
			for (iterat = 0; iterat < EmployId.size(); iterat++)
			{
				if (EmployId.at(iterat) == Id)
				{
					
					ProjectQueue.push_back(Id);
					value++;
				}
			}
			if (value == 0)
			{
				cout << "no records found\n";

			}
		}
		else
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "invalid Id ";
		}
	}

//display the details of employee in queue

void queueclass::pop_details()
{

	if (BenchQueue.begin() == BenchQueue.end())
	{
		cout << "queue is empty\n";
	}
	else
	{
		cout << endl;
		cout << "\nThe bench List is\n";
		for (iterat = 0; iterat < BenchQueue.size(); iterat++)
		{
			
			//poping the elements at that index

			cout << BenchQueue.at(iterat) << endl;

		}
		cout << "\nThe project queue is\n";
		for (iterat = 0; iterat < ProjectQueue.size(); iterat++)
		{

			cout << ProjectQueue.at(iterat) << endl;;

		}
	}
}

//removes the employee from bench and project

void queueclass::remove_employee()
{
	if (BenchQueue.begin() == BenchQueue.end())
	{
		cout << "queue is empty\n";
	}
	else
	{

		//returns the element in front of the vector

		EmployeeToBench = ProjectQueue.front();
		cout << "\nthe employee removed from project is\n " << EmployeeToBench;
		cout << endl;
		EmployeeToProject = BenchQueue.front();
		cout << "\nThe employee removed from bench is\n" << EmployeeToProject;

		//removes the element 

		BenchQueue.erase(BenchQueue.begin());
		ProjectQueue.erase(ProjectQueue.begin());
	}
}

 //adding the removed elements 

void queueclass::add_employee()
{
	if (BenchQueue.begin() == BenchQueue.end())
	{
		cout << "queue is empty\n";
	}
	else
	{
		BenchQueue.push_back(EmployeeToBench);
		ProjectQueue.push_back(EmployeeToProject);
	}
}

//display the elements after queue

void queueclass::after_queue()
{
	cout << endl;
	for (iterat = 0; iterat < BenchQueue.size(); iterat++)
	{
		cout << "\nThe bench queue is\n";
		cout << BenchQueue.at(iterat);

	}
	for (iterat = 0; iterat < ProjectQueue.size(); iterat++)
	{
		cout << "\nThe project queue is\n";
		cout <<ProjectQueue.at(iterat);

	}
}
