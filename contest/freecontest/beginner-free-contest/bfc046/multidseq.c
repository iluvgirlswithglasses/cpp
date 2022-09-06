
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:    Tue Sep  6 16:28:54 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <stdio.h>

const int R = 1e9+7;
int k, n, res;
int dp[52][100007];

void radd(int *x, int y) {
    *x += y;
    if (*x >= R) *x -= R;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int j = 1; j <= n; j++)
        dp[1][j] = 1;
    //
    for (int i = 1; i < k; i++)
        for (int j = 1; j <= n; j++)
            for (int m = j; m <= n; m += j)
                radd(&dp[i+1][m], dp[i][j]);
    //
    for (int j = 1; j <= n; j++)
        radd(&res, dp[k][j]);
    printf("%d\n", res);
	return 0;
}
