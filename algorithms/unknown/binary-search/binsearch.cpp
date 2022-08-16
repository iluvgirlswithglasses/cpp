
#include <iostream>
using namespace std;

//
int n, arr[(int) 1e3];
int a, b;

// given an increasing array arr
// find the largest number that <= k
int f(int k) {
	// [l:r)
	int l = 0, r = n+1;
	while (l < r) {
		int m = (l + r + 1) >> 1;	// to right
		if (arr[m] <= k)
			l = m;
		else
			r = m-1;
	}
	return arr[l];
}

// given an increasing array arr
// find the smallest number that >= k
int g(int k) {
	// (l:r]
	int l = 0, r = n+1;
	while (l < r) {
		int m = (l + r) >> 1;		// to left
		if (arr[m] >= k)
			r = m;
		else
			l = m+1;
	}
	return arr[r];
}


int main() {
	// getinp
	cin >> n;
	for (int i = 1; i <= n; i++) {
		arr[i] = i*4 + 1;
		cout << arr[i] << " ";
	}
	cout << "\n";
	cin >> a >> b;
	arr[0] = (int) -1e3;
	arr[n+1] = (int) 1e3;
	//
	cout << f(a) << "\n";
	cout << g(b) << "\n";
	return 0;
}
