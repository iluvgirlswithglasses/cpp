#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
	int u, v, c;
};

const int N = 1e5+7;
int n;
edge arr[N];

/**
 * dsu
 * */
int p[N], s[N];

void dsu() {
	for (int i = 1; i <= n; i++){
		p[i] = i; s[i] = 1;
	}
}

int find(int u) {
	if (p[u] == u) return u;
	p[u] = find(p[u]);
	return p[u];
}

void join(int u, int v) {
	int a = find(u);
	int b = find(v);
	if (a != b) {
		if (s[a] < s[b]) swap(a, b);
		p[b] = a;
		s[a] += s[b];
	}
}


/**
 * 
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n-1; i++) 
		cin >> arr[i].u >> arr[i].v >> arr[i].c;
	//
	dsu();
	sort(arr, arr+(n-1), [](edge &i, edge &j){
		return i.c < j.c;
	});
	//
	long long res = 0;
	for (int i = 0; i < n-1; i++) {
		res += (long long) arr[i].c * s[find(arr[i].u)] * s[find(arr[i].v)];
		join(arr[i].u, arr[i].v);
	}
	cout << res << endl;
	return 0;
}
