
/*
cực tiểu loại 2
--> cực đại loại 1
*/

#include <iostream>
#include <string>
using namespace std;

const int N = 2e5+7;
int n, k, a[N], c[3];
string s;

bool check() {
	for (int i = 0; i < 3; i++)
		if (c[i] < k) return false;
	return true;
}

int sum() {
	int s = 0;
	for (int i = 0; i < 3; i++)
		s += c[i];
	return s;
}

int calc() {
	int res = N;
	for (int l = 0, r = 0; r < n; r++) {
		c[a[r]]++;
		if (check()) {
			while (check()) {
				c[a[l++]]--;
			}
			c[a[--l]]++;
			res = min(res, sum() - k*3);
		}
	}
	if (res == N) 
		return -1;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k >> s;
	for (char &c: s) {
		int i;
		switch (c) {
			case 'V': i=0; break;
			case 'C': i=1; break;
			case 'A': i=2; break;
		}
		a[n++] = i;
	}
	cout << calc() << "\n";
	return 0;
}
