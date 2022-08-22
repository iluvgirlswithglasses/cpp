#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main() {
	for (int i = 0; i < 18; i++) {
		lli res = 1;
		res *= pow(10, i);
		cout << res << " ";
	} cout << endl;
	//
	getchar();
	return 0;
}
