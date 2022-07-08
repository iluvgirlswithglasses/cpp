
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Jul  8 20:11:20 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
using namespace std;

/*
number of removals == number of block of opening brackets
*/

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<const int, int>
#define st first
#define nd second

const int N = 1e5+7;
int n, q;
char s[N];
// `p[i]` returns the nearest closing bracket of the opening bracket `i` or its block
// if `i` is not an opening bracket, or it does not have a closing bracket, `p[i]` returns `0`
int p[N];
// `m[i]` returns `j` that `[i:j)` is a block of opening brackets that has an ending bracket
// in other words, it contains the indexes of continuous non-zero values of `p[]`
map<int, int> m;
int idx[N];	// `idx[i]` return the id of the corresponding 'opening brackets block'

// this is [l:r)
int calc(int l, int r) {
	map<int, int>::iterator ss = m.lower_bound(l), sp = ss;
	if (sp != m.begin() && (--sp)->nd > l) 
		ss = sp;
	if (ss == m.end())
		return 0;
	//
	map<int, int>::iterator se = m.lower_bound(r);
	if (se == m.begin()) return 0;
	if ((--se)->nd >= r) {
		if (se == m.begin()) return 0;
		se--;
	}
	//
	return idx[se->st] - idx[ss->st] + 1;
}

void inp() {
	// simple stuffs
	cin >> n >> q;
	cin >> s;
	int closest = 0;
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == ')')
			closest = i;
		else
			p[i] = closest;
	}
	// generating `m[]` and `idx[]`
	bool opening = false;
	int  cr_opening;
	int  block_cnt = 0;
	for (int i = 0; i <= n; i++) {
		if (p[i] > 0) {
			if (!opening) {
				cr_opening = i;
				opening = true;
				idx[i] = ++block_cnt; 
			} else {
				idx[i] = block_cnt;
			}
		} else if (p[i] == 0 && opening) {
			m[cr_opening] = i;
			opening = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	inp();
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << calc(--l, r) << "\n";
	}
	return 0;
}
