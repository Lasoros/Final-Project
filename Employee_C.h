#ifndef Employee_C_H
#define Employee_C_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <iomanip>


using namespace std;

const int SIZE = 50;

class Employee_C
{
	
protected:

	

	//char fullName[SIZE];
	//int ID;
	//double salary;
	//char gender;

	//static double totalSal;



public:

	char fullName[SIZE];
	int ID;
	double salary;
	char gender;

	static double totalSal;

	Employee_C();
	//Employee_C(char name . int ID, double sal, char gen);
	Employee_C(char[], int, double, char);

	char Get_Name() const;
	int Get_ID() const;
	double Get_Salary() const;
	char Get_Gender() const;

	void Set_Name(char[]);
	void Set_ID(int);
	void Set_Salary(double);
	void Set_Gender(char);

	
	virtual void Display_Salaries() const;
	virtual void Display_Info()const;





};
#endif