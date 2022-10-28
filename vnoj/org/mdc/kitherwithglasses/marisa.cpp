
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 28 11:44:01 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e5+7;
const int ZERO = -1, NEG = 0, POS = 1;

int n;
int t[N];
ld  a[N];

int calc() {
	// result
	int rlen  = 0;
	ld  rbest = 0.0;
	// iteration
	// dp[0]: {max sum, start from}
	// while dp[1] is min sum
	vector<pi> dp(2, {0.0, N});

	for (int i = 0; i < n; i++) {
		// meet zero --> reset all
		if (t[i] == ZERO) {
			dp[0] = dp[1] = {0.0, N};
			continue;
		}
		// meet positive --> things get simple
		else if (t[i] == POS) {
			// create positive sequence if not exists
			dp[POS].nd = min(i, dp[POS].nd);
			// x*y is compressed into log(x) + log(y)
			dp[POS].st += a[i];
			// if exists a negative sequence --> update it
			if (dp[NEG].nd < N) dp[NEG].st += a[i];
		}
		// meet negative --> swapping things
		else if (t[i] == NEG) {
			swap(dp[0], dp[1]);
			dp[NEG].nd = min(i, dp[NEG].nd);

			dp[NEG].st += a[i];
			if (dp[POS].nd < N) dp[POS].st += a[i];
		}

		// update the result
		if (dp[POS].st > rbest) {
			rbest = dp[POS].st;
			rlen  = i - dp[POS].nd + 1;
		} else if (dp[POS].st == rbest) {
			rlen = max(rlen, i - dp[POS].nd + 1);
		}
	}

	return rlen;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			ll x; cin >> x;
			if (x < 0)
				t[i] = NEG, x = -x;
			else if (x == 0)
				t[i] = ZERO;
			else
				t[i] = POS;
			a[i] = log(x);
		}
		cout << calc() << "\n";
	}
	return 0;
}
