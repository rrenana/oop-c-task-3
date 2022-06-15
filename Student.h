//Name:Renana Hoshen
//ID:319034757
//Third Task 

#include<stdio.h>
#pragma once
#include<iostream>
using namespace std;
#include <string.h>
#include <cstdlib>

class Student
{
protected:
	char* name;
	long ID;
public:
	Student();
	Student(const char* n, long id);
	Student(const Student& s);
	~Student();
	virtual void print()const;
	bool outstanding()const;
	long get_id();
	virtual void print_good()const;
	virtual int type();
	virtual char* supervisor_name();
	void print_name()const;
	virtual bool update_book(const char* n, const char* np, int grade);
	friend class College;
};