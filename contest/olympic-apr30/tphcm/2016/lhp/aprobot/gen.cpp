#include <bits/stdc++.h>
using namespace std;
ofstream out("aprobot.inp");

int main() {
	srand((unsigned) time(0));
	out << 500 << " " << 6 << endl;
	for (int i = 0; i < 500; i++) {
		out << rand() % 1000 + 1 << " ";
	}
	return 0;
}
