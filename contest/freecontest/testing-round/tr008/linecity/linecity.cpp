#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+7;
int n, l, a[N], res;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> l >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a+n);
	//
	res = max(a[0], l-a[n-1]);
	for (int i = 1; i < n; i++)
		res = max(res, (a[i] - a[i-1]) >> 1);
	//
	cout << res << "\n";
	return 0;
}
