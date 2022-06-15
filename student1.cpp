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
#include "student1.h"
#include "Course.h"

Student1::Student1() :Student()
{
	this->arr = NULL;
	this->size = 0;
	this->year = 0;
}

Student1::Student1( const int y, const char* n, long id) :Student(n, id)
{
	this->arr = NULL;
	this->size = 0;
	if (y <= 4 && y >= 0)
		this->year = y;
		

}

Student1::Student1(const Student1& s):Student(s.name,s.ID)
{
	this->arr = new Course[s.size];
	if (!this->arr)
		return;
	else
	{
		for (int i = 0; i < s.size; ++i)
			this->arr[i] = s.arr[i];
		this->size = s.size ;
	}
	this->year = s.year;
}


Student1::~Student1()
{

}

void Student1::add_course(const Course& c)
{
	Course* arr2 = NULL;
	arr2 = new Course[this->size];
	if (!arr2)
		return;
	else
	{
		for (int i = 0; i < this->size; ++i)
			arr2[i] = this->arr[i];
		delete[]this->arr;
		this->arr = new Course[this->size];
		if (!this->arr)
			return;
		else
		{
			for (int i = 0; i < this->size; ++i)
				this->arr[i] = arr2[i];
			this->size = this->size + 1;
			this->arr[size] = c;
		}
	}
}

void Student1::print()const
{
	float average=0;
	Student::print();
	for (int i = 0; i < this->size; ++i)
	{
		average = average + this->arr[i].get_grad();
		this->arr[i].print();
	}
	cout << "school year: "<<this->year << endl;
	cout << "average: " << average << endl;
}

bool Student1::outstanding()const
{
	float average = 0;
	for (int i = 0; i < this->size; ++i)
		average = average + arr[i].get_grad();
	average = average / this->size;
	if (this->year == 1 || this->year == 2)
	{
		if (average >= 90)
			return true;
		else
			return false;
	}
	else
	{
		if (average >= 85)
			return true;
		else
			return false;
	}
}

Course Student1::get_course(int i)
{
	return this->arr[i];
}

void Student1::print_good()const
{
	if (outstanding())
		Student::print();
}

int  Student1::type()
{
	return 2;
}

bool Student1::update_book(const char* n, const char* np, int grade)
{
	for (int i = 0; i < this->size; ++i)
	{
		if (strcmp(this->arr[i].get_name(), n) == 0)
		{
			this->arr[i].set(np, grade);
			return true;
		}
		else
		{
			Course c(n, np, grade);
			add_course(c);
			return true;
		}
	}
	return false;
}