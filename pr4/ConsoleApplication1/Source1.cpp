#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
void balance(ifstream&);
int main() {
	ifstream infile;
	infile.open("test123Kappa.txt");
	balance(infile);
}
void balance(ifstream& infile) {
	stack<char> s;
	stack<char> end;
	string str;
	char c;
	char d;
	while (!infile.eof()) {
		getline(infile, str);
		stringstream ss(str);
		while (!ss.eof()) {
			ss >> c;
			switch (c)
			{
			case '\'':
			case '\"':
			case '\\':
			case '*':
				break;
			case '(':
			case '{':
			case '[':
				s.push(c);
				break;
			case ')':
				if (s.empty()) 	return;
				d = s.top();
				s.pop();
				if (d != '(') {
					return;
				}
				else {
					end.push(c);
					end.push(d);
				}
				break;
			case '}':
				if (s.empty()) 	return;
				d = s.top();
				s.pop();
				if (d != '{') {
					return;
				}
				else {
					end.push(c);
					end.push(d);
				}
				break;
			case ']':
				if (s.empty()) 	return;
				d = s.top();
				s.pop();
				if (d != '[') {
					return;
				}
				else {
					end.push(c);
					end.push(d);
				}
				break;
			} // end switch
		} // end line
	} // end file
	for (int i = 0;i < (int)end.size();i++) {
		cout << "pair matching " << end.top();
		end.pop();
		cout << " and " << end.top() << endl;
		end.pop();
	}
} // end function
	/*
	char c;
	char d;
	int count=0;
	while (!infile.eof()) {
		getline(infile, str);
		stringstream ss(str);
		count++;
		int countC = 0;
		while (!ss.eof()) {
			ss >> c;
			switch (c) {
			case '\'':
			case '\"':
			case '\\':
			case '*':
				break;
			case '(':
			case '{':
			case '[':
				s.push(c);
				break;
			case ')':
				if (s.empty()) 	return;
				d = s.top();
				s.pop();
				if (d != '(') {
					return;
				}
				cout << "pair matching ( and )" << endl;
				break;
			case '}':
				if (s.empty()) 	return;
				d = s.top();
				s.pop();
				if (d != '{') {
					return;
				}
				cout << "pair matching { and }" << endl;
				break;
			case ']':
				if (s.empty()) 	return;
				d = s.top();
				s.pop();
				if (d != '[') {
					return;
				}
				cout << "pair matching [ and ]" << endl;
				break;
			}
			countC++;
		}
	}
	*/