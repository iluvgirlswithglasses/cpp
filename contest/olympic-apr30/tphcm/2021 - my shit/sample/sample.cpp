// OK, that first-year was better than me
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string * arr;

int calc() {
	int counts = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int matches = 0;
			for (int l = 0; l < m; l++) {
				if (arr[i].at(l) != arr[j].at(l)) {
					matches += 1;
					// since m <= 16
					// adding an if clause to break if matches > k seems less effective
				}
			}
			if (matches == k) counts += 1;
		}
	}
	return counts;
}

void getinp() {
	ifstream inp("sample.inp");
	inp >> n >> m >> k;
	arr = new string[n];
	for (int i = 0; i < n; i++) {
		inp >> arr[i];
	}
}

int main() {
	getinp();
	cout << calc();	// replaced by fout in real test
	//
	getchar();	// this didn't exist in real test
	return 0;
}
