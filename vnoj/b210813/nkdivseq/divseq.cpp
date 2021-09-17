#include <iostream>
using namespace std;

const int N = 1e5+7;
int n, a[N];
int main() {
	cin >> n;
	//
	if ( n == 1 ) {
		cout << 1 << endl;
	} else {
		int k = (int) ceil((sqrt(1+8*n)-1)/2);
		//
		n -= (k-1)*k/2; 
		int res = 1;
		for (int i = 2; i < k; i++) 
			res = (res/i+i) * i;
		res = (res/k+1)*k;
		cout << res + (n-1)*k << endl;
	}
	//
	system("pause");
	return 0;
}
