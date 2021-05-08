/*
Thomas Wimer
Final Project
Langley 
05/08/2021
CIS 1202.NR1
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Employee_C.h"
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;


void Display_Salaries(Employee_C& obj);
void Display_Info(Employee_C& obj);
void Fill_Array(char name[], int id, double sal, char gen);
void Extract_ID(fstream& txt, fstream& bin);
int Find_Employee(fstream& txt, fstream& bin, int* notFound_p);


int main()
{

	Employee_C employ;
	//Employee_C *employ [100];

	string fileName;


	

	cout << "\nPleae enter the binary file name . . . ";
	getline(cin, fileName);

	fstream bin(fileName, ios::out | ios::binary);


	//cout << fileName; working

	//for(int i = 0; i < )

	Fill_Array(employ.fullName, employ.ID , employ.salary , employ.gender);




	cout << "\nEmployee Name . . . " << employ.Get_Name();
	cout << "\nEmployee I.D. . . . " << employ.Get_ID();
	cout << "\nEmployee Salary . . . " << employ.Get_Salary();
	cout << "\nEmployee Gender . . . " << employ.Get_Gender();
	
	Display_Info(employ);






	bin.close();


	cout << endl << endl;
	system("pause");
	return 0;
}

void Fill_Array(char name[], int id, double sal, char gen)
{
	const int SIZE_A = 100;

	int quit = 0;

	int numEmp = 0;


	
	//Employee_C* employ; //DMA
	//employ = new char[SIZE_A];
	//char* emp_p = nullptr;
	//emp_p = new emp_p[100];
	//char emp_p = new char[SIZE_A];



	Employee_C employ[SIZE_A]; //static memory REMEBER TO CHANGE THIS BACK TO DMA ONCE <========================== LOOK
	
	//for (int i = 0; i < SIZE_A; i++)
	while (quit && numEmp < SIZE_A)
	{

		cout << "\Please enter the employee's full name . . .";
		cin.get(name, SIZE);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		employ[numEmp].Set_Name(name);

		cout << "\Please enter the employee's I.D. . . .";
		cin >> id;

		employ[numEmp].Set_ID(id);

		cout << "\Please enter the employee's Salary . . .";
		cin >> sal;

		employ[numEmp].Set_Salary(sal);

		cout << "\Please enter the employee's Gender . . .";
		cin >> gen;

		employ[numEmp].Set_Gender(gen);

		cout << "\Please enter 1 to continue else enter 0 to quit. . .";
		cin >> quit;
		if (quit == 0)
		{
			numEmp = SIZE_A;
		}
		else
		{
			numEmp++;
		}
		cin.ignore();
	
	}




	//delete employ[100];
}

void Extract_ID(fstream& txt, fstream& bin)
{
	
	Employee_C employ;

	while (employ.ID != 0)
	{
		txt << employ.fullName << " ";

		
		cin.get(employ.fullName, SIZE);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		txt << employ.fullName << endl;

		cin >> employ.ID;
		txt << employ.ID << "\n";

		cin >> employ.salary;
		txt << employ.salary << "\n";

		cin >> employ.gender;
		txt << employ.gender << "\n";

		bin.write(reinterpret_cast<char*> (&employ), sizeof(employ));

	}

	txt.close();
}

int Find_Employee(fstream& txt, fstream& bin, int* notFound_p)//make INT to return value
{

	Employee_C employ;

	int searchEmp;

	


	cout << "\nPlease enter the employee I.D. to be searched for . . .";
	cin >> searchEmp;

	fstream search;

	while (search.read((char*)&employ, sizeof(employ)))
	{
		if (employ.ID == searchEmp)
		{
			employ.Display_Info();
		}
		else
		{

			int unableToFind = -1;
			int* notFound_p = &unableToFind;

			//return -1;
			return *notFound_p; //was getting error C2082 "Redefinition of formal paratmer "notFound_p"
		}
	}


	/*bin.read(reinterpret_cast<char*> (&employ), sizeof(Employee_C));
	while (bin)
	{

		if(searchEmp)

	}*/

}

void Display_Salaries(Employee_C& obj)
{
	cout << setprecision(2) << fixed;

	obj.Display_Salaries();

}

void Display_Info(Employee_C& obj)
{
	obj.Display_Info();
}