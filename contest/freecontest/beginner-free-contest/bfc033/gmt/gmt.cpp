#include <iostream>
using namespace std;

int h, m, a, b;

int main() {
	cin >> h >> m >> a >> b;
	h += b - a;
	//
	if (h < 0) h += 24;
	if (h >= 24) h -= 24;
	cout << h << " " << m << endl;
	// system("pause");
	return 0;
}
