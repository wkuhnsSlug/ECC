#ifndef hw4_h
#define hw4_h
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
void mainLoop(ifstream&);
void checker(string inp, ifstream& infile, string*& s,bool);
void checkerAux(string inp, string*& s,int i,bool&);
void solver(string inp, string*& s);
void solverAux(string,string,int&, string*& s);
void loop(string pre, string str, int& i, string*& s,int);
int fact(int);
#endif


