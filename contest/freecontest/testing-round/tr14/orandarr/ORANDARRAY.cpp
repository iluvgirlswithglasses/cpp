#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+5;
int n,k,a[MAX];

bool check(int lim) {
	int sumOr=0, cnt=0;
	for(int i=1; i<=n; i++) {
		sumOr |= a[i];
		if((sumOr&lim) == lim) {
			sumOr=0;
			cnt++;
		}
	}
	return cnt >= k;
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	int rs = 0;
	for(int i = 30; i >= 0; i--)
		if (check( rs+(1<<i) )) rs += (1<<i);
	cout << rs;
	//
	return 0;
}