
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 31 21:53:45 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5+7, H = 1e5+7;
int n, h, cnt[H];

const char* calc() {
	for (int i = h; i > 0; i--) {
		cnt[i] = cnt[i] + (cnt[i+1] >> 1);
		if (cnt[i]&1) return "NO";
	}
	return cnt[1] == 2 ? "YES" : "NO";
}

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	int q; scanf("%d", &q);
	while (q--) {
		memset(cnt, 0, H*sizeof(cnt[0]));
		h = 0;
		//
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			cnt[a]++;
			h = a>h ? a : h;
		}
		//
		printf("%s\n", calc());
	}
	return 0;
}

