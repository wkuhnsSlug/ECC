#include "hw4.h"
void mainLoop(ifstream& infile) {
	string inp;
	//infile.seekg(0,infile.beg);
	
	infile.close();
	infile.open("words.txt");
	if (!infile)
	{
		cerr << "Error: Cannot open data.txt!" << endl;
		return;
	}
	cout << "Please enter a string for an anagram(!exit to quit) : ";
	getline(cin,inp);

	if (inp == "!exit") {
		cout << "bye!" << endl;
		return;
	}
	string *s = new string[fact(inp.length())];
	
	solver(inp, s);
	/*for (int i = 0;i < fact(inp.length());i++) {
		cout <<i<<". " <<s[i] << endl;
	}*/
	checker(inp, infile, s,false);
	mainLoop(infile);
}
void checker(string inp,ifstream& infile,string*& s,bool flag) {
	if (infile.eof()) {
		if (!flag)cout << "No matches found" << endl;
		return;
	}
	string str;
	infile>>str;
	checkerAux(str, s, (fact(inp.length()))-1,flag);
	checker(inp, infile,s,flag);
}
void checkerAux(string str, string*& s, int i,bool& flag) {
	if (i <0)return;
	if (str == s[i] && s[i]!="") {
		flag = true;
		cout << "Match Found! " << str << endl;
	}
	checkerAux(str, s, i - 1,flag);
}
void solver(string inp, string*& s) {
	int i = 0;
	solverAux("", inp,i,s);
}
void solverAux(string pre, string str,int& i, string*& s) {
	if (""==str) {
		s[i] = pre;
		i++;
	}else{
		/*for (int j = 0;j < str.length();j++) {
			solverAux(pre+ str[j], str.substr(0, j) + str.substr(j + 1, str.length()), i, s);
		}*/
		loop(pre, str, i, s, 0);
	}
}
void loop(string pre, string str, int& i, string*& s,int j) {
	if ((unsigned)j >= str.length()) {

		return;
	}
	solverAux(pre + str[j], str.substr(0, j) + str.substr(j + 1, str.length()), i, s);
	loop(pre, str, i, s, j + 1);
}
int fact(int n) {
	if (n == 0)return 1;
	return n*fact(n - 1);
}
