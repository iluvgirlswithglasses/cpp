#include <iostream>
using namespace std;

int main() {
	unsigned long long a, b; cin >> a >> b;
	//
	int diff = 0;
	for (int i = 64 - min(__builtin_clzll(a), __builtin_clzll(b)) - 1; i >= 0; i--) {
		if ((a>>i&1) != (b>>i&1)) diff++;
	}
	//
	if (diff&1) cout << "-1\n";
	else cout << (diff>>1) << "\n";
	return 0;
}
