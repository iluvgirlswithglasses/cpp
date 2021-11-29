
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 28 17:38:04 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#include <cstdio>	// debug

/*
	số bộ thỏa ở nốt a
=	số nốt con có C < C[a] Choose 2

	bài này mình duyệt từ nhân viên có lương nhỏ nhất --> lớn nhất
	vì nếu không duyệt theo thứ tự tăng dần như vậy thì mình cũng đjt biết làm sao ;)
*/

/** defs */
struct worker {
	int index, salary, l, r;
};

#define ll long long
const int N = 1e5+7;

/** vars */
int n;
worker a[N];
ll res;
vector<int> adj[N];

/** utils */
void compress() {
	set<int> s;
	for (int i = 0; i < n; i++) {
		s.insert(a[i].salary);
	}
	vector<int> v(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		a[i].salary = lower_bound(v.begin(), v.end(), a[i].salary) - v.begin() + 1;
		a[i].index = i;
	}
}

/** 
 * segment tree 
 * 
 * query(l, r) = số nhân viên hiện có trong đoạn [l:r)
 * */
int fn, f[N<<2];	// cây sau khi làm phẳng sẽ có 2n = fn phần tử

void upd(int i) {
	for (i+=fn; i > 0; i>>=1) {
		f[i]++;
	}
}

int get(int l, int r) {
	if (r - l < 1) return 0; 
	int res = 0;
	for (l+=fn, r+=fn; l < r; l>>=1, r>>=1) {
		if (l&1) res += f[l++];
		if (r&1) res += f[--r];
	}
	return res;
}

/** dfs */
int top = 0;

void dfs(int u) {
	a[u].l = top++;
	for (int v: adj[u]) dfs(v);
	a[u].r = top++;
}

/** drivers */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a[0].salary;
	for (int i = 1; i < n; i++) {
		int p; 
		cin >> p >> a[i].salary;
		adj[--p].push_back(i);
	}
	//
	compress();
	dfs(0);
	fn = n<<1;
	//
	sort(a, a+n, [](worker& a, worker& b){
		return a.salary < b.salary;
	});
	vector<int> to_upd = {a[0].l, a[0].r};
	// 
	for (int i = 1; i < n; i++) {
		if (a[i].salary > a[i-1].salary) {
			for (int j: to_upd) upd(j);
			to_upd.clear();
		}
		// số phần tử trong đoạn của cây đã làm phẳng == số đệ
		ll has = get(a[i].l+1, a[i].r)>>1;
		res += has*(has-1)>>1;
		//
		to_upd.push_back(a[i].l);
		to_upd.push_back(a[i].r);
	}
	//
	cout << res << "\n";
	return 0;
}
