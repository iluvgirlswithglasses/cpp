
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec  1 22:56:21 2021
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
using namespace std;

#include <cstdio>	// debug

/*
what ???
tf ????
I was so certain my method can be used on tree only

I gotta submit this again to see if the server wasn't drunk
*/

/**
 * @defs
 * */

const int N = 2e5+7;
const int YUKI = 0, AME = 1, HANA = 2;	// chị - em - mẹ :))))


/**
 * @vars
 * 
 * ban đầu tính để state[i] == 0 là chưa thăm
 * nhưng thật ra như v là thừa
 * nếu để mặc định YUKI đào hết thì dễ hơn nhiều
 * */

int n;
vector<int> adj[N];

// state[i] = đào bởi i
// mặc định = YUKI
int state[N];
// yukicnt: số hang chị phải đào, mặc định = n
// amecnt:  số hang em phải đào, default = 0
int yukicnt, amecnt;
// các hang mà mẹ phải đào, sắp xếp theo thứ tự thăm ~viếng~
vector<int> hana;


/**
 * @calc
 * */

bool dfs(int u) {
	// I strongly believe that
	// there is at least one solution
	// which HANA would dig at least 1 cave
	state[u] = HANA;
	hana.push_back(u);
	// nếu giao hàng này cho hana là xong việc
	if (--yukicnt == amecnt) {
		return true;	// we're done
	}
	//
	for (int v: adj[u]) if (state[v] == YUKI) {
		if (dfs(v)) {
			return true;	// we're done
		}
	}
	//
	state[u] = AME;
	amecnt++;
	hana.pop_back();
	// nếu giao hang này cho ame là xong việc
	return amecnt == yukicnt;
}


/**
 * @drivers
 * */

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int m; cin >> n >> m;
	yukicnt = n;
	while (m--) {
		int u, v; cin >> u >> v;
		adj[--u].push_back(--v);
		adj[v].push_back(u);
	}
	//
	dfs(0);
	vector<int> res[3];
	for (int i = 0; i < n; i++)
		res[ state[i] ].push_back(i);
	cout << n - yukicnt - amecnt << " " << yukicnt << "\n";
	// in ra các hang hana đào
	// theo đúng thứ tự bfs
	for (int j: hana) cout << j+1 << " ";
	cout << "\n";
	// ame to yuki
	for (int i = 0; i < 2; i++) {
		for (int j: res[i]) cout << j+1 << " ";
		cout << "\n";
	}
	return 0;
}
