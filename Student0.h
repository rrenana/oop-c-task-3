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


class Student0 :public Student
{
private:
	bool  short_is;
public:
	Student0();
	Student0(const bool s,const char* n,long id);
	Student0(const Student0& s);
	~Student0();
	void print()const;
	bool outstanding()const { return true; }
	void print_good()const;
	int type();
};