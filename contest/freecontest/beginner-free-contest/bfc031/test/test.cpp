#include <iostream>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;
	//
	int r = n % k;
	int a = n * 17, b = r * 17;
	cout << (a % k) << " " << (b % k) << endl;
	//
	cin >> n;
	return 0;
}
