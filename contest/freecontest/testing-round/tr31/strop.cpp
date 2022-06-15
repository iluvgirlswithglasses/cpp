
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Jun 15 22:12:05 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
move 1:
	rm 1 char, add 2 adjacent chars of the other letter --> d = 3
move 2:
	rm 3 adjacent chars of a same letter --> d = 3


aab -> aaaa -> bbaaa -> baaaaa -> baa
                     -> bbbbaa
baa
baaaaa
bbbbaa

given 2 strings with a same letter different mod 3 ((cntA - cntB) % 3)
there's always a way to transform from one to another
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
const int C3 = 300000;
const int N  = 1e5+7;

int q;
string s, t;
int sa[N], sb[N], ta[N], tb[N];

void add(string &s, int *sa, int *sb) {
	for (int i = 0; i < s.length(); i++) {
		sa[i+1] = sa[i];
		sb[i+1] = sb[i];
		if (s[i] == 'A') sa[i+1]++;
		if (s[i] == 'B') sb[i+1]++;
	}
}

const char* query(int ls, int rs, int lt, int rt) {
	int ds = (sa[rs] - sa[ls-1]) - (sb[rs] - sb[ls-1]) + C3,
	    dt = (ta[rt] - ta[lt-1]) - (tb[rt] - tb[lt-1]) + C3;
	if ((ds % 3) == (dt % 3))
		return "YES";
	return "NO";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s >> t;
	add(s, sa, sb);
	add(t, ta, tb);
	// query
	cin >> q;
	while (q--) {
		int l, r, x, y;
		cin >> l >> r >> x >> y;
		cout << query(l, r, x, y) << "\n";
	}
	return 0;
}
