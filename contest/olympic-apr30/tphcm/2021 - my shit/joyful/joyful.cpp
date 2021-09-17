// bruh I swear to god if I had known this...
// fk this shouldn't had been a hard question
#include <bits/stdc++.h>
using namespace std;

//
vector<int*> arrH;
vector<int*> arrV;
const int AX = 0;
const int AY = 1;
const int BX = 2;
const int BY = 3;

// utils
bool is_h(int * line) {
	return line[AY] == line[BY];
}

bool is_cross(int * h, int * v) {
	return h[AX] <= v[AX] && v[AX] <= h[BX] &&
		   v[AY] <= h[AY] && h[AY] <= v[BY];
}

//
int calc() {
	int counts = 0;
	//
	for (int * i: arrH) {
		for (int * j: arrV) {
			if (is_cross(i, j)) counts += 1;
		}
	}
	//
	return counts;
}

//
void getinp() {
	ifstream inp("joyful.inp") ;
	int n; inp >> n;
	for (int i = 0; i < n; i++) {
		int ax, ay, bx, by; inp >> ax >> ay >> bx >> by;
		// min & max: swap a and b in cases so that they won't mess is_cross() up
		int * temp = new int[4]{
			min(ax, bx), 
			min(ay, by), 
			max(ax, bx), 
			max(ay, by)
		};
		if (is_h(temp)) {
			arrH.push_back(temp);
		} else {
			arrV.push_back(temp);
		}
	}
}

int main() {
	getinp();
	cout << calc();
	//
	// getchar();
	return 0;
}
