#include <iostream>
#pragma once
using namespace std;

const int MAX_LEN = 30;
struct Student
{
	char firstName[MAX_LEN + 1];
	char lastName[MAX_LEN + 1];
	float gpa;
};

void csprint_ind(const char s[]);
void csprint_ptr(const char *s);
void aiprint_ind(const int a[],int na);
void aiprint_ptr(const int *pa, int na);
void struc_print_ind(const Student x[], int nx);
void struc_print_ptr(const Student *px, int nx);

