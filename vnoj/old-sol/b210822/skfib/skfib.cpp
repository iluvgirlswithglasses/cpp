#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int N = 2007;
int n, a[N];

int calc() {
	
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		cout << calc() << "\n";
	}
	//
	return 0;
}
