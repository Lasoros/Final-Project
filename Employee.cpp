#include "Employee_C.h"

double totalSal = 0;

Employee_C::Employee_C()
{

	fullName[50-1] = ' ';

	ID = 0;

	salary = 0;

	gender = ' ';
	
	//totalSal = 0;
}

Employee_C::Employee_C(char name[], int id, double sal, char gen)
{

	fullName[50-1] = name[50-1];
	ID = id;
	salary = sal;
	gender = gen;
	//totalSal;
}



char Employee_C::Get_Name() const
{
	return fullName[50-1];
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

//double Employee_C::Set_TotalSal() const
//{
//	return totalSal; //trying to work around LNK2001
//}

void Employee_C::Set_Name(char name[])
{
	fullName[50-1] = name[50-1];
}

void Employee_C::Set_ID(int id)
{
	ID = id;
}

void Employee_C::Set_Salary(double sal)
{
	salary = sal;
	//totalSal = +sal; //uncommnet this for LNK2001
}

void Employee_C::Set_Gender(char gen)
{
	gender = gen;
}

//double Employee_C::Get_Salary()
//{
//
//	cout << "\nthe total for all employee salaries is " << totalSal;
//	return totalSal;
//
//}

//void Employee_C::Set_TotalSal(double totalSal, double sal)
//{
//	salary = sal;
//	totalSal =+ sal; //trying to work around LNK2001
//}

//double Employee_C::Display_Salaries(Employee_C& double sal)
//{
//	double sal;
//
//
//	cout << "\nThe total for all employee salaries is " << totalSal;
//}

void Employee_C::Display_Info() const
{
	cout << "\nEmployee Name . . . " << fullName;
	cout << "\nEmployee I.D. . . . " << ID;
	cout << "\nEmployee Salary . . . " << salary;
	cout << "\nEmployee Gender . . . " << gender;
}