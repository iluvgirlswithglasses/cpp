
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec  4 11:39:54 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
đề không hề ghi rằng:
	khi có nhiều người về đích cùng lúc, tất cả mọi người sẽ đều được phát huy chương
và trong khi đề cho constraint N <= 1000,
test 6 lại cho N = 1063

bruh hết sức bruh
*/

#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second
#define mkpair make_pair

const int N = 1e3+7, K = 102;
int n, k, a[N][K];
map<int, vector<int>> resource_holder;

int org[K], wincnt;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// freopen("SUPERSCH.INP", "r", stdin);
	// freopen("SUPERSCH.OUT", "w", stdout);
	//
	cin >> n >> k;
	n--;
	for (int j = 0; j < n; j++)
	for (int i = 0; i < k; i++)
		cin >> a[j][i];
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		resource_holder[x].push_back(i+1);
	}
	//
	for (int i = 0; i < k; i++) {
		int mi = a[0][i];
		for (int j = 1; j < n; j++)
			mi = min(mi, a[j][i]);
		//
		map<int, vector<int>>::iterator p = resource_holder.upper_bound(mi);
		if (p != resource_holder.begin()) {
			p--;
			wincnt++;
			org[i] = p->nd.back();
			p->nd.pop_back();
			if (p->nd.size() == 0) {
				resource_holder.erase(p);
			}
		}
	}
	//
	cout << wincnt << "\n";
	for (int i = 0; i < k; i++) {
		if (org[i] > 0) {
			cout << org[i] << " ";
		} else {
			map<int, vector<int>>::iterator p = resource_holder.begin();
			cout << p->nd.back() << " ";
			p->nd.pop_back();
			if (p->nd.size() == 0) {
				resource_holder.erase(p);
			}
		}
	}
	cout << "\n";
	return 0;
}
