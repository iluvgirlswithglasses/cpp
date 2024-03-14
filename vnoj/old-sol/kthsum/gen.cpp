#include <fstream>
#include <iostream>
#include <random>
#include <time.h>
using namespace std;

ofstream out("test.txt");

int main() {
	srand((unsigned) time(0));
	int n, k; cin >> n >> k;
	out << n << " " << k << "\n";
	while (n--) {
		out << rand() % (1<<15) - (1<<14) << " ";
	} out << "\n";
	return 0;
}
