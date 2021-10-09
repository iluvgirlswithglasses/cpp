#include <iostream>
#include <fstream>
using namespace std;

const int N = 1e7+7;
int n;
bool er[N];	// er[i] == true --> er[i] isn't prime

bool is_prime(int i) {
	return !er[i];
}

void eratosthenes() {
	er[0] = true;
	er[1] = true;
	for (int i = 2; i <= n; i++) {
		if (!er[i]) {
			for (long long j = (long long) i * i; j < N; j+=i) {
				er[j] = true;
			}
		}
	}
}

int main() {
	ofstream out("_sub\\out.txt");
	//
	cin >> n;
	int cnt = 0;
	eratosthenes();
	for (int i = 0; i <= n; i++) {
		if (is_prime(i)) {
			out << i << ", ";
			cnt++;
		}
	}
	//
	cout << cnt << "\n";
	return 0;
}
