#include <iostream>
#include <string>
using namespace std;


/**
 * utils
 * */
#define ll long long
const char h[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', };

void to_upper(string &s) {
	for (char &c: s)
		if ('a' <= c && c <= 'z') c = c - 'a' + 'A';
}

ll apb(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	return a * apb(a, b-1);
}

ll cval(char c) {
	int i = c;
	if ('0' <= i && i <= '9') return i - '0';
	if ('A' <= i && i <= 'F') return i - 'A' + 10;
	return -1;
}

ll h2d(string &h) {
	ll r = 0;
	for (int i = 0, j = h.length()-1; i < h.length(); i++, j--) {
		r += apb(16, j) * cval(h.at(i));
	}
	return r;
}

/**
 * drivers
 * */
string a, b;
ll ad, bd;

ll calc_x2y() {
	ll r = ad%9;
	for (ll i = ad+1; i <= bd; i++)
		r = (r + (i%9)) % 9;
	return r;
}

char calc() {
	if (ad == 0) return '0';
	//
	ll s = calc_x2y();
	
	return h[s];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b; 
	to_upper(a); to_upper(b);
	ad = h2d(a); bd = h2d(b);
	cout << calc() << "\n";
	return 0;
}
