//Name:Renana Hoshen
//ID:319034757
//Third Task 

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#include <string.h>
#include <cstdlib>
#include "student1.h"


class Student1; class Course
{
private:
	char* name;
	char* lecturer;
	int grade;
public:
	Course();
	Course(const char* n,const char* l, int g);
	Course(const Course& c);
	~Course();
	void operator =(const Course& c);
	void print()const;
	int get_grad();
	char* get_name();
	void set(const char* lect, int grade);
	friend class student1;

};