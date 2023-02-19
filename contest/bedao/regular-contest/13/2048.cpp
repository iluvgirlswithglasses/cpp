
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

ll     int_tb[N];
string str_tb[N];

void gen_tb() {
	for (ll i = 0; i < N; i++) {
		int_tb[i] = i * 2048ll;

		string str = to_string(int_tb[i]);
		str_tb[i] = string(11 - str.length(), '0') + str;
	}
}

/**
 * @ utils
 * */
ll get_max(string &t) {
	string ans = string(t.length(), '9');
	for (int i = 0; i < t.length(); i++)
		if (t[i] != '?') ans[i] = t[i];
	return stoll(ans);
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
	ll mx  = get_max(t);
	vector<pi> pos = get_pos(t);
	for (int i = 0; i < N && int_tb[i] <= mx; i++)
		if (check(str_tb[i], pos)) cnt++;
	return cnt;
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	gen_tb();
	//
	string s, t;
	cin >> s;
	if (s.length() <= 12) {
		cout << tail_check(s) << "\n";
	} else {
		t = s.substr(s.length() - 12, 12);
		s = s.substr(0, s.length() - 12);
		ll ans = head_check(s) * tail_check(t) % R;
		cout << ans << "\n";
	}
	return 0;
}
