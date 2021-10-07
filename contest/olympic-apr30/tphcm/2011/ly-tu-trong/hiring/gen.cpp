#include <fstream>
#include <random>
#include <time.h>
using namespace std;


int main() {
	//
	int n = 12;
	// pre
	ofstream out; out.open("hiring.inp");
	out << n << " " << n << " " << 7 << " " << 13 << endl;
	// gen
	srand((unsigned) time(0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << rand() % 2000 << " ";
		} out << endl;
	}
	//
	return 0;
}
