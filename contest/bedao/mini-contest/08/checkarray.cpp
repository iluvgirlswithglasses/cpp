
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Dec 13 17:21:14 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 52;
int n, a[N];

const char* calc() {
	sort(a, a+n, [](int i, int j){
		return i > j;
	});
	for (int i = 0; i < n-1; i++)
		if (a[i] - a[i+1] > 1) return "NO";
	return "YES";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << calc() << "\n";
	return 0;
}
