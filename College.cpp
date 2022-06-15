//Name:Renana Hoshen
//ID:319034757
//Third Task 

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#include <string.h>
#include <cstdlib>
#include "Student.h"
#include "Student0.h"
#include "student1.h"
#include "student2.h"
#include "Course.h"
#include "College.h"

College::College()
{
	this->arr = NULL;
	this->size = 0;
}



bool College::add_student()
{
	long id;
	cout << "Enter ID:" << endl;
	cin >> id;

	for (int i = 0; i < this->size; ++i)
	{
		if (this->arr[i]->get_id() == id)
			return false;
	}
	char name[20];
	int type;
	cout << "Please enter student name:" << endl;
	cin >> name;
	cout << "Select a student type:" << endl;
	cout << "1 - Preparatory" << endl;
	cout << "2 - Bachelor's degree" << endl;
	cout << "3 - Master's degree" << endl;
	cin >> type;
	Student** arr2 = NULL;
	switch (type)
	{
	case 1:
		int a;
		cout << "Does the student study in a short or long preparatory course?" << endl;
		cout << "1-short" << endl;
		cout << "2-long" << endl;
		cin >> a;
		if (a == 1)
		{
			//Student** arr2 = NULL;
			arr2 = new Student * [this->size + 1];
			if (!arr2)
				return false;
			for (int i = 0; i < this->size; ++i)
				arr2[i] = this->arr[i];
			delete[]this->arr;
			arr2[size] = new Student0(true, name, id);
			this->size = this->size + 1;
			this->arr = new Student * [this->size];
			if (!this->arr)
				return false;
			for (int i = 0; i < this->size; ++i)
				this->arr[i] = arr2[i];
			return true;
			break;
		}
		else
		{
			//Student** arr2 = NULL;
			arr2 = new Student * [this->size + 1];
			if (!arr2)
				return false;
			for (int i = 0; i < this->size; ++i)
				arr2[i] = this->arr[i];
			delete[]this->arr;
			arr2[size] = new Student0(false, name, id);
			this->size = this->size + 1;
			this->arr = new Student * [this->size];
			if (!this->arr)
				return false;
			for (int i = 0; i < this->size; ++i)
				this->arr[i] = arr2[i];
			return true;
			break;
		}
	case 2:
		int y;
		cout << "Please enter the student's school year:" << endl;
		cin >> y;
		//Student** arr2 = NULL;
		arr2 = new Student * [this->size + 1];
		if (!arr2)
			return false;
		for (int i = 0; i < this->size; ++i)
			arr2[i] = this->arr[i];
		delete[]this->arr;
		arr2[size] = new Student1(y, name, id);
		this->size = this->size + 1;
		this->arr = new Student * [this->size];
		if (!this->arr)
			return false;
		for (int i = 0; i < this->size; ++i)
			this->arr[i] = arr2[i];
		return true;
		break;

	case 3:
		char t[20];
		char l[20];
		cout << "Enter the name of the thesis:" << endl;
		cin >> t;
		cout << "Enter the name of the lecturer";
		cin >> l;
		
		arr2 = new Student * [this->size + 1];
		if (!arr2)
			return false;
		for (int i = 0; i < this->size; ++i)
			arr2[i] = this->arr[i];
		delete[]this->arr;
		arr2[size] = new Student2(t, l, name, id);
		this->size = this->size + 1;
		this->arr = new Student * [this->size];
		if (!this->arr)
			return false;
		for (int i = 0; i < this->size; ++i)
			this->arr[i] = arr2[i];
		return true;
		break;

	default:
		break;
	}
}




bool College::add_grade(long id, const char* c, const char* l, int g)
{
	for (int i = 0; i < this->size; ++i)
	{
		if (this->arr[i]->type()==2)
		{
			this->arr[i]->update_book(c, l, g);
			return true;
		}
	}
	return false;

}

void College::print_all()const
{
	for (int i = 0; i < this->size; ++i)
		this->arr[i]->print();

}

void College::print_excellent()const
{
	cout << "Outstanding students: ";
	for (int i = 0; i < this->size; ++i)
		this->arr[i]->print_good();

}

void College::find_type(int& a, int& b, int& c)
{
	int count1=0;
	int count2=0;
	int count3=0;
	for (int i = 0; i < this->size; ++i)
	{
		if (this->arr[i]->type() == 1)
			++count1;
		else
			if (this->arr[i]->type() == 2)
				++count2;
			else
				if (this->arr[i]->type() == 3)
					++count3;
		a = count1;
		b = count2;
		c = count3;
	}
}

int College:: supervisor(const char* n)
{
	int count = 0;
	for (int i = 0; i < this->size; ++i)
	{
		if (this->arr[i]->type() == 3)
		{
			if (strcmp(this->arr[i]->supervisor_name(), n) == 0)
			{
				this->arr[i]->print_name();
				++count;
			}
		}
	}
	cout << "the amount of names is: " << count << endl;
	return count;
}

int College::menu()
{
	int choice;
	int a = 0;
	int b = 0;
	int c = 0;
	char lesson[20];
	char proffesor[20];
	do
	{
		cout << "Main Menu:" << endl;
		cout << "1-Add Student" << endl;
		cout << "2-Add Grade" << endl;
		cout << "3-Print All" << endl;
		cout << "4-Print excellent" << endl;
		cout << "5-Types of student" << endl;
		cout << "6-Supervisor" << endl;
		cout << "7-Quit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			if (add_student())
				cout << "Succeeded" << endl;
			else
				cout << "failed" << endl;
			break;
		case 2:
			long id;
			
			int grade;

			cout << "please enter ID: " << endl;
			cin >> id;
			cout << "please enter the Name of the course: " << endl;
			cin >> lesson;
			cout << "please enter the Name of the lecturer: " << endl;
			cin >> proffesor;
			cout << "please enter grade: " << endl;
			cin >> grade;
			
			if (add_grade(id, lesson, proffesor, grade))
				cout << "Succeeded" << endl;
			else
				cout << "failed" << endl;
			break;
		case 3:
			print_all();
			break;
		case 4:
			print_excellent();
			break;
		case 5:
			
			find_type(a, b, c);
			cout<<"Quantities of students:"<<endl;
			cout << "Preparatory students: " << a << endl;
			cout << "Undergraduate students: " << b << endl;
			cout << "Graduate students: " << c << endl;
			break;
		case 6:
			
			cout << "please enter the Name of the lecturer:" << endl;
			cin >> proffesor;
			supervisor(proffesor);
			break;

		default:
			break;
		}
	} while (choice != 7);
	return 0;
	
}