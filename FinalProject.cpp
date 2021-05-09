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

	int unableToFind = -1;
	int* notFound_p = &unableToFind;


	

	cout << "\nPleae enter the binary file name . . . ";
	getline(cin, fileName);

	fstream bin(fileName, ios::out | ios::binary);

	fstream txt;
	txt.open(fileName, ios::out);

	//cout << fileName; working

	//for(int i = 0; i < )

	Fill_Array(employ.fullName, employ.ID , employ.salary , employ.gender);

	cout << "\nGot to here"; // used for debugging, issue still happening in Extract_ID

	bin.open(fileName, ios::in | ios::binary);
	if (txt.fail())
	{
		cout << "\nBinary file not found. . . program will end";
		system("pause");
		return 0;
	}

	Extract_ID(txt,bin);
	bin.close();

	Find_Employee(txt, bin, notFound_p);

	//cout << "\nEmployee Name . . . " << employ.Get_Name();
	//cout << "\nEmployee I.D. . . . " << employ.Get_ID();
	//cout << "\nEmployee Salary . . . " << employ.Get_Salary();
	//cout << "\nEmployee Gender . . . " << employ.Get_Gender();
	
	//Display_Salaries(employ);
	Display_Info(employ);






	


	cout << endl << endl;
	system("pause");
	return 0;
}

void Fill_Array(char name[], int id, double sal, char gen)
{
	const int SIZE_A = 100;

	int quit = 0;

	int numEmp = 0;

	
	Employee_C* employ_p;
	employ_p = new Employee_C[SIZE_A];

	//Employee_C employ[SIZE_A]; //static memory REMEBER TO CHANGE THIS BACK TO DMA ONCE <========================== LOOK
	
	//for (int i = 0; i < SIZE_A; i++)
	//while (quit && numEmp < SIZE_A)
	do
	{

		int counter = 1;

		//for (int i = 0; i < 1; i++)
		//{

		//	cout << "\Please enter the employee's full name . . . ";
		//	cin.get(name, SIZE);
		//	cin.clear();
		//	cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//	employ[i].Set_Name(name);

		//	cout << "\nName of emlpoyee is " << employ[i].Get_Name() << endl;

		//	cout << "\Please enter the employee's I.D. . . . ";
		//	cin >> id;

		//	employ[i].Set_ID(id);

		//	cout << employ[i].Get_ID() << endl;

		//	cout << "\Please enter the employee's Salary . . . ";
		//	cin >> sal;

		//	employ[i].Set_Salary(sal);

		//	cout << employ[i].Get_Salary() << endl;

		//	cout << "\Please enter the employee's Gender . . . ";
		//	cin >> gen;

		//	employ[i].Set_Gender(gen);

		//	cout << employ[i].Get_Gender() << endl;

		//	cout << "\Please enter 1 to continue else enter 0 to quit. . . ";
		//	cin >> quit;
		//	if (quit == 0)
		//	{
		//		numEmp = SIZE_A;
		//		//break;
		//	}
		//	else
		//	{
		//		counter++;
		//	}
		//	cin.ignore();

		//}
	

		cout << "\Please enter the employee's full name . . . ";
		cin.get(name, SIZE);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		employ_p[numEmp].Set_Name(name);
		//cout << employ[numEmp].Get_Name();

		cout << "\Please enter the employee's I.D. . . . ";
		cin >> id;

		employ_p[numEmp].Set_ID(id);
		//cout << employ[numEmp].Get_ID();

		cout << "\Please enter the employee's Salary . . . ";
		cin >> sal;

		employ_p[numEmp].Set_Salary(sal);
		//cout << employ[numEmp].Get_Salary();

		cout << "\Please enter the employee's Gender . . . ";
		cin >> gen;

		employ_p[numEmp].Set_Gender(gen);
		//cout << employ[numEmp].Get_Gender();

		cout << "\Please enter 1 to continue else enter 0 to quit. . . ";
		cin >> quit;
		if (quit == 0)
		{
			numEmp = SIZE_A;
			//break;
		}
		else
		{
			counter++;
		}
		cin.ignore();
	
	} while (quit && numEmp < SIZE_A);




	delete [] employ_p;
}

void Extract_ID(fstream& txt, fstream& bin)
{
	
	cout << "\nworking";

	Employee_C employ_p;

	int counter = 0;

	//bin << employ.Get_Name() << endl;
	//bin << employ.Get_ID() << endl;
	//bin << employ.Get_Salary()<< endl;
	//bin << employ.Get_Gender() << endl;
	//bin.write(reinterpret_cast<char*> (&employ), sizeof(Employee_C));

	while (counter != 0) //bin >> employ.ID
	//do
	{

		//cin.get(employ.fullName, SIZE);
		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//bin << employ.fullName << endl;
		
		//cin >> employ.ID;
		//bin << employ.Get_Name() << endl;
		//bin << employ.Get_ID() << endl;
		//bin << employ.Get_Salary() << endl;
		//bin << employ.Get_Gender() << endl;
		//bin.write(reinterpret_cast<char*> (&employ), sizeof(Employee_C));


		for (int i = 0; i < 100; i++)
		{
			bin << employ_p.fullName << " ";

			cin.get(employ_p.fullName, SIZE);
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			bin << employ_p.fullName << endl;
			

			cin >> employ_p.ID;
			bin << employ_p.ID << "\n";
			


			cin >> employ_p.salary;
			bin << employ_p.salary << "\n";
			

			cin >> employ_p.gender;
			bin << employ_p.gender << "\n";
			

			bin.write(reinterpret_cast<char*> (&employ_p), sizeof(Employee_C));
			//bin.write(reinterpret_cast<char*> (&acct), sizeof(acct));
		} //while (employ.Get_ID() != 0);
	}
		
	cout << " Name " << employ_p.Get_Name();
	cout << " ID " << employ_p.Get_ID();
	cout << " Salary " << employ_p.Get_Salary();
	cout << " Gender " << employ_p.Get_Gender();

	cout << "\nhere as well";

	txt.close();
}

int Find_Employee(fstream& txt, fstream& bin, int* notFound_p)//make INT to return value
{

	Employee_C employ;

	int searchEmp;

	bool stop = 1;
	


	cout << "\nPlease enter the employee I.D. to be searched for . . .";
	cin >> searchEmp;

	fstream search;

	//fstream search("fileName", ios::in | ios::binary);
	//search.read();

	fstream inFile;
	inFile.open("fileName", ios::binary);

	while (inFile.read((char*)&employ, sizeof(Employee_C)))
	{
		if (employ.Get_ID() == searchEmp)
		{
			cout << "\nThe position of " << employ.ID << " is " << &employ.ID;
		}
		else
		{
			int unableToFind = -1;
			int* notFound_p = &unableToFind;

			return *notFound_p;
		}
	}


	//while (search.read((char*)&employ, sizeof(employ)))
	while (stop != 0)
	{
		search.read((char*)&employ, sizeof(employ));

		if (employ.Get_ID() == searchEmp)
		{
			
			cout << "\nThe position of " << employ.ID << " is " << &employ.ID; //should print out the position, cant test due to error LNK2001
			//employ.Display_Info(); 
		}
		else
		{

			int unableToFind = -1;
			int* notFound_p = &unableToFind;

			//return -1;
			return *notFound_p; //was getting error C2082 "Redefinition of formal paratmer "notFound_p" ---- FIXED
		}

		cout << "\nEnter 1 to continue or 0 to stop . . . ";
		cin >> stop;
	}

	do
	{
		
	
			search.read((char*)&employ, sizeof(Employee_C));

			if (employ.Get_ID() == searchEmp)
			{

				cout << "\nThe position of " << employ.ID << " is " << &employ.ID; //should print out the position, cant test due to error LNK2001
				//employ.Display_Info(); 
			}
			else
			{

				int unableToFind = -1;
				int* notFound_p = &unableToFind;

				//return -1;
				return *notFound_p; //was getting error C2082 "Redefinition of formal paratmer "notFound_p" ---- FIXED
			}
		
	} while (!search.eof());


	/*bin.read(reinterpret_cast<char*> (&employ), sizeof(Employee_C));
	while (bin)
	{

		if(searchEmp)

	}*/

}

//void Display_Salaries(Employee_C& sal)
//{
//	Employee_C employ;
//	
//	cout << setprecision(2) << fixed;
//
//	employ.Get_Salary();
//
//}

void Display_Info(Employee_C& obj)
{
	obj.Display_Info();
}

//double Display_TotalSal(double sal, double totalSal)
//{
//	Employee_C employ;
//
//	Set_TotalSal
//
//}