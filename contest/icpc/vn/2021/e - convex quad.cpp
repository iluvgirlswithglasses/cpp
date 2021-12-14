
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Dec 14 19:29:47 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * @ defs
 * */
#define ls vector<int>
#define ll long long
#define ld long double

struct point {
	int x, y;
} p[4];

struct line {
	ld a, b, c;

	line(const point& pa, const point& pb) {
		a = pa.y - pb.y;
		b = pb.x - pa.x;
		c = - a*pa.x - b*pa.y;
	}

	ld at(const ld x) {
		//     ax + by + c == 0
		// --> y = (-ax-c)/b
		return (-x*a - c) / b;
	}

	ld intersect(const line& d) {
		// (+ax+c)/b = (+ix+k)/j
		ld e1 = a/b, e2 = c/b, e3 = d.a/d.b, e4 = d.c/d.b;
		return (e4 - e2) / (e1 - e3);
	}
};

int mod(int i) {
	return i % 4;
}

/**
 * @ geometry utils
 * */
bool intersect(point& a, point& b, point& c, point& d) {
	// check if f(a, b) intersect segment (c, d)
	line f(a, b), g(c, d);
	ld x = f.intersect(g), y = f.at(x);
	//
	ld minx = min(c.x, d.x), maxx = max(c.x, d.x),
	   miny = min(c.y, d.y), maxy = max(c.y, d.y);
	//
	return minx <= x && x <= maxx && 
	       miny <= y && y <= maxy;
}

/**
 * @ perf
 * */
bool complex(ls& v) {
	//
	for (int i = 0; i < 4; i++)
		if (intersect(
			p[ v[i] ], 
			p[ v[mod(i+1)] ], 
			p[ v[mod(i+2)] ], 
			p[ v[mod(i+3)] ]
		)) return true;
	return false;
}

bool perm(ls& v, ls& visited) {
	if (v.size() == 4) {
		if (!complex(v)) return true;
	}
	for (int i = 0; i < 4; i++) if (!visited[i]) {
		v.push_back(i);
		visited[i] = true;
		//
		if (perm(v, visited)) return true;
		//
		v.pop_back();
		visited[i] = false;
	}
	return false;
}

const char* calc() {
	ls v;
	ls visited(4, false);
	if (perm(v, visited)) return "YES";
	return "NO";
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		for (int i = 0; i < 4; i++)
			cin >> p[i].x >> p[i].y;
		cout << calc() << "\n";
	}
	return 0;
}
