#include <iostream>
#include <vector>
using namespace std;

int s, n;

void calc() {
	vector<int> f(n, 0);
	int i = 0;
	for (int e = 1e9; e > 0; e /= 10) {
		while (s >= e && s-e >= n-(i+1)) {	// n-(i+1): unfilled count
			f[i] += e;
			s -= e;
			if (i < n-1) i++; 
		}
	}
	//
	for (int &i: f) cout << i << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> s >> n;
		if (n == 1)
			cout << s << "\n";
		else
			calc();
	}
	return 0;
}
