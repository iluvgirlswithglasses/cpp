#include <iostream>
using namespace std;

const int N = 2e5+7;
int l, r; 
bool er[N];	// er[i] == true --> er[i] isn't prime

void eratosthenes() {
	er[1] = true;
	for (int i = 2; i < N; i++) {
		if (!er[i]) {
			for (long long j = (long long) i * i; j < N; j+=i) {
				er[j] = true;
			}
		}
	}
}

int main() {
	eratosthenes();
	cin >> l >> r; r++;
	for (int i = l; i < r; i++) {
		if (!er[i]) cout << i << endl;
	}
	//
	system("pause");
	return 0;
}
