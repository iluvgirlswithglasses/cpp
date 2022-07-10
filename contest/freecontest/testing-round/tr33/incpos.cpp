
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Jul 10 23:26:50 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
given the array `a[]` and `q` queries
for each query
increase `a[l:r]` by `x`
then print the number of this occurrences: `a[i] > a[i+1]`
*/

#include <iostream>
using namespace std;

const int N = 2e5+7;
// f[i]:	number of occurrences managed by node `f[i]`
// fl[i]:	the value of the left-most element managed by `f[i]`
// fr[i]:	same of `fl[i]` for right-most
// fd[i]:	lazy update for `fl[]` and `fr[]`
int n, q, f[N<<1], fl[N<<1], fr[N<<1], fd[N];

void init() {
	for (int i = n-1; i > 0; i--) {
		int l = i<<1, r = i<<1|1;
		f[i] = f[l] + f[r];
		fl[i] = fl[l]; fr[i] = fr[r];
		// found one more occurrences when joining two child nodes
		if (fr[l] > fl[r]) f[i]++;
	}
}

void upd(int l, int r, int v) {

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = n; i < (n<<1); i++) {
		int x; cin >> x;
		fl[i] = fr[i] = x;
	}
	init();
	//
	while (q--) {
		int l, r, v; cin >> l >> r >> v;
		upd(l-1, r, v);
		cout << f[1] << "\n";
	}
	return 0;
}
