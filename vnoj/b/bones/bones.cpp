#include <iostream>
using namespace std;

int a, b, c;
int cnt[20+20+40+7];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> c;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				cnt[i+j+k]++;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= a+b+c; i++) {
		if (cnt[i] > cnt[res]) res = i;
	}
	cout << res << "\n";
	return 0;
}
