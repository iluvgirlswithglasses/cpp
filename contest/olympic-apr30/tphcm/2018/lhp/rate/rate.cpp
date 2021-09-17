#include <iostream>
#include <fstream>
using namespace std;

//
int n, k;
int * arr;

double recursion(int l, double & best) {
	if (l > n) return best;
	//
	long long int res = 0;
	// first slide
	for (int i = 0; i < l; i++) {
		res += arr[i];
	}
	best = max(best, res / (double) l);
	// others
	for (int i = 1; i <= n - l; i++) {
		res += (arr[i + l - 1] - arr[i - 1]);
		best = max(best, res / (double) l);
	}
	return recursion(l + 1, best);
}

//
void getinp() {
	ifstream inp("rate.inp");
	inp >> n >> k;
	arr = new int[n];
	//
	for (int i = 0; i < n; i++) inp >> arr[i];
}

//
int main() {
	getinp(); 
	//
	double best = 0;
	string res = to_string(recursion(k, best));
	cout << res;
	//
	getchar();
	return 0;
}
