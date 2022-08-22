#include <iostream>
using namespace std;

int main() {
	long long a, b, x, y;
	cin >> a >> b >> x >> y;
	long long s = abs(a - x) * abs(b - y);
	cout << s << endl;
	//
	cin >> a;
	return 0;
}
