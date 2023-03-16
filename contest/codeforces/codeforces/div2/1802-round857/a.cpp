
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Mar 16 17:48:09 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<const int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 104;
int n, b[N];

void calc_max(vector<int> &once, vector<int> &twice) {
	int likes = 0;
	for (int i: once) cout << ++likes << " ";
	for (int i: twice) cout << ++likes << " ";
	for (int i: twice) cout << --likes << " ";
	cout << "\n";
}

void calc_min(vector<int> &once, vector<int> &twice) {
	int likes = 0;
	for (int i: twice) cout << ++likes << " " << --likes << " ";
	for (int i: once) cout << ++likes << " ";
	cout << "\n";
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> b[i];

	map<int, int> cnt;
	for (int i = 0; i < n; i++) 
		cnt[abs(b[i])]++;
	vector<int> once;
	vector<int> twice;
	for (pi &p: cnt) {
		if (p.nd == 1) once.push_back(p.st);
		else twice.push_back(p.st);
	}

	calc_max(once, twice);
	calc_min(once, twice);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}
