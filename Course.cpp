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
#include "Course.h"

Course::Course()
{
	this->name = NULL;
	this->lecturer = NULL;
	this->grade = 0;
	
}

Course::Course(const char* n, const char* l, int g)
{
	this->name = new char[strlen(n)+1];
	if (!this->name)
		return;
	else
		strcpy(this->name, n);

	this->lecturer = new char[strlen(l)+1];
	if (!this->lecturer)
		return;
	else
		strcpy(this->lecturer, l);

	this->grade = g;
}


Course::Course(const Course& c)
{
	this->name = new char[strlen(c.name) + 1];
	if (!this->name)
		return;
	else
		strcpy(this->name, c.name);


	this->lecturer = new char[strlen(c.lecturer) + 1];
	if (!this->lecturer)
		return;
	else
		strcpy(this->lecturer, c.lecturer);


	this->grade = c.grade;

}


Course::~Course()
{

}


void Course:: operator =(const Course& c)
{
	this->name = new char[strlen(c.name) + 1];
	if (!this->name)
		return;
	else
		strcpy(this->name, c.name);


	this->lecturer = new char[strlen(c.lecturer) + 1];
	if (!this->lecturer)
		return;
	else
		strcpy(this->lecturer, c.lecturer);


	this->grade = c.grade;
}

void Course::print()const
{
	cout << "Course Name:" << this->name << endl;
	cout << "Lecturer Name:" << this->lecturer << endl;
	cout << "Grade:" << this->grade << endl;
}

int Course::get_grad()
{
	return this->grade;
}

char* Course::get_name()
{
	return this->name;
}

void Course::set(const char* lect, int grade)
{
	delete[] this->lecturer;
	this->lecturer = new char[strlen(lect) + 1];
	if(this->lecturer)
		strcpy(this->lecturer, lect);
	this->grade = grade;

}