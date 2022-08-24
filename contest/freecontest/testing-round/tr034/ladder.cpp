
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Aug 24 17:39:28 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstdio>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e5, I = 1e9+7;
int n, m, a[N];
// increase[], decrease[]
// in[i] == in[j] --> a[i:j] increasing subsequence
// de[i] == de[j] --> a[i:j] decreasing subsequence
// inEnd[i]: the last index of group `i` in `in[]`
// likewise for `deEnd[]`
int in[N], de[N], inEnd[N], deEnd[N];

void init() {
	for (int i = 1; i < n; i++) {
		// increase
		if (a[i] >= a[i-1]) 
			in[i] = in[i-1];
		else
			in[i] = in[i-1]+1, inEnd[in[i-1]] = i-1;
		// decrease
		if (a[i] <= a[i-1])
			de[i] = de[i-1];
		else
			de[i] = de[i-1]+1, deEnd[de[i-1]] = i-1;
	}
}

const char* query(int l, int r) {
	// if this subseq always increases/decreases
	if (in[l] == in[r] || de[l] == de[r])
		return "Yes\n";
	// if there's fluctuation
	int inGroup = in[l], mid = inEnd[inGroup];
	if (de[mid] == de[r])
		return "Yes\n";
	return "No\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	init();
	while (m--) {
		int l, r; cin >> l >> r;
		cout << query(l-1, r-1);
	}
	return 0;
}
