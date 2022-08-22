#include <iostream>
using namespace std;

const int N = 1003;
int n, a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	//
	int r = 0;
	for (int i = 1; i < n; i++) 
		r = max(r, abs(a[i] - a[i-1]));
	for (int i = 2; i < n; i++) 
		r = max(r, abs(a[i] - a[i-2]));
	cout << r << "\n";
	return 0;
}
