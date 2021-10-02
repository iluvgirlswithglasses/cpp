#include <iostream>
using namespace std;

typedef long long int lli;

// stupid note
// c = a ^ b => a = c ^ b;

// perfs
void calc() {
	int n; cin >> n;
	// dynamic[i] = sum_xor(arr, arr + i + 1);
	lli * dynamic = new lli[n];
	//
	cin >> dynamic[0];
	for (int i = 1; i < n; i++) {
		lli t; cin >> t;
		dynamic[i] = dynamic[i-1] ^ t;
	}
	// even case
	if (dynamic[n-1] == 0) {
		cout << "YES\n";
		delete[] dynamic;
		return;
	}
	// odd case
	for (int i = 1; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			lli sect0 = dynamic[i-1];					// 0 -> i
			lli sect1 = dynamic[j-1] ^ dynamic[i-1];	// i -> j
			lli sect2 = dynamic[n-1] ^ dynamic[j-1];	// j -> n
			// simple, yet took me a whole hour to figure this out
			if (sect0 == sect1 && sect1 == sect2) {
				cout << "YES\n";
				delete[] dynamic;
				return;
			}
		}
	}
	//
	cout << "NO\n";
	delete[] dynamic;
}

// drivers
int main() {
	int t; cin >> t;
	while (t--) {
		calc();
	}
	//
	return 0;
}
