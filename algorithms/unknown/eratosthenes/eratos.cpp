
#include <iostream>
using namespace std;

#define ll long long

struct Eratos {

	static const int I = 1e7+7;

	int  n, cnt;
	int  p[Eratos::I];	// p[i] == the i-th prime
	bool e[Eratos::I];	// e[i] == 0 --> `i` is prime

	void init(int _n) {
		n = _n;
		e[0] = e[1] = true;
		for (ll i = 2; i <= n; i++) if (!e[i]) {
			p[cnt++] = i;
			for (ll j = i*i; j <= n; j+=i) e[j] = true;
		}
	}

	bool is_prime(int x) {
		return !e[x];
	}

} er;

int main() {
	cin.tie(0)->sync_with_stdio(false);
	int n; cin >> n;
	er.init(n);
	cout << "number of primes in [0:n]: " << er.cnt << "\n";
	for (int i = 0; i < er.cnt; i++)
		cout << er.p[i] << ", ";
	cout << "\n";
	return 0;
}
