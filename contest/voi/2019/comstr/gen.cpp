#include <iostream>
#include <string>
using namespace std;

int main() {
	string a, b, tmp;
	cin >> a >> b;
	cout << a << "\n";
	for (int i = 0; i < 10; i++) {
		tmp = a;
		a = b;
		b = a + tmp;
		cout << a << "\n";
	}
	return 0;
}
