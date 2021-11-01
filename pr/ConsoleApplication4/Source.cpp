#include <iostream>
using namespace std;
class Person {
public:
	Person(const char* name) : m_name(name) {
		cout << m_name << endl;
	}
	~Person() {
		cout << "~" << m_name << endl;
		throw -1;
	}
private:
	const char* m_name;
};
void funcB() {
	cout << "1" << endl;
	Person x("X");
	Person y("Y");
	cout << "2" << endl;
	return;
}
void funcA() {
	cout << "3" << endl;
	try {
		funcB();
	}
	catch (int) {
		cout << "4" << endl;
	}
	cout << "5" << endl;
}
int main() {
	try {
		funcA();
	}
	catch (int) {
		cout << "6" << endl;
	}
	catch (...) {
		cout << "7" << endl;
	}
	cout << "8" << endl;
	return 0;
}

/*
3
1
X





3
1
X
Y
~Y
~X
4
5
8
*/
		/*
		Base::5
		D1::10
		Other::15
		~Other::-15
		~D1::-10
		~base::-5
		*/

/*
#include <iostream>
using namespace std;
class Person
{
public:
void Play()
{
cout << "Person::Play" << endl;
};
void Study()
{
cout << "Person::Study" << endl;
}
};
class Student : public Person
{
public:
virtual void Study()
{
cout << "Student::Study" << endl;
}
};
class CS_Student : public Student
{
public:
void Play()
{
cout << "CS_Student::Play!" << endl;
}
void Study()
{
cout << "CS_Student::Study!" << endl;
}
};
void activity(Student &s)
{
s.Play();
s.Study();
}
int main()
{
CS_Student cs_student;
activity(cs_student);
}
Output:

*/
/*
Output:
A
A
#include <iostream>
using namespace std;
class A
{
public:
void output()
{
cout << "A" << endl;
}
};
class B : public A
{
public:
void output()
{
cout << "B" << endl;
}
};
int main()
{
A *a = new A();
a->output();
A *b = new B();
b->output();
delete a, b;
}
*/
/*

#include <iostream>
using namespace std;
class Base
{
public:
void output(int n)
{
cout << "Hello Base" << n << endl;
}
};
class Derived : public Base
{
public:
// This hides the output(int n) member function
// from Base class
void output()
{
cout << "Hello Derived Class!" << endl;
}
};
int main()
{
Base b;
b.output(1);
Derived d;
d.output();
d.Base::output(2);
}
Output:
Hello Base1
Hello Derived Class
Hello Base2
*/
/*
#include <iostream>
using namespace std;
class Person {
public:
virtual void eat() { cout << "Yummy" << endl; }
virtual void speak() { cout << "Hello" << endl; }
virtual void sleep() { cout << "ZZZZ" << endl; }
};
class Student : public Person {
public:
void speak() { cout << "I love school" << endl; }
void
study() {
cout << "Studying for Midterm test"
<< endl;
}
void getReadyForTest() {
study();
sleep();
}
};
class ElCaminoStudent : public Student {
public:
void speak() { cout << "Go Warriors!" << endl; }
void sleep() {
cout <<
"ZZZ... CS2 ...ZZZZ" << endl;
}
void getReadyForCS2Test() {
study();
eat();
sleep();
}
};
int main() {
Person* array[3];
array[0] = new Person();
array[1] = new Student();
array[2] = new ElCaminoStudent;
for (int i = 0; i < 3; i++) {
array[i]->eat();
array[i]->speak();
array[i]->sleep();
}
Student * sp = new Student();
ElCaminoStudent *ecp = new ElCaminoStudent;
sp->getReadyForTest();
ecp->getReadyForCS2Test();
}
output:
 Yummy
 hello
 zzzz
 Yummy
 "I love school"
 ZZZZ
 Yummy
 "I love school"
 ZZZZ
 "Studying for Midterm test"
 ZZZZ
 "Studying for Midterm test"
 Yummy
 ZZZ... CS2 ...ZZZZ
*/
