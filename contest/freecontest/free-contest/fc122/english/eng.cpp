
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 07 11:40:32 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <bits/stdc++.h>
using namespace std;

double half_round(double i) {
	int a = (i + 0.25) * 2;
	return (double) a / 2;
}

double a, b, c, d, r;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> c >> d;
	//
	double r = half_round((a + b + c + d) / 4.0);
	cout << setprecision(1) << fixed << r << " ";
	//
	if (r >= 8.5) {
		cout << "C2\n";
	} else if (r >= 7.0) {
		cout << "C1\n";
	} else if (r >= 5.5) {
		cout << "B2\n";
	} else if (r >= 4.0) {
		cout << "B1\n";
	}
	return 0;
}

