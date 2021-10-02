#include <iostream>
using namespace std;

#define i16 short
#define u16 unsigned short
#define u32 unsigned int

const u16 N = 4;
const u16 I = 65535;
u16 houses;

const i16 M[] = {-4, 1, 4, -1};
const i16 E[] = {0, 1, 2, 3, 4, 7, 8, 11, 12, 13, 14, 15};

i16 getnxt(i16 cr, i16 m) {
	i16 nxt = cr + M[m];
	if (abs(M[m]) == 1) {
		if (cr/4 == nxt/4) return nxt;
		return -1;
	}
	if (0 <= nxt && nxt < 16) return nxt;
	return -1;
}

void dfs(const u16 bitset, i16 u, u16 &visited, u16 &cnt) {
	visited |= 1<<u;
	cnt++;
	//
	for (i16 i = 0; i < 4; i++) {
		i16 nxt = getnxt(u, i);
		if (
			(nxt != -1) &&
			(bitset>>nxt&1) &&
			!(visited>>nxt&1)
		) dfs(bitset, nxt, visited, cnt);
	}
}

bool dfs(u16 bitset) {
	u16 visited = 0, cnt = 0;
	for (i16 i = 0; i < 16; i++) if (bitset>>i&1) {
		dfs(bitset, i, visited, cnt);
		break;
	}
	return cnt == __builtin_popcount(bitset);
}


bool dfs_g2(u16 bitset) {
	u16 visited = 0, cnt = 0;
	bitset = ~bitset;
	for (int _i = 0; _i < sizeof(E) / sizeof(E[0]); _i++) {
		u16 i = E[_i];
		if (
			(bitset>>i&1) && !(visited>>i&1)
		) dfs(bitset, i, visited, cnt);
	}
	return cnt == __builtin_popcount(bitset);
}

bool included(u16 &bitset) {
	u16 s = ~(bitset|houses);
	return s == 0;
}

u32 brute() {
	u32 res = 0;
	for (u16 i = 1; i != 0; i++) {
		if (included(i) && dfs(i) && dfs_g2(i)) {
			res++;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	houses = ~houses;
	// inp
	for (int i = 0; i < N; i++) 
	for (int j = 0; j < N; j++) {
		bool k; cin >> k;
		if (k) houses ^= 1<<((i<<2) + j);
	}
	// res
	cout << brute() << "\n";
	return 0;
}
