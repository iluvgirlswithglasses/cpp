#include <iostream>
using namespace std;

int m, a, d;

//
int main() {
	int t; cin >> t;
	while (t--) {
		//@ inp
		cin >> m >> a;
		//@ calc
		if (m==1) {
			cout << 1 << endl;
			continue;
		}
		//
		d = (a/3) * 2;
		if (a%3 > 0) d++;
		cout << d << endl;
	}
	//
	return 0;
}
