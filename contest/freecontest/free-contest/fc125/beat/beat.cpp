#include <bits/stdc++.h>
using namespace std;

#define lli long long int

//
const int limN = 102;
list<int> arr[limN][limN][limN];
int beat[3][limN];
//
int n; 

//
void iterateHandler(int i, int j, int k, list<int> & best, lli & bestVal) {
	// all equals
	if (beat[0][i-1] == beat[1][j-1] && beat[1][j-1] == beat[2][k-1]) {
		list<int> newD = arr[i-1][j-1][k-1];
		newD.push_back(beat[0][i-1]);

		lli crVal = 1;
		for (int a: newD) crVal *= (lli) a;
		if (crVal > bestVal) {
			best = newD;
			bestVal = crVal;
		}

		arr[i][j][k] = newD;
		/* 
		printf("%d %d %d - ", i, j, k);
		for (int a: arr[i][j][k]) cout << a << " "; 
		cout << endl;
		*/
	} else {
		list<int> * tempLst = new list<int>[3] {
			arr[i-1][j][k], arr[i][j-1][k], arr[i][j][k-1]
		};
		unsigned int * tempLen = new unsigned int[3] {
			tempLst[0].size(), tempLst[1].size(), tempLst[2].size()
		};
		//
		arr[i][j][k] = tempLst[distance(tempLen, max_element(
			tempLen, tempLen + 3
		))];
		//
		delete[] tempLst;
		delete[] tempLen;
	}
}

void calc() {
	lli bestVal = 0l;
	list<int> d;
	// dont need to loop for case = 0
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			for (int k = 1; k < n + 1; k++) {
				iterateHandler(i, j, k, d, bestVal);
			}
		}
	}
	//
	cout << d.size() << endl;
	if (d.size() > 0) {
		for (int i: d) cout << i << " ";
		cout << endl;
	}
}

//
void getinp() {
	cin >> n;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			cin >> beat[i][j];
		}
	}
}

//
int main() {
	getinp();
	calc();
	//
	return 0;
}
