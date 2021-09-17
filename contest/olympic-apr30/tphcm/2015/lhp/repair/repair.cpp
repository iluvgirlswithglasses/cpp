// oh yes
// the references.traffics
#include <bits/stdc++.h>
using namespace std;

//
int n, m;
int ** cost;

//
void calc() {

}

void getinp() {
	ifstream inp("repair.inp");
	inp >> n >> m;
	cost = new int*[n];
	for (int i = 0; i < n; i++) {
		cost[i] = new int[m];
		for (int j = 0; j < m; j++) {
			int a; inp >> a;
			if (a == -1) {
				cost[i][j] = INT_MAX;
			} else {
				cost[i][j] = a;
			}
		}
	}
}

// debugs
void printmat(int ** mat) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == INT_MAX) {
				cout << "- ";
			} else {
				cout << mat[i][j] << " ";
			}
		} cout << endl;
	} cout << endl;
}

int main() {
	getinp();
	printmat(cost);
	//
	getchar();
	return 0;
}
