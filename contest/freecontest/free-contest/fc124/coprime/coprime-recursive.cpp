
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int I = 1e6+7, p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997,};
long long res, c[I];

/**
 * utils
 * */
vector<int> fact(int n) {
	vector<int> r;
	for (int i = 0; p[i] * p[i] <= n; i++) {
		if (n % p[i] == 0) 
			r.push_back(p[i]);
		while (n % p[i] == 0) 
			n /= p[i];
	}
	if (n > 1)
		r.push_back(n);
	return r;
}

/**
 * calc
 * */
void recursion(int t, vector<int> &f, vector<bool> &bs) {
	if (bs.size() == f.size()) {
		int k = 1;
		for (int i = 0; i < f.size(); i++) {
			if (bs[i]) k *= f[i];
		}
		//
		if (t == 1) {
			if (count(bs.begin(), bs.end(), 1) & 1) {
				res -= c[k];
			} else {
				res += c[k];
			}
			c[k]++;
		} else {
			c[k]--;
			if (count(bs.begin(), bs.end(), 1) & 1) {
				res += c[k];
			} else {
				res -= c[k];
			}
		}
	} else {
		for (int i = 0; i <= 1; i++) {
			bs.push_back(i);
			recursion(t, f, bs);
			bs.pop_back();
		}
	}
}

/**
 * drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int t, x; cin >> t >> x;
		vector<int> f = fact(x);
		vector<bool> bs;
		recursion(t, f, bs);
	    cout << res << "\n";
	}
	return 0;
}

