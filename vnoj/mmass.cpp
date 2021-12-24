
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Dec 24 15:37:43 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

const int N = 102;
int n, ele[N], cnt[N];
string s;
stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	//
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == '(') {
			//
			st.push(n);
		} else if (c == ')') {
			//
			int last = st.top(); st.pop();
			char nxt = s[i+1];
			//
			if ('0' <= nxt && nxt <= '9') {
				for (int j = last; j < n; j++)
					cnt[j] *= (nxt - '0');
				i++;
			}

		} else if ('0' <= c && c <= '9') {
			// không xử lý th số sau dấu ngoặc
			cnt[n-1] = c - '0';
		} else {
			// element
			cnt[n] = 1;
			switch (c) {
				case 'C': ele[n] = 12; break;
				case 'H': ele[n] = 1; break;
				case 'O': ele[n] = 16; break;
			}
			n++;
		}
	}
	//
	int res = 0;
	for (int i = 0; i < n; i++)
		res += ele[i] * cnt[i];
	cout << res << "\n";
	return 0;
}
