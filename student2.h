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

class Student2 :public Student
{
private:
	char* thesis;
	char* supervisor;
public:
	Student2();
	Student2(const char* t,const char* s, const char* n, long id);
	Student2(const Student2& s);
	~Student2();
	void print()const;
	bool outstanding()const;
	void print_good()const;
	int type();
	char* supervisor_name();
};