#include <iostream>
using namespace std;

typedef long long ll;

/*
AAA
ABA
BAB
BBB
*/

int x, y;

ll nPk(int n, int k) {
	ll res = 1;
	for (int i = n; i >= n-k+1; i--)
		res *= i;
	return res;
}

ll only_a() {
	return nPk(x, 3);
}

ll one_b() {
	return only_a() + nPk(x, 2);
}

ll two_b() {
	return only_a() + (nPk(x, 2) << 1) + (x << 1);
}

ll worst_shit() {
	return nPk(x, 3) 
		 + nPk(x, 2) * y
		 + nPk(y, 2) * x
		 + nPk(y, 3);
}

ll calc() {
	if (x < 2 && y < 2) {
		return 0l;
	}
	if (x == 2 && y == 1) {
		return 2l;
	}
	if (x == 2 && y == 2) {
		return 8l;
	}
	switch (y) {
		case 0: return only_a();
		case 1: return one_b();
		case 2: return two_b();
	}
	return worst_shit();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> x >> y;
		if (y > x) swap(x, y);
		cout << calc() << "\n";
	}
	return 0;
}
