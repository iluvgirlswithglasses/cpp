
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 22 19:11:10 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

/*
"đề này không phải nghĩ"
	- Hoàng Vũ A2K48 2020
*/

#include <bits/stdc++.h>
using namespace std;

/*
"hai đường thẳng chứa hai cạnh không kề nhau của nó không cắt nhau ở bên trong tấm thép"
--> khi cắt 1 cạnh, nó chỉ thay đổi kết quả cắt 2 cạnh kề nó
*/

#define ld long double
#define pi pair<ld, ld>
#define st first
#define nd second

const int N = 2e3+7;
int n, m;
ld a[N][2], b[N][2];

void getinp() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%Lf %Lf", &a[i][0], &a[i][1]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%Lf %Lf", &b[i][0], &b[i][1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	getinp();
	return 0;
}

