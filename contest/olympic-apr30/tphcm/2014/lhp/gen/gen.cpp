#include <bits/stdc++.h>
using namespace std;
ifstream inp("gen.inp");

//
vector<int> a;
vector<int> b;

//
int subs() {
	int ** mat = new int*[a.size() + 1];
	for (int i = 0; i < a.size() + 1; i++) 
		mat[i] = new int[b.size() + 1];
	//
	for (int i = 0; i < a.size() + 1; i++) {
		for (int j = 0; j < a.size() + 1; j++) {
			if (i == 0 || j == 0) {
				mat[i][j] = 0;
				continue;
			}
			if (a[i-1] == b[j-1]) {
				mat[i][j] = mat[i-1][j-1] + 1;
			} else {
				mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
			}
		}
	}
	return mat[a.size()][b.size()];
}

// utils
bool condition_a(int n) {
	// nếu là bình phương một số nguyên
	double intpart = 1.0;
	return modf(sqrt(n), &intpart) == 0.0;
}

bool condition_b(int n) {
	double intpart = 1.0;
	double r = pow(n, 1.0/3.0);
	if (modf(r, &intpart) != 0.0) return false;	// not int
	//
	if (r < 2.0) return false;
	if (r == 2.0) return true;
	for (int i = 2; i < r / 2; i++) {
		intpart = (double) i;
		if (modf(r, &intpart) == 0.0) return false;
	}
	return true;
}

bool check(int n) {
	return condition_a(n) || condition_b(n);
}

//
void getarr(int k, vector<int> & v) {
	for (int i = 0; i < k; i++) {
		int n; inp >> n;
		if (check(n)) v.push_back(n);
	}
}

void getinp() {
	int n, m; inp >> n >> m;
	getarr(n, a); getarr(m, b);
}

void printarr(vector<int> & arr) {
	for (int i: arr) cout << i << " "; cout << endl;
}

int main() {
	getinp();
	cout << subs();
	//
	getchar();
	return 0;
}
