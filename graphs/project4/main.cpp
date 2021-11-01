
#include <iostream>
#include <string>
#include "hw4.h"
using namespace std;
int main() {
	ifstream infile("words.txt");
	cout << "hello" << endl;
	mainLoop(infile);
	infile.close();
}