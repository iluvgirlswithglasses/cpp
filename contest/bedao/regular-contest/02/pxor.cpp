
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov  3 12:44:15 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

const int I = 1<<13;
int n, cnt[I];
set<int> a;

/**
 * eratos
 * */
vector<bool> p(I, true);

void eratos() {
	p[0] = false;
	p[1] = false;
	for (int i = 2; i < I; i++) {
		if (!p[i]) continue;
		for (int j = i*i; j < I; j+=i)
			p[j] = false;
	}
}


/**
 * drivers
 * */
int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	eratos();
	int q; scanf("%d", &q);
	while (q--) {
		memset(cnt, 0, I*sizeof(cnt[0]));
		scanf("%d", &n);
		for (int i = 0, _i; i < n; i++) {
			scanf("%d", &_i);
			cnt[_i]++;
			a.insert(_i);
		}
		//
	}
	return 0;
}

