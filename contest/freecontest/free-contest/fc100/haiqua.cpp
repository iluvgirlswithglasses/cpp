
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Dec 20 18:30:25 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

/*
chỉ có thể hái quả có w = 1 hoặc = 2

nút này có 2 quả 1/2 thì nút kia (nút con cùng cha) cũng phải có quả 1/2, 
nói chung làm sao ra hiệu <= 1

khi vẽ ra hết tcả các trường hợp thì...
không thể hái nhiều hơn 1 quả có w = 2
và nếu có hái thì buộc hái nó trước

Trong quá trình làm thì nhận ra được thêm 1 điều nữa
Một khi đã hái được 1 quả, chắc chắn sẽ hái trụi cả cây
Do chỉ cần 1 cành 1/1 hoặc 1/2 thì domino ra mấy cành kia cũng phải vậy
thì mới k đổ á
*/

#define pi pair<int, int>
#define st first
#define nd second

const int N = (1<<20) + 7;
int n, k, f[N<<1];

bool read() {
	bool can = true;
	int twocnt = 0;
	//
	cin >> k;
	n = 1<<k;
	for (int i = 0; i < n; i++) {
		cin >> f[n+i];
		if (can) {
			if (f[n+i] > 2)
				can = false;
			if (f[n+i] == 2) 
				twocnt++;
		}
	}
	//
	for (int i = n-1; i > 0; i--)
		f[i] = f[i<<1] + f[i<<1|1];
	//
	return can && twocnt <= 1;
}

// returns: {id of the erased node, weight of the erased node};
pi erase(int idx) {
	//
	if (idx >= n) {
		int w = f[idx];
		f[idx] = 0;
		return make_pair(idx - n + 1, w);
	}
	//
	int l = idx<<1, r = l|1;
	pi child;
	if (f[r] > f[l]) {
		child = erase(r);
	} else {
		child = erase(l);
	}
	//
	f[idx] -= child.nd;
	return child; 
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	if (read()) {
		cout << n << "\n";
		for (int i = 0; i < n; i++)
			cout << erase(1).st << " ";
		cout << "\n";
	} else {
		cout << "0\n";
	}
	return 0;
}
