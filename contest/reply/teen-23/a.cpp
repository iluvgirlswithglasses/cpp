
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Mar  9 22:31:37 2023
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

const int R = 1e4+7, N = 502, I = 1004;
// speed, turbo speed, cooldown, duration
int n, r, s[N], t[N], c[N], d[N];

int calc() {
	int ans = 0;
	double time = R;

	for (int i = 0; i < n; i++) {
		int travel = 0, consumed = 0;

		while (travel < r) {

			// turbo
			if (travel + t[i]*d[i] < r) {
				travel += t[i]*d[i];
				consumed += d[i];
			} else {
				int need = r - travel;
				consumed += (need + t[i] - 1) / t[i];
				break;
			}

			// normal
			if (travel + s[i]*c[i] < r) {
				travel += s[i]*c[i];
				consumed += c[i];
			} else {
				int need = r - travel;
				consumed += (need + s[i] - 1) / s[i];
				break;
			}
		}

		if (consumed < time) {
			time = consumed;
			ans = i;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	for (int te = 1; te <= tt; te++) {
		cin >> r >> n;
		for (int i = 0; i < n; i++) {
			int id; cin >> id;
			cin >> s[id] >> t[id] >> c[id] >> d[id];
		}

		cout << "Case #" << te << ": ";
		cout << calc() << "\n";
	}
	return 0;
}
