
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Dec 13 17:54:13 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * @ vars
 * */
const int N = 102;
int n, m, q;
vector<string> a;
string mat[N];

/**
 * @ perf
 * */
string flip(string& s) {
	string res;
	for (int i = s.length()-1; i >= 0; i--)
		res = res + s[i];
	return res;
}

void gen_a() {
	// hor
	for (int r = 0; r < n; r++)
		a.push_back(mat[r]);
	// ver
	for (int c = 0; c < m; c++) {
		string s;
		for (int r = 0; r < n; r++)
			s = s + mat[r][c];
		a.push_back(s);
	}
	// dia lr
	for (int r = 0; r < n; r++) {
		string s;
		for (int t = r, l = 0; t < n && l < m; t++, l++)
			s = s + mat[t][l];
		a.push_back(s);
	}
	for (int c = 0; c < m; c++) {
		string s;
		for (int t = 0, l = c; t < n && l < m; t++, l++)
			s = s + mat[t][l];
		a.push_back(s);
	}
	// dia rl
	for (int row = 0; row < n; row++) {
		string s;
		for (int t = row, r = m-1; t < n && r >= 0; t++, r--) 
			s = s + mat[t][r];
		a.push_back(s);
	}
	for (int c = 0; c < m; c++) {
		string s;
		for (int t = 0, r = c; t < n && r >= 0; t++, r--) 
			s = s + mat[t][r];
		a.push_back(s);
	}
	// flip
	int pre = a.size();
	for (int i = 0; i < pre; i++)
		a.push_back(flip(a[i]));
}

const char* find(string& s) {
	for (string& i: a) {
		if (i.find(s) != string::npos) return "YES";
	}
	return "NO";
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	a.reserve(2000);
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		cin >> mat[i];
	gen_a();
	while (q--) {
		string s; cin >> s;
		cout << find(s) << "\n";
	}
	return 0;
}
