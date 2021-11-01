#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
	ifstream infile;
	infile.open("test123Kappa.txt");
	if (!infile) {
		cout << "didnt work" << endl;
		exit(EXIT_FAILURE);
	}
	string herder;
	while (!infile.eof()) {
		getline(infile, herder);
		if (herder.empty())continue; //skips if nothing if on that line
		herder = "dont't "+herder;
		cout << herder << endl;
	}


}