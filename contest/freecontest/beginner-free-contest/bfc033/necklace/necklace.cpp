#include <iostream>
using namespace std;

const int N = 3500;
int n, k, a[N];

/**
 * utils
 * */
int pre(int i) {
	if (i - 1 < 0) return n - 1;
	return i - 1;
}

int next(int i) {
	if (i + 1 == n) return 0;
	return i + 1;
}

/**
 * perf
 * */
void calc() {

}

/**
 * drivers
 * */
int main() {
	// inp
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	//
	calc();
	//
	system("pause");
	return 0;
}
