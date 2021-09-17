#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream inp("inp.txt");
	cin.rdbuf(inp.rdbuf());
	//
	return 0;
}
