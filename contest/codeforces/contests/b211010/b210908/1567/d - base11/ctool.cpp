#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	int s = 0, a;
	string str;
	while (n--) {
		cin >> a;
		str = to_string(a);
		for (int i = str.length()-1, e = 1; i >= 0; i--, e*=11) {
			s += (str[i] - '0') * e;
		}
	}
	cout << s << "\n";
}
