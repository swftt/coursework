#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <ctime>
#include <string>
#include <cmath>
#include <typeinfo>
using namespace std;
// TODO make delete,make editing
class Worker {
	string name, surname;
	int age;
	int salary;
	int id;
public:
  	static int identifier;
	virtual int ClassType() = 0;
	Worker()
	{
		name = "David";
		surname = "Beckham";
		age = 30;
		salary = 20000;
		id = identifier;
	}
	Worker(string name, string surname, int age, int salary) {
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->salary = salary;
		id = identifier;
	}
	int GetId()
	{
		return id;
	}
	void PrintInfo()
	{
		cout<<id<<"   "<<name<<"   "<<surname<<"   "<<age<<"   " <<salary<<"  ";
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
	void SetWorker(string name, string surname, int age, int salary)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->salary = salary;
	}
};
int Worker::identifier = 1;
class Programmer :public Worker {
	string position;  //junior,middle,senior,teamlead...
	double lengthOfWork;
	vector<string> languages;
public:
	int ClassType() { return 1; }
	Programmer()
	{
		position = "junior";
		lengthOfWork = 1;
		languages.push_back("c++");
	}
	Programmer(string position, vector<string>languages, double lengthOfWork)
	{
		this->position = position;
		this->lengthOfWork = lengthOfWork;
		for (int i = 0; i <languages.size(); i++)
		{
			this->languages.push_back(languages[i]);
		}
	}
	vector<string> GetLanguages()
	{
		return languages;
	}
	string GetPosition()
	{
		return position;
	}
	double GetLengthOfWork()
	{
		return lengthOfWork;
	}
	void PrintProgrammer()
	{
		PrintInfo();
		cout << position << "  " << lengthOfWork<<"  ";
		for (auto it : languages)
		{
			cout << it << "|";
		}
		cout << endl;
	}
	void SetProgrammer(string position, string languages[5], double legthOfWork)
	{
		this->position = position;
		this->lengthOfWork = legthOfWork;
		for (int i = 0; i < languages->size(); i++)
		{
			this->languages[i] = languages[i];
		}
	}
	
};
class Designer :public Worker {
	string position;      //newbie,old,teamlead...
	double lengthOfWork;
	string vectorOfWork;
public:
	int ClassType() { return 2; }
	Designer()
	{
		 position = "newbie";
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
		return position;
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
	void PrintDesigner()
	{
		PrintInfo();
		cout << position << "  " << lengthOfWork << "  " <<vectorOfWork<<"  ";
		cout << endl;
	}
	

};
class Devops :public Worker {
	double lengthOfWork;
	string position;
	string spesialSkills;
public:
	int ClassType() { return 3; }
	Devops()
	{
		lengthOfWork = 0.5;
		position = "default ";
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
	void PrintDevops()
	{
		PrintInfo();
		cout << position << "  " << lengthOfWork<<"  "<< spesialSkills << "  ";
		cout << endl;
	}
	
};
class DataBase {
	vector<Worker*>workers;
	void PrintWorker(Worker * worker)
	{
		if (worker->ClassType() == 1)
		{
			Programmer * programmer = (Programmer*)worker;
			programmer->PrintProgrammer();
		}
		if (worker->ClassType() == 2)
		{
			Designer * designer = (Designer*)worker;
			designer->PrintDesigner();
		}
		if (worker->ClassType() == 3)
		{
			Devops * devops = (Devops*)worker;
			devops->PrintDevops();
		}
	}

public:
	void CreateAndAddWorker(Worker *worker)
	{
		int choice;
		int ctorChoice;
		choice = worker->ClassType();
		string name, surname;
		int age;
		double salary;
		switch (choice)
		{
		case 1:
			cout << "Programmer" << endl;
			cout << "ctor: 1.Default 2.With parametrs";
			cin >> ctorChoice;
		
			if (ctorChoice == 1)
			{
				Worker * worker = new Programmer();
				Worker::identifier++;
				workers.push_back(worker);
			}
			 if (ctorChoice == 2){
				string position;
				cout << "ctor with param" << endl;
				cin.ignore();
				cout << "Name:";
				getline(cin, name);
				cout << "Surname:";
				getline(cin, surname);
				cout << "Age:";
				cin >> age;
				cout << "Salary:";
				cin >> salary;
				cin.ignore();
				cout << "Position:";
				getline(cin, position);
				int sizeOfLangArr;
				cout << "Enter how many programming languages to enter:";
				cin >> sizeOfLangArr;
				int lengthOfWork;
				vector<string> lang;
				cout << "Length of work in company:";
				cin >> lengthOfWork; cin.ignore();
				string tmpStr;
				for (size_t i = 0; i < sizeOfLangArr; i++)
				{
					getline(cin, tmpStr);
					lang.push_back(tmpStr);
				}
				worker = new Programmer(position, lang, lengthOfWork);
				worker->SetWorker(name, surname, age, salary);
				Worker::identifier++;
				workers.push_back(worker);
				
				


			}
			break;
		case 2:
			cout << "Designer" << endl;
			cout << "ctor: 1.Default 2.With parametrs";
			cin >> ctorChoice;
		
			if (ctorChoice == 1)
			{
				Worker * worker = new Designer();
				Worker::identifier++;
				workers.push_back(worker);
			}
			 if (ctorChoice == 2)
			{
				string vectorOfWork;
				string position;
				int lengthOfWork;
				cin.ignore();
				cout << "ctor with param" << endl;
				cout << "Name:";
				getline(cin, name);
				cout << "Surname:";
				getline(cin, surname);
				cout << "Age:";
				cin >> age;
				cout << "Salary:";
				cin >> salary;
				cin.ignore();
				cout << "Position:";
				getline(cin, position);
				cout << "Vector of work:";
				getline(cin, vectorOfWork);
				cout << "Length of work in company:";
				cin >> lengthOfWork;
				worker = new Designer(position,vectorOfWork,lengthOfWork);
				worker->SetWorker(name, surname, age, salary);
				Worker::identifier++;
				workers.push_back(worker);
			
			}
			break;
		case 3:
			cout << "Devops" << endl;
			cout << "ctor: 1.Default 2.With parametrs";
			cin >> ctorChoice;

			if (ctorChoice == 1)
			{
				Worker * worker = new Devops();
				Worker::identifier++;
				workers.push_back(worker);
			}
			 if (ctorChoice == 2)
			{
				string spesialSkills;
				string position;
				int lengthOfWork;
				cin.ignore();
				cout << "ctor with param" << endl;
				cout << "Name:";
				getline(cin, name);
				cout << "Surname:";
				getline(cin, surname);
				cout << "Age:";
				cin >> age;
				cout << "Salary:";
				cin >> salary;
				cin.ignore();
				cout << "Position:";
				getline(cin, position);
				cout << "Spesial:";
				getline(cin, spesialSkills);
				cout << "Length of work in company:";
				cin >> lengthOfWork;
				worker = new Devops(position, spesialSkills, lengthOfWork);
				worker->SetWorker(name, surname, age, salary);
				Worker::identifier++;
				workers.push_back(worker);
			}
			break;

			
		}
	
	}
	void PrintWorkers()
	{
		cout << endl;
		for (int i=0;i<workers.size();i++)
		{
			PrintWorker(workers[i]);
		}
		cout << endl;
	}
	DataBase operator+(const DataBase &other)                //can create new database with few databases or add database to your database
	{
		DataBase database;
		for (auto it : other.workers)
		{
			workers.push_back(it);
		}
		for (auto it : workers)
		{
			database.workers.push_back(it);
		}
		return database;
	}  
	void DeleteByPos(int pos)
	{
		workers.erase(workers.begin() + pos);
		PrintWorkers();
	}
	void DeleteFromPosToPos(int pos1, int pos2)
	{
		workers.erase(workers.begin() + pos1, workers.begin() + pos2-1);
		PrintWorkers();
	}
	void DeleteByInfo(string criterion, string searchCriterion)
	{
		if (criterion.compare("surname") == 0)
		{
		
			for (size_t i=0;i<workers.size();i++)
			{
				if (workers[i]->GetSurname().compare(searchCriterion) == 0)
				{
					workers.erase(workers.begin() + i);
					i--;	
				}
				

			}
			cout << "deleted by surname" << endl;
		}
		else
			cout << "Not found" << endl;
	
		PrintWorkers();
	}
};
int main()
{
	DataBase d;
	Worker * worker=new Programmer();
	Worker *wor = new Designer();
	Worker * worker2 = new Designer();
	Worker *wor2 = new Devops();
	Worker * worker3 = new Programmer();
	Worker *wor3 = new Devops();
	DataBase d2;
	d.CreateAndAddWorker(worker);
	d.CreateAndAddWorker(wor2);
	d.CreateAndAddWorker(worker2);
	d.PrintWorkers();
	
	
	d2.CreateAndAddWorker(wor3);
	d2.CreateAndAddWorker(worker3);
	d2.CreateAndAddWorker(wor);
	d2.PrintWorkers();

	cout << endl;
	DataBase d3;
	d = d + d2;
	d.PrintWorkers();
	
	d.DeleteByInfo("surname", "lol");
	//d.DeleteFromPosToPos(2, 4);
//	d.DeleteByPos(3);
	

	return 0;
}
