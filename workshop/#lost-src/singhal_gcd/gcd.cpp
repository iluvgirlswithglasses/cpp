// https://codeforces.com/gym/102767/problem/C
 
#include <iostream>
#include <vector>
using namespace std;
 
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
 
const int N = 1e5+7;
int n, a[N];
 
void calc() {
	int r = 1, l = n;
	vector<int> pos;
	for (int i = 1; i < n; i++) {
		int cr = gcd(a[i-1], a[i]);
		if (cr > r) {
			pos.clear();
			r = cr;
		} 
		if (cr >= r) {
			pos.push_back(i);
		}
	}
	if (r > 1) {
		int consec = 2; l = 2;
		for (int i = 1; i < pos.size(); i++) {
			if (pos[i] - pos[i-1] == 1) {
				consec++;
				l = max(l, consec);
			} else {
				consec = 2;
			}
		}
	}
	cout << r << " " << l << "\n";
}
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		calc();
	}
	return 0;
}