
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 29 10:13:32 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <cstdio>
using namespace std;

/*
d(A, B) = |Ax - Bx| + |Ay - By|

--> d(A, B) = + Ax - Bx + Ay - By	or
              + Ax - Bx - Ay + By	or
              - Ax + Bx - Ay + By	or
              - Ax + Bx + Ay - By

--> d(A, B) = (Ax + Ay) - (Bx + By)	or
			  (Ax - Ay) - (Bx - By)	or
			  (Bx + By) - (Ax + Ay)	or
			  (Bx - By) - (Ax - Ay)

--> d(A, B) = |(Ax + Ay) - (Bx + By)|	or
			  |(Ax - Ay) - (Bx - By)|

with Ai = Ax + Ay, Aj = Ax - Ay,
	 Bi = Bx + By, Bj = Bx - By

--> d(A, B) = |Ai - Bi| or |Aj - Bj|

somehow I ran into rotation

*/

struct point {
	int x, y;

	void rotate() {
		int a = x, b = y;
		x = a + b;
		y = a - b;
	}
};

const int N = 2e5+7, I = 1e6+7;
int n;
point p[N];
int lx = I, ly = I, rx = -I, ry = -I;

/**
 * 
 * */

void upd(point & p) {
	lx = min(lx, p.x);
	ly = min(ly, p.y);
	rx = max(rx, p.x);
	ry = max(ry, p.y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i].x);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i].y);
	//
	for (int i = 0; i < n; i++) {
		p[i].rotate();
		upd(p[i]);
	}
	//
	for (int i = 0; i < n; i++) {
		int x = max(p[i].x - lx, rx - p[i].x);
		int y = max(p[i].y - ly, ry - p[i].y);
		printf("%d ", max(x, y));
	}
	printf("\n");
	return 0;
}

