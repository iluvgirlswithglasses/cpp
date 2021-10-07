// given an increasing array arr
// find the smallest number that is bigger than k

#include <iostream>
using namespace std;

//
int n, arr[(int) 1e3];
int k;

//
int search(int k) {
	// [l:r)
	int l = 0, r = n;
	while (l < r - 1) {
		int m = (l + r) >> 1;
		if (arr[m] >= k) {
			r = m;
		} else {
			l = m;
		}
	}
	// change this into arr[l+1] to find the biggest number that is smaller than k
	return arr[l];
}


int main() {
	// getinp
	cin >> n >> k;
	for (int i = 0; i < n; i++) arr[i] = i*4 + 1;
	arr[n] = (int) 1e3;
	//
	cout << search(k) << endl;
	// returns
	system("pause");
	return 0;
}
