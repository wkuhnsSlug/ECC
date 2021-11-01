#include "student.h"

void csprint_ind(const char s[]) {
	int i = 0;
	cout << "--- Printed Using Indexing ---" << endl;
	while (s[i]) {
		
		cout << s[i];
		i++;
	}
	cout << endl;
}
void csprint_ptr(const char *s) {
	cout << "--- Printed Using Pointers ---" << endl;
	while (*s) { 
		cout << *s;
		s++;
	}
	cout << endl;
}
void aiprint_ind(const int a[], int na) {
	cout << "--- Printed Using Indexing ---" << endl;
	for (int i = 0;i < na;i++) {
		cout << "a["<<i<<"] = " << a[i] << endl;
	}
}
void aiprint_ptr(const int *pa, int na) {
	cout << "--- Printed Using Pointers ---" << endl;
	for (int i = 0;i < na;i++) {
		const int *temp = (pa + i);
		cout << "*(pa+"<<i<<") = " << *temp << endl;
	}
}
void struc_print_ind(const Student x[], int nx) {
	cout << "--- Printed Using Indexing ---" << endl;
	for (int i = 0;i < nx;i++) {
		cout << "Name: " << x[i].firstName << " " << x[i].lastName<<endl;
		cout << "GPA: " << x[i].gpa <<endl;
	}
}
void struc_print_ptr(const Student *px, int nx) {
	cout << "--- Printed Using Pointers ---" << endl;
	for (int i = 0;i < nx;i++) {
		const Student *p = (px + i);
		cout << "Name: " << p->firstName <<" "<< p->lastName << endl;
		cout << "GPA: " << p->gpa << endl;
	}
}