#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	ofstream out("test.txt");
	srand((unsigned) time(0));
	//
	cin >> n;
	out << n << "\n";
	while (n--) {
		out << (rand() % 1004) << " ";
	}
	return 0;
}
