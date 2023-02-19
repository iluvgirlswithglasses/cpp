
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Feb 17 16:29:32 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

// basically 1e11 % 2048 == 0
// calculate 10^x / 2046 into a / b and you'll notice the pattern of `b`

#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, char> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const ll R = 1e9+9, N = 48828125;

/**
 * @ utils
 * */
ll get_max(string &t) {
	string ans = string(t.length(), '9');
	for (int i = 0; i < t.length(); i++)
		if (t[i] != '?') ans[i] = t[i];
	return stoll(ans);
}

ll get_min(string &t) {
	string str = string(t.length(), '0');
	for (int i = 0; i < t.length(); i++)
		if (t[i] != '?') str[i] = t[i];
	ll ans = stoll(str);
	return (ans / 2048) * 2048;
}

vector<pi> get_pos(string &t) {
	vector<pi> res;
	for (int i = 0; i < t.length(); i++)
		if (t[i] != '?') res.push_back({i, t[i]});
	return res;
}

bool check(string &s, vector<pi> &pos) {
	for (pi &p: pos)
		if (s[p.st] != p.nd) return false;
	return true;
}

ll head_check(string &s) {
	ll ans = 1ll;
	for (char c: s)
		if (c == '?') ans = ans * 10 % R;
	return ans;
}

ll tail_check(string &t) {
	ll cnt = 0;
	ll mn = get_min(t), mx = get_max(t);
	vector<pi> pos = get_pos(t);
	
	for (; mn <= mx; mn += 2048) {
		string s = to_string(mn);
		s = string(11 - s.length(), '0') + s;
		if (check(s, pos)) cnt++;
	}
	return cnt;
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s, t;
	cin >> s;
	if (s.length() <= 12) {
		if (s[0] == '?') {
			ll cnt = 0;
			for (char c = '1'; c <= '9'; c++) {
				s[0] = c;
				string candidate = string(11 - s.length(), '0') + s;
				cnt += tail_check(candidate);
			}
			cout << cnt << "\n";
		} else {
			s = string(11 - s.length(), '0') + s;
			cout << tail_check(s) << "\n";
		}
	} else {
		t = s.substr(s.length() - 11, 11);
		s = s.substr(0, s.length() - 11);
		ll ans = head_check(s) * tail_check(t) % R;
		cout << ans << "\n";
	}
	return 0;
}
