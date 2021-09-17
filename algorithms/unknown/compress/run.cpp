#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define ll long long

const int N = 2e5+7;
int n, a[N];

/**
 * use binary search
 * */
int bs(vector<int> &v, int i) {
	int l = 0, r = v.size()-1;
	while (l < r) {
		int m = (l + r + 1) >> 1;
		if (v[m] <= i) l = m;
		else r = m - 1;
	}
	return l;
}

void f() {
	set<int> s(a, a+n);
	vector<int> v(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		a[i] = bs(v, a[i]);
	}
}

/**
 * use lower_bound()
 * */
void g() {
	set<int> s(a, a+n);
	vector<int> v(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
	}
}

/**
 * driver
 * */
ifstream inp; 
ofstream out;
void init_io() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	inp.open("i.txt");
	out.open("o.txt");
}

int main() {
	init_io();
	system_clock::time_point start = system_clock::now();
	//
	inp >> n;
	for (int i = 0; i < n; i++) 
		inp >> a[i];
	//
	f();
	for (int i = 0; i < n; i++) 
		out << a[i] << " "; 
	out << "\n";
	//
	duration<double> diff = system_clock::now() - start;
	cout << diff.count() << "s\n";
	return 0;
}
