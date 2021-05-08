#include "Employee_C.h"

Employee_C::Employee_C()
{

	fullName[SIZE] = ' ';

	ID = 0;

	salary = 0;

	gender = ' ';
	
	totalSal = 0;
}

Employee_C::Employee_C(char[], int, double, char)
{

	fullName[SIZE];
	ID = ID;
	salary;
	gender;

}



char Employee_C::Get_Name() const
{
	return fullName[50];
}

int Employee_C::Get_ID() const
{
	return ID;
}

double Employee_C::Get_Salary() const
{
	return salary;
}

char Employee_C::Get_Gender() const
{
	return gender;
}

void Employee_C::Set_Name(char name[])
{
	fullName[50] = name[50];
}

void Employee_C::Set_ID(int id)
{
	ID = ID;
}

void Employee_C::Set_Salary(double sal)
{
	salary = sal;
	totalSal += sal;
}

void Employee_C::Set_Gender(char gen)
{
	gender = gen;
}

void Employee_C::Display_Salaries() const
{
	cout << "\nThe total for all employee salaries is " << totalSal;
}