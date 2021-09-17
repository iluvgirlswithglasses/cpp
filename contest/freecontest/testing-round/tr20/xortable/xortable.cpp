/*
a^b=x -> a^x=b
a^c=y -> a^y=c
--> b^c = a^x^a^y = x^y
*/

#include <iostream>
using namespace std;

const int N = 102;
int n, a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << (a[i]^a[j]) << " ";
		} cout << "\n";
	}
	return 0;
}
