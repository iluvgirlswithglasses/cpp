
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Nov  1 17:11:02 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <bits/stdc++.h>
using namespace std;

#define ld long double
const ld PI = acos((ld)-1);

ld r, x;
ld ac, am, oq, cq, cp;
ld s_ach, s_cek, s_lb;

ld calc() {
	ac = 2 * r * sin(2 * PI / 5);
	am = ac * sin(PI / 5);
	oq = r * cos(PI / 5);
	cq = r * sin(PI / 5);
	cp = ac * cos(PI / 5);
	//
	s_ach = am * (ac + x) / 2;
	s_cek = am * cp;
	s_lb = (r * r * PI - 5 * oq * cq) / 5;
	return s_ach + s_cek + s_lb;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> r >> x;
		cout << setprecision(9) << fixed << calc() << "\n";
		//
		// printf("%Lf %Lf %Lf %Lf %Lf\n%Lf %Lf %Lf\n", ac, am, oq, cq, cp, s_ach, s_cek, s_lb);
	}
	return 0;
}

