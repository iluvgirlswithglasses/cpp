#include <bits/stdc++.h>
using namespace std;

// utils
int k = 3;
int * encodes = new int[k]{'L', 'R', 'U'};
int encode(char i) {
	return distance(
		encodes, find(encodes, encodes + k, i)
	);
}

//
int * recursion(string t, int cr) {
	// U is handled by calc
	if (t.at(cr) == 'U') return recursion(t, cr + 1);
	// bottom str
	if (cr == t.length() - 1) {
		int * res = new int[2]{0, 0};
		res[encode(t.at(cr))] = 1;
		return res;
	}
	//
	int * child = recursion(t, cr + 1);
	int * res = new int[2];
	int index = encode(t.at(cr));
	res[index] = child[0] + child[1] + 1;
	res[(index + 1) % 2] = child[(index + 1) % 2];
	delete[] child;
	//
	return res;
}

int calc(string s, string t) {
	//
	int res = 0;
	if (t.length() == 0) {
		return 1;
	} else {
		int * r = recursion(t, 0);
		res += 1 + r[0] + r[1];
	}
	// that annoying U
	int uCount = 0;
	for (int i = 0; i < t.length(); i++) {
		if (t.at(i) == 'U') {
			uCount += 1;
			if (s.length() >= uCount) {
				int * r = recursion(t, i + 1);
				int pos = encode(s.at(s.length() - uCount));
				res += 1 + r[(pos + 1) % 2];
				delete[] r;
			}
		}
	}
	//
	return res;
}

//
int main() {
	int testCount;
	ifstream inp("btree.inp"); inp >> testCount;
	for (int i = 0; i < testCount; i++) {
		string s, t; inp >> s >> t; 
		// we don't need S tbh
		s = s.substr(1, s.length() - 1);
		t = t.substr(1, t.length() - 1);
		cout << calc(s, t) << endl;
	}
	//
	getchar();
	return 0;
}
