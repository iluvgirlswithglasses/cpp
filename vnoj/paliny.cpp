
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct  6 18:43:59 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// about this palindrome algorithm:
// https://cp-algorithms.com/string/manacher.html

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;

// only detect odd-length palindromes
vector<int> __manacher(string s) {
	int n = s.length();
	// advoid dealing with ends of the string separately
	// btw this is "regexly" correct
	s = "^" + s + "$";
	// `d[i]`: half the length of the palindrome that centers around `i`, including itself
	// so if `d[i] == 2`, it means there's a palindrome with length `2*2 - 1` centered at `i`
	vector<int> d(n+2);
	int l = 1, r = 1;
	for (int i = 1; i <= n; i++) {
		d[i] = max(0, min(
			r-i, d[l + (r-i)]
		));
		while (s[i - d[i]] == s[i + d[i]])
			d[i]++;
		if (i + d[i] > r)
			l = i - d[i], r = i + d[i];
	}
	return d;
}

int manacher(string s) {
	string t;
	for (char c: s)
		t += string(".") + c;
	// d[0] and d[-1] are anchor characters "^" and "$"
	// d[2n+1] are escape characters, currently set to "."
	// real characters presented in string `s`
	vector<int> d = __manacher(t + '.');
	return *max_element(d.begin() + 1, d.end() - 1) - 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	cout << manacher(s) << "\n";
	return 0;
}
