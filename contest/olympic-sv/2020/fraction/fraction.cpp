#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

#define key first
#define val second

const int p[] = {
	2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997, 1009,
};
const int N = 1e5+7;
int n, a[N], b[N];

void fact(int n, int k, unordered_map<int, int> &f) {
	//
	for (int i = 0; p[i] * p[i] <= n; i++) {
		int quan = 0;
		while (n % p[i] == 0) {
			n /= p[i];
			quan++;
		}
		if (quan > 0) {
			if (f.find(p[i]) == f.end()) f[p[i]] = 0;
			f[p[i]] += quan*k;
		}
	}
	if (n > 1) {
		if (f.find(n) == f.end()) f[n] = 0;
		f[n] += k;
	}
}

string calc() {
	unordered_map<int, int> f;
	for (int i = 0; i < n; i++) {
		fact(a[i], 1, f);
		fact(b[i], -1, f);
	}
	f.erase(2); f.erase(5);
	//
	for (pair<const int, int> &i: f) {
		if (i.val < 0) return "repeating";
	}
	return "finite";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		cout << calc() << "\n";
	}
	return 0;
}
