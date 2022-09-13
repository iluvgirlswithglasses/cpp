
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep 13 10:26:15 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
using namespace std;

const int N = 307;
int n, m, a[N];
set<int> res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	n += 2;	// a[n-1] = a[n-2] = 0
	for (int i = 0; i < n; i++)
	for (int j = i+1; j < n; j++)
	for (int k = j+1; k < n; k++)
		if (a[i] + a[j] + a[k] <= m) res.insert(a[i] + a[j] + a[k]);
	cout << res.size() << "\n";
	return 0;
}
