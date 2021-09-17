#include <iostream>
#include <vector>
using namespace std;

vector<int> seq;

void gen(int k) {
	for (int i = 1; k > 0; i++) {
		if (i%3 == 0 || i%10 == 3) continue;
		seq.push_back(i); k--;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	gen(1001);
	//
	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		cout << seq[--k] << "\n";
	}
	return 0;
}
