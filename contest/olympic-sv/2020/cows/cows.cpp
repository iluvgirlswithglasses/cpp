#include <iostream>
using namespace std;

#define ll long long
ll n, s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	ll r = n * (2 + (n-1)) / 2;
	cout << r - s << "\n";
	return 0;
}
