#include <bits/stdc++.h>
using namespace std;

#define lli long long int

//
int n;
int * arrM;		// 
int * arrX;		// 

// utils
int calc_lim(int pre, int cr) {
	// this function return the last index you can travel after 'nxt' index
	int d = arrX[cr] - arrX[pre];
	int lim = cr;
	for (int i = cr + 1; i < n; i++) {
		if (arrX[i] - arrX[cr] <= d) {
			lim += 1;
		} else {
			break;
		}
	}
	// printf("%d -> %d, d=%d, lim=%d\n", pre, cr, d, lim);
	return lim;
}

//
bool recursion(int cr, int lim, int res, int & best) {
	// cout << cr << "\n";
	if (cr == n - 1) {
		best = max(res, best);
		return true;
	}
	res += arrM[cr];
	//
	bool hasChild = false;
	// better make it decending
	// if a long path doesn't work => short path neither
	for (int i = min(n - 1, lim); i > cr; i--) {
		int clim = calc_lim(cr, i);
		if (clim != cr) {
			if (recursion(i, clim, res, best)) {
				hasChild = true;
			} else {
				break;
			}
		}
	}
	//
	return hasChild;
}

int recursion() {
	int best = 0;
	recursion(0, n-1, 0, best);
	return best;
}

// debug
void printarr(int * arr) {
	for (int i = 0; i < n; i++) cout << arr[i] << " "; cout << endl << endl;
}

//
void getinp() {
	ifstream inp("prince.inp");
	inp >> n; n += 2;
	arrX = new int[n]; arrM = new int[n]; 
	//
	arrM[0] = 0; arrX[0] = 0;
	for (int i = 0; i < n - 2; i++) {
		inp >> arrX[i+1];
		inp >> arrM[i+1];
	}
	//
	inp >> arrX[n-1];
	arrM[n-1] = 0;
}

int main() {
	getinp();
	cout << recursion();
	//
	getchar();
	return 0;
}
