//Name:Renana Hoshen
//ID:319034757
//Third Task 

//#include<iostream>
//using namespace std;
//#include <stdio.h>
//#include <string.h>
//#include <cstdlib>
//#include "Student.h"
//#include "Student0.h"
//#include "Student1.h"
//#include "Student2.h"
//#include "Course.h"
//#include "College.h"
//#include<stdio.h>
//#pragma once
//#include<iostream>
//using namespace std;
//#include <string.h>
//#include <cstdlib>
//#include "Student.h"
//#include "student0.h"

#include <iostream>
using namespace std;
#include <string.h>
#include <cstdlib>
#include "Student.h"
#include "Student0.h"


Student0::Student0():Student()
{
	this->short_is = true;
}


Student0::Student0(const bool s, const char* n, long id) :Student(n, id)
{
	this->short_is = s;
}

Student0::Student0(const Student0& s) : Student(s.name, s.ID)
{
	this->short_is = s.short_is;
}

Student0::~Student0()
{

}

void Student0::print()const
{
	Student::print();
	if (!this->short_is)
		cout << "Length of the preparatory course: Long" << endl;
	else
		cout << "Length of the preparatory course: short" << endl;
}


bool Student::outstanding()const
{
	return false;
}

void Student0::print_good()const
{
	if (outstanding())
		Student::print();
}


int  Student0::type()
{
	return 1;
}