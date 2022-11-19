
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 19 14:00:58 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
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

const int N = 102, I = 1e9+7, R = 1e9+7;
int n, a[N], p[N];

int calc() {
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		memset(p, 0, (n+1) * sizeof(p[0]));
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n, [](int a, int b){ return a > b; });
		//
		for (int i = n-1; i >= 0; i--)
			p[i] = a[i] + p[i+1];
		//
		int s = 0;
		for (int i = 0; i < n-2; i++) {
			if (a[i] < p[i+1]) {
				s = p[i];
				break;
			}
		}
		cout << s << "\n";
	}
	return 0;
}
