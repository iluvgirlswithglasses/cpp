
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Feb 22 14:46:51 2023
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

const int N = 2e5+7, I = 1e9+7, R = 1e9+7;
int x, y;
int n, a[N];

void calc() {
	n = (x - y) << 1;
	if (n == 2) {
		a[0] = x;
		a[1] = y;
		return;
	}

	int i = 0;
	for (int v = x; v > y; v--)
		a[i++] = v;
	for (int v = y; v < x; v++)
		a[i++] = v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> x >> y;
		calc();
		cout << n << "\n";
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}
