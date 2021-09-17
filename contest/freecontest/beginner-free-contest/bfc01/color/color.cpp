#include <iostream>
using namespace std;
typedef long long ll;

const ll R = 1e9+7;
int n, k;

// calculate ((a**b) % R) real quick
ll fast_exponential(ll a, ll b) {
	if (b == 0) return 1l;
	if (b == 1) return a;
	if (b & 1) {
		// (b^1)>>1 == (b-1)/2
		ll tmp = fast_exponential(a, (b^1)>>1);
		return ( ((tmp * tmp) % R) * a ) % R;
	}
	// if b is even
	ll tmp = fast_exponential(a, b>>1);
	return (tmp * tmp) % R;
}

int main() {
	cin >> n >> k;
	// 
	ll a = 1, b = 1;
	// euler candy
	for (int i = n - k + 1; i >= n - (k<<1) + 2; i--)
		a = (a * i) % R;
	for (int i = 2; i <= k; i++) 
		b = (b * i) % R;
	// Fermat little theorem
	// b < a
	ll res = (a * fast_exponential(b, R-2)) % R;
	cout << res << endl;
	return 0;
}
