#include <bits/stdc++.h>
using namespace std;
ofstream out("prince.inp");

int main() {
	//
	cout << "n? ";
	int n; cin >> n; cout << endl;
	cout << "k? ";
	int k; cin >> k; cout << endl;
	//
	srand((unsigned) time(0));
	//
	out << n << endl;
	int pre = 0;
	for (int i = 0; i < n; i++) {
		pre += rand() % k + 1;
		out << pre << " " << rand() % 20 << endl;
	}
	out << pre + rand() % k + 1;
}
