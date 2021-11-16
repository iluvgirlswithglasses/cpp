
#include <stdio.h>

#define N 10000007
#define ll long long

int a, b;
int cnt[N];
ll res;

int abs(int x) {
    if (x < 0) return -x;
    return x;
}

int main() {
	scanf("%d%d", &a, &b);
	for (int i = 2; (i<<1) <= b; i++)
	for (int j = (i<<1); j <= b; j+=i) {
		cnt[j] += i;
	}
	//
	if (a == 1) res++;
	for (int i = a; i <= b; i++) {
		res += abs(i - cnt[i] - 1);
	}
	printf("%Ld\n", res);
	return 0;
}

