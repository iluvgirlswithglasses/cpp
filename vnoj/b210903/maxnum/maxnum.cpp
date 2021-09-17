
// https://en.wikipedia.org/wiki/Legendre's_formula

#include <iostream>
using namespace std;

int n, p;

int legendre(int n, int p) {
    if (n < p) return 0;
    return n/p + legendre(n/p, p);
}

int legendre() {
    int res = 1e9+7;
    for (int i = 2; i <= p; i++) {
    	if (p % i == 0) {
	        int cr = 0;
	        while (p % i == 0) {
	            p /= i;
	            cr++;
	        }
	        res = min(res, legendre(n, i) / cr);
	    }
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> p;
    cout << legendre() << "\n";
    return 0;
}
