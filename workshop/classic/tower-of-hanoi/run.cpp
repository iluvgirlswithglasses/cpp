
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Oct 06 16:09:54 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

/*
this problem used to be so hard back then
now it's easy af
*/

#include <iostream>
using namespace std;

/*
một đĩa:
- mang trực tiếp từ cr -> des
2 đĩa:
- mang 1 đĩa từ cr -> tmp
- mang 1 đĩa từ cr -> des
- mang đĩa từ tmp -> des
3 đĩa:
- mang 2 đĩa từ cr -> tmp
- mang 1 đĩa từ cr -> des
- mang 2 đĩa từ tmp -> des
n đĩa:
- mang (n-1) đĩa từ cr -> tmp
- mang 1 đĩa từ cr -> des
- mang (n-1) đĩa từ tmp -> des
*/

// a: current pillar / cr
// b: temp pillar / tmp
// c: destination pillar / des
void recursion(int n, int a, int b, int c) {
	if (n == 1) {
		cout << a << " " << c << "\n";
	} else {
		// a -> trung gian c -> b
		recursion(n-1, a, c, b);
		// a -> c
		recursion(1, a, b, c);
		// b -> trung gian a -> c
		recursion(n-1, b, a, c);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	recursion(n, 0, 1, 2);
	return 0;
}

