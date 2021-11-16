
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 16 16:17:30 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define ll long long

const int N = 1e7+7;
int a, b;
int cnt[N];
ll  res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b;
	for (int i = 2; (i<<1) <= b; i++)
	for (int j = (i<<1); j <= b; j+=i) {
		cnt[j] += i;
	}
	//
	if (a == 1) res++;
	for (int i = a; i <= b; i++) {
		res += abs(i - cnt[i] - 1);
	}
	cout << res << "\n";
	return 0;
}

