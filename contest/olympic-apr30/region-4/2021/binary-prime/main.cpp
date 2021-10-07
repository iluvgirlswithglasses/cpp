#include <string>
#include <fstream>
#include <iostream>
using namespace std;

bool is_prime(int n) {
	if (n == 1) return false;
	if (n == 2) return true;
	//
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool is_ref(int n) {
	string s = "";
	string alt = "";
	while (n > 0) {
		//
		int r = n % 2;
		n /= 2;
		char a = r - '0';
		s = a + s;
		//
		alt = to_string(r) + alt;
	}
	cout << s << "\t" << alt << endl;
	return false;
}

int main() {
	for (int i = 0; i < 30; i++) is_ref(i);
	//
	getchar();
	return 0;
}
