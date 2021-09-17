#include <bits/stdc++.h>
using namespace std;

int main() {
	srand((unsigned) time(0));
	ofstream out("rate.inp");
	//
	int n = 300000, k = 40;
	out << n << " " << k << endl;
	for (int i = 0; i < n; i++) {
		out << (rand() % (int) pow(10, 6)) + 1 << " ";
	}
	//
	return 0;
}
