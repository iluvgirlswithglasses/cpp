
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 10 16:06:46 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <string>
using namespace std;

const int N = 103;
int n, a[2][N];

string calc() {
	for (int i = 0; i < n; i++) {
		if (a[0][i] == 1 && a[1][i] == 1)
			return "NO";
	}
	return "YES";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			string s; cin >> s;
			for (int j = 0; j < n; j++)
				a[i][j] = s[j] - '0';
		}
		//
		cout << calc() << "\n";
	}
	return 0;
}

