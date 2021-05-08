/*
Thomas Wimer
Final Project
Langley 
05/08/2021
CIS 1202.NR1
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Employee_C.h"

#include <cmath>
#include <algorithm>

using namespace std;


void Display_Salaries(Employee_C& obj);
void Fill_Array(char name[], int id, double sal, char gen);


int main()
{

	Employee_C employ;
	//Employee_C *employ [100];

	string fileName;


	cout << "\nPleae enter the binary file name . . . ";
	cin >> fileName;


	//cout << fileName; working

	double;










	cout << endl << endl;
	system("pause");
	return 0;
}

void Fill_Array(char name[], int id, double sal, char gen)
{
	const int SIZE_A = 100;
	
	//Employee_C* employ; //DMA
	//employ = new employ[SIZE_A]
	//char* emp_p = nullptr;
	//emp_p = new emp_p[100];
	//char emp_p = new char[SIZE_A];



	Employee_C employ[SIZE_A]; //static memory REMEBER TO CHANGE THIS BACK TO DMA ONCE <========================== LOOK
	
	for (int i = 0; i < 100; i++)
	{

		cout << "\Please enter the employee's full name . . .";
		cin.get(name, SIZE);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		employ[i]->Get_Name(name);

		cout << "\Please enter the employee's I.D. . . .";
		cin >> id;

		employ[i].Get_ID(id);

	}




	//delete employ[100];
}

void Display_Salaries(Employee_C& obj)
{

	obj.Display_Salaries();

}