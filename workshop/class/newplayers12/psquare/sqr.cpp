#include <iostream>
using namespace std;

#define u64 unsigned long long
const u64 R = 2017;
u64 n, nr;

u64 mod(u64 i) {
	return i % R;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n; nr = mod(n);
	// S = n * (1 + n^2) / 2
	u64 s = mod( nr * (1 + mod(nr*nr)) / 2 );
	//
	cout << s << "\n";
	return 0;
}
