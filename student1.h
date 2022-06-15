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
#include "Course.h"

class Course; class Student1 :public Student
{
private:
	Course* arr;
	int size;
	int year;
public:
	Student1();
	Student1(const int y, const char* n, long id);
	Student1(const Student1& s);
	~Student1();
	void add_course(const Course& c);
	void print()const;
	bool outstanding()const;
	Course get_course(int i);
	void print_good()const;
	int type();
	bool update_book(const char* n, const char* np, int grade);
	friend class Course;
};