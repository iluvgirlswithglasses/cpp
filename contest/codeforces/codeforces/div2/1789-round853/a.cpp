
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Mar  2 16:18:34 2023
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

int gcd(int a, int b) {
	if (a < b) swap(a, b);	// assert a > b
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

const int N = 107, I = 1e6+7;
int n, a[N];

bool calc() {
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (gcd(a[i], a[j]) <= 2) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		if (calc()) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}
