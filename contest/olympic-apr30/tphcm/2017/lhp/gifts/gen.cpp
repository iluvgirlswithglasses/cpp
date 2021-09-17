#include <iostream>
#include <fstream>
#include <time.h>
#include <random>
using namespace std;
ofstream out("gifts.inp");

unsigned long long llrand() {
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }

    return r & 0xFFFFFFULL;
}

int main() {
	srand((unsigned) time(0));
	int n; cout << "n? "; cin >> n;
	for (int i = 0; i < n; i++) out << llrand() + 1 << " ";
	return 0;
}
