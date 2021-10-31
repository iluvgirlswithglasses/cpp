#include <bits/stdc++.h>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second

/**
 * eratos
 * */
const long long I = 1e6+7;
bool er[I];	// er[i] == true --> er[i] isn't prime

bool is_prime(int i) {
	return !er[i];
}

void eratosthenes() {
	er[0] = true;
	er[1] = true;
	for (int i = 2; i < I; i++) {
		if (!er[i]) {
			for (long long j = (long long) i * i; j < I; j+=i) {
				er[j] = true;
			}
		}
	}
}

/**
 * 
 * */
const int N = 1e6+7;
int n, x, a[N], pc[N];	// pc[]: prime count

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	eratosthenes();
	cin >> n >> x;
	//
	int c = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 0) {
			if (is_prime(a[i]) && a[i] <= x) {
				c++;
			}
		}
		pc[i] = c;
	}
	//
	int best = 0;
	if (c > 1) {
		best = n;
		for (int i = 1, j = i+c-1; j <= n; i++, j++) {
			best = min(best, c - (pc[j] - pc[i-1]));
		}
	}
	cout << best << "\n";
	return 0;
}
