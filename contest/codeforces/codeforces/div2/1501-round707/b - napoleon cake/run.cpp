
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 22 19:43:48 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int N = 2e5+7;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//
	int t; cin >> t;
	while (t--) {
		cin >> n;
		vector<bool> res(n, true);
		stack<int> s;
		//
		for (int i = 0; i < n; i++) {
			s.push(i);
			int a; cin >> a;
			if (a > 0) {
				int downto = max(0, i-a+1);
				while (s.size() && s.top() >= downto) 
					s.pop();
			}
		}
		//
		while (s.size()) {
			res[s.top()] = false;
			s.pop();
		}
		for (int i: res)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}

