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
#include "student0.h"
#include "student1.h"
#include "student2.h"
#include "Course.h"

class College
{
private:
	Student** arr;
	int size;
public:
	College();
	bool add_student();
	bool add_grade(long id,const char*c,const char*l,int g);
	void print_all()const;
	void print_excellent()const;
	int supervisor(const char* n);
	void find_type(int& a, int& b, int& c);
	int menu();
};