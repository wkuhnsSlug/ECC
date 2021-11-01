#include <iostream>
#include <string>
#include <cstring>
#include "student.h"
using namespace std;
/*
Name: William Kuhns
Class: CSCI 30, Advanced Programming in C++
Section: 0131
Assignment Number: 0
Files: main.cpp,student.h,student.cpp
Due Date: 2016/01/25

I, William Kuhns, pledge that this is my own independent work, which conforms to
generally accepted guidelines of academic honesty.
*/
int main(int args[]) {
	char str[MAX_LEN];
	cout << "Enter a string: ";
	cin >> str;
	csprint_ind(str);
	csprint_ptr(str);

	system("pause");
	cout << "Enter up to 10 integers. Make that -999 is not a possible integer" << endl
		<< "to be considered, and hence may be used to stop the entry of data." <<endl;
	const int max = 10;
	int arr[max];
	int len=0;
	while(len<max){
		cout << "Enter integer: ";
		int temp;
		cin >> temp;
		if (temp == -999) {
			break;
		}
		arr[len]=temp;
		len++;
	}
	aiprint_ind(arr, len);
	aiprint_ptr(arr, len);
	system("pause");
	cout << "Enter up to 10 structures terminated by first name \"*\"" << endl;

	Student arrS[max];
	Student *p=&arrS[0];
	int lenS = 0;
	while (lenS<max) {
		cout << "Enter first name: ";
		char temp[MAX_LEN];
		
		cin >> p->firstName;
		
		if (p->firstName[0] == '*') {
			break;
		}
		cout << "Enter last name: ";
		cin >> p->lastName;
		cout << "Enter gpa: ";
		cin >> p->gpa;
		p++;
		lenS++;
	}
	struc_print_ind(arrS, lenS);
	struc_print_ptr(arrS, lenS);
}
