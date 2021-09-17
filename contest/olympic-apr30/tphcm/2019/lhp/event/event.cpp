#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//
int n, n_val, n_len;
int * vals = new int[10]{
	6, 2, 5, 5, 4, 5, 6, 3, 7, 6
};

// use this instead of out in real test
ofstream out;

//
void init() {
	out.open("event.out");
}

// 
bool valid(int k) {
	return to_string(k).length() == n_len;
}

int calc_val(int k) {
	int s = 0;
	string str = to_string(k);
	//
	for (int i = 0; i < str.length(); i++) {
		int c = str.at(i) - '0';
		s += vals[c];
	}
	//
	return s;
}

int calc(int k) {
	if (!valid(k)) return -1;
	if (calc_val(k) == n_val) return k;
	return calc(k + 1);
}

//
void get_inp() {
	ifstream inp; inp.open("event.inp");
	inp >> n;
	//
	n_val = calc_val(n);
	n_len = to_string(n).length();
}

int main() {
	init();
	get_inp();
	//
	int res = calc(n + 1);
	if (res == -1) {
		cout << "NO SOLUTION";
	} else {
		cout << res;
	}
	//
	getchar();
	return 0;
}
