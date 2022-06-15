//Name:Renana Hoshen
//ID:319034757
//Third Task 
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#include <string.h>
#include <cstdlib>
#include "Student.h"

Student::Student()
{
	this->name = NULL;
	this->ID = 0;
}


Student::Student(const char* n, long id)
{
	if (strlen(n) > 20)
		return;
	else
	{
		this->name = new char[strlen(n) + 1];
	if (!this->name)
		return;
	else
		strcpy(this->name, n);

	this->ID = id;
	}
	
}


Student::Student(const Student& s)
{
	this->name = new char[strlen(s.name) + 1];
	if (!this->name)
		return;
	else
		strcpy(this->name, s.name);

	this->ID = s.ID;
}



Student::~Student()
{

}

void Student::print()const
{
	cout << "Student Name:" << this->name << endl;
	cout << "Student ID:" << this->ID << endl;
}

long Student::get_id()
{
	return this->ID;
}

void Student::print_good()const
{
	print();
}

int  Student::type()
{
	return 0;
}

char* Student:: supervisor_name()
{
	return NULL;
}

void Student::print_name()const
{
	cout << "Student Name: " << this->name << endl;
}

bool Student:: update_book(const char* n, const char* np, int grade)
{
	return false;
}