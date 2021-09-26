#include <iostream>
#include <string>
using namespace std;

#define u64 unsigned long long
const char h[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void calc(u64 v) {
	if (v > 0) {
		calc(v/16);
		cout << h[v%16];
	}
}

int main() {
	while (true) {
		u64 v; cin >> v;
		calc(v);
		cout << "\n";
	}
}
