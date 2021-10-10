#include <iostream>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int s; cin >> s;
		for (int i = 1; i < n; i++) {
			int v; cin >> v;
			s &= v;
		}
		cout << s << endl;
	}
	return 0;
}
