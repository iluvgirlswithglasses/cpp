
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Mar  1 10:39:18 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e3+7, I = 1e9+7, R = 1e9+7;
int n, a[N], p[N], s[N];

int check() {
	for (int k = 0; k < n-1; k++)
		if (p[k] == s[k+1])
			return k + 1;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		p[0]   = a[0]   == 2;
		s[n-1] = a[n-1] == 2;
		for (int i = 1; i < n; i++) 
			p[i] = p[i-1] + (a[i] == 2);
		for (int i = n-2; i >= 0; i--)
			s[i] = s[i+1] + (a[i] == 2);
		cout << check() << "\n";
	}
	return 0;
}
