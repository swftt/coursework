// coursework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <ctime>
#include <string>
#include <cmath>
using namespace std;

class Worker {
	string name, surname;
	int age;
	double salary;
public:
	Worker()
	{
		name = "David";
		surname = "Beckham";
		age = 30;
		salary = 20000;
	}
	Worker(string name,string surname,int age, double salary)	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->salary = salary;
	}
	string Get_All_Info()
	{
		return name+"  "+ surname+"  " + to_string(age)+"  " + to_string(salary);
	}
	string GetName()
	{
		return name;
	}
	string GetSurname()
	{
		return surname;
	}
	int GetAge()
	{
		return age;
	}
	double GetSalary()
	{
		return salary;
	}
	void SetWorker(string name, string surname, int age, double salary)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->salary = salary;
	}
};
class Programmer:public Worker {
	string position;  //junior,middle,senior,teamlead...
	double lengthOfWork;
	string languages[5];
public:
	Programmer()
	{
		position = "junior";
		lengthOfWork = 1;
		languages[0] = { "c++" };
	}
	Programmer(string position,string *languages, double lengthOfWork)
	{
		this->position = position;
		this->lengthOfWork = lengthOfWork;
		for (int i = 0; i < 5; i++)
		{
			this->languages[i] = languages[i];
		}
	}
	string GetPosition()
	{
		return position;
	}
	double GetLengthOfWork()
	{
		return lengthOfWork;
	}
	string  GetLanguages()
	{
		return languages[0] + " "+languages[1] + " "+languages[2] + " " + languages[3] + " " + languages[4] + " ";
	}
	void SetProgrammer(string position, string languages[5], double legthOfWork)
	{
		this->position = position;
		this->legthOfWork = legthOfWork;
		for (int i = 0; i < languages->size(); i++)
		{
			this->languages[i] = languages[i];
		}
	}
	string GetInfoProgrammer()
	{
		return Get_All_Info() + " " + position + " " + to_string(legthOfWork) + " " + GetLanguages();
	}
};
class Designer :public Worker {
	string position;      //newbie,old,teamlead...
	double lengthOfWork;
	string vectorOfWork;
public:
	Designer()
	{
		string position = "newbie";
		lengthOfWork = 1;
		vectorOfWork = "3d";
	}
	Designer(string position, string vectorOfWork, double lengthOfWork)
	{
		this->position = position;
		this->vectorOfWork = vectorOfWork;
		this->lengthOfWork = lengthOfWork;
	}
	string GetPosition()
	{
		return postion;
	}
	double GetLengthOfWork()
	{
		return lengthOfWork;
	}
	string GetVectorOfWork()
	{
		return vectorOfWork;
	}
	void SetDesigner(string position, string vectorOfWork, double lengthOfWork)
	{
		this->position = position;
		this->vectorOfWork = vectorOfWork;
		this->lengthOfWork = lengthOfWork;
	}
	string GetInfoDesigner()
	{
		return Get_All_Info() + " " + position + " " + to_string(lengthOfWork)+ " " + vectorOfWork + " ";
	}

};
class Devops :public Worker {
	double lengthOfWork;
	string position;
	string spesialSkills;
public:
	Devops()
	{
		lengthOfWork = 0.5;
		position = "default worker";
		spesialSkills = "python knowledge";

	}
	Devops(string position, string spesialSkills, double lengthOfWork)
	{
		this->position = position;
		this->spesialSkills = spesialSkills;
		this->lengthOfWork = lengthOfWork;
	}
	double GetLengthOfWork()
	{
		return lengthOfWork;
	}
	string GetPosition()
	{
		return position;
	}
	string GetSkills()
	{
		return spesialSkills;
	}
	void SetDevops(string position, string spesialSkills, double lengthOfWork)
	{
		this->position = position;
		this->spesialSkills = spesialSkills;
		this->lengthOfWork = lengthOfWork;
	}
	string GetInfoDev()
	{
		return Get_All_Info() + " " + position + " " + to_string(lengthOfWork) + " " + spesialSkills + " ";
	}
};
int main()
{
    return 0;
}

