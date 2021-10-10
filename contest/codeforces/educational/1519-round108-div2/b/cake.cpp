#include <iostream>
using namespace std;

//
int calc_cost(int n, int m) {
	int m_cost = n * (m - 1);
	//
	return (n - 1) + m_cost;
}

int main() {
	int t; cin >> t;
	while (t--) {
		// another joke
		int n, m, k; cin >> n >> m >> k;
		// just the same as steps count from (1, 1) -> (n, m)
		// nothing new
		if (
			calc_cost(n, m) == k
		) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
	}
	//
	return 0;
}
