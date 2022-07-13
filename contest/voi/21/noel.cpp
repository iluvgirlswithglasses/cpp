
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Jul 13 20:03:12 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 2e3+7;
// f[i][j]:	the maximum count of children to have candy
//			if there is a child who earns two candies indexed `i` and `j`
int n, d, c[N], f[N][N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> d;
	for (int i = 0; i < (n<<1); i++)
		cin >> c[i];

	return 0;
}
