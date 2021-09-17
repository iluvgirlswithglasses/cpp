#include <iostream>
#include <stdio.h>
using namespace std;
 
const int maxn = 3e4 + 4;
long int n, a[maxn], lis[maxn], t[maxn], p;
 
int main (void) 
{
	scanf ("%d", &n);
	a [0] = -1e9;	// a[] is the given array
	a [n + 1] = 1e9;
 
	for (int i = 1; i <= n + 1; ++i) {
		//
		if (i <= n) scanf ("%ld", &a [i]);
		int l = 0, r = p;
		//
		while (l < r) {
			int m = (l + r + 1) >> 1;
			if (a [t [m]] < a [i]) l = m;
			else r = m - 1;
		}
		//
		lis [i] = l + 1;	// l == r
		//
		if (lis[i] > p) {
			t[ ++p ] = i;
		} else if ( 
			a[i] < a[ t[lis[i]] ] 
		) {
			t[ lis[i] ] = i;
		}
	}
	printf ("%ld\n", lis [n + 1] - 1);
	// returns
	system("pause");
	return 0;
}