#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;
bool balance(char *c,unsigned len);
char *change(ifstream& infile, unsigned& len);
void reSize(char *&a, unsigned& len);
int main() {
	ifstream infile;
	infile.open("test.txt");
	unsigned len = 0;
	char *c = change(infile,len);
	bool end = balance(c, len);
	if (end) {
		cout << "worked" << endl;
	}else {
		cout << "nope" << endl;
	}

}
char *change(ifstream& infile,unsigned& len) {
	len = 1000;
	int j = 0;
	char *temp = new char[len];
	while (!infile.eof()) {
		string str;
		getline(infile, str);
		for (int i = 0;i < str.length();i++) {
			if (j >= (int)len) {
				reSize(temp, len);
			}
			temp[j]=str[i];
			j++;
		}
		if (j >= (int)len) {
			reSize(temp, len);
		}
		temp[j] = '\n';
		j++;
	}
	return temp;
}
bool balance(char *c,unsigned len){
	stack<char> s;
	char d;
	bool errorF = false;
	for (int i = 0;i < (int)len;i++) {
		switch (c[i])
		{
		case '\'':
			for (int j = i+1;j < (int)len;j++) {
				if (c[j] == '\'') {
					i = j;
					cout << "pair matching \' and \' " << endl;
					errorF = true;
					break;
				}
			}
			if (!errorF) {
				return false;
			}
			break;
		case '\"':
			for (int j = i+1;j < (int)len;j++) {
				if (c[j] == '\"') {
					i = j;
					cout << "pair matching \" and \" " << endl;
					errorF = true;
					break;
				}
			}
			if (!errorF) {
				return false;
			}
			break;
		case '/':
			if (c[i + 1] == '*') {
				for (int j = i + 2;j < (int)len;j++) {
					if (c[j] == '*' && c[j + 1] == '/') {
						i = j+1;
						cout << "pair matching /* and */ " << endl;
						errorF = true;
						break;
					}
				}
				if (!errorF)return false;
			}else if (c[i + 1] == '/') {

			}
			break;
		case '*':
			break;
		case '(':
		case '{':
		case '[':
			s.push(c[i]);
			break;
		case ')':
			if (s.empty()) 	return false;
			d = s.top();
			s.pop();
			if (d != '(') {
				return false;
			}
			cout << "pair matching ( and )" << endl;
			break;
		case '}':
			if (s.empty()) 	return false;
			d = s.top();
			s.pop();
			if (d != '{') {
				return false;
			}
			cout << "pair matching { and }" << endl;
			break;
		case ']':
			if (s.empty()) 	return false;
			d = s.top();
			s.pop();
			if (d != '[') {
				
				return false;
			}
			cout << "pair matching [ and ]" << endl;
			break;
		} // end switch
	}
	return true;
}
void reSize(char *&a, unsigned& len) {
	char *temp = new char[len*2];
	for (int i = 0;i < (int)len;i++) {
		temp[i] = a[i];
	}
	delete[] a;
	a = temp;

}