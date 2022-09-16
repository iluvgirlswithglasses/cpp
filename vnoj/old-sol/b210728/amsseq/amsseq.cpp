#include <algorithm>
#include <iostream>
using namespace std;

//@ vars
const int nlim = 1e4;
const int alim = 1e3+1;
int n, k, arr[nlim];


//@ drivers
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		int pre = i - k; pre = max(pre, 0);
		arr[i] = arr[pre] + a;
		//
		for (int j = pre + 1; j < i; j++) {
			arr[i] = max(arr[i], arr[j] + a);
		}
	}
	cout << *max_element(arr, arr+n+1) << endl;
	// 
	system("pause");
	return 0;
}
