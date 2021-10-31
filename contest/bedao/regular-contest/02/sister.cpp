
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 31 21:25:10 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <cstdio>
#include <vector>
using namespace std;

const int N = 22;
const int I = 1e5+7;
int n, c[N];
int res = -1;

/**
 * eratos
 * */
vector<bool> is_prime(N*I, true);

void eratos() {
	is_prime[0] = false;
	is_prime[1] = false;
	for (int i = 2; i * i < N*I; i++) {
		if (!is_prime[i]) continue;
		for (int j = i * i; j < N*I; j+=i)
			is_prime[j] = false;
	}
}

/**
 * 
 * */
int b;
vector<bool> cache(1<<N, false);

int main() {
	// ios_base::sync_with_stdio(false); cin.tie(0);
	eratos();
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	//
	for (int i = 0; i < n; i++)
		b |= 1<<i;
	//
	for (int mk = 0; mk < (1<<n); mk++) {
		if (cache[mk]) continue;
		//
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			if (mk>>i&1) a += c[i];
			else b += c[i];
		}
		int sub = a-b>0 ? a-b: b-a;
		if (is_prime[sub])
			res = max(res, sub);
		cache[mk] = cache[mk^b] = true;
	}
	printf("%d\n", res);
	return 0;
}

