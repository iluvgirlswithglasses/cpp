
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Mar  6 13:25:51 2023
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

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n, s[N];

ll calc() {
	ll ans = 0;
	multiset<int> st;
	for (int i = 0; i < n; i++) {
		if (s[i] == 0) {
			if (st.size()) {
				multiset<int>::iterator itr = --st.end();
				ans += *itr;
				st.erase(itr);	
			}
		} else {
			st.insert(s[i]);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> s[i];
		cout << calc() << '\n';
	}
	return 0;
}
