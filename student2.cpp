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
#include "student2.h"

Student2::Student2() :Student()
{
	this->thesis = NULL;
	this->supervisor = NULL;
}

Student2::Student2(const char* t, const char* s, const char* n, long id):Student(n,id)
{
	if (strlen(t) > 20)
		return;
	else
	{
		this->thesis = new char[strlen(t) + 1];
		if (!this->thesis)
			return;
		else
			strcpy(this->thesis, t);
	}

	if (strlen(s) > 20)
		return;
	else
	{
		this->supervisor = new char[strlen(s) + 1];
		if (!this->supervisor)
			return;
		else
			strcpy(this->supervisor, s);
	}
}

Student2::Student2(const Student2& s) :Student(s.name,s.ID)
{
	if (strlen(s.thesis) > 20)
		return;
	else
	{
		this->thesis = new char[strlen(s.thesis) + 1];
		if (!this->thesis)
			return;
		else
			strcpy(this->thesis, s.thesis);
	}

	if (strlen(s.supervisor) > 20)
		return;
	else
	{
		this->supervisor = new char[strlen(s.supervisor) + 1];
		if (!this->supervisor)
			return;
		else
			strcpy(this->supervisor, s.supervisor);
	}
}

Student2::~Student2()
{

}

void Student2::print()const
{
	Student::print();
	cout << "Thesis topic:" << this->thesis << endl;
	cout << "Thesis facilitator:" << this->supervisor << endl;
		
}

bool Student2::outstanding()const
{
	return true;
}

void Student2::print_good()const
{
	if (outstanding())
		Student::print();
}

int  Student2::type()
{
	return 3;
}

char* Student2::supervisor_name()
{
	return this->supervisor;
}