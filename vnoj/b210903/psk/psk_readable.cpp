#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

struct cup {
	int i, v, c;
};

const int N = 1e3+7;
int n;
cup a[N];

/**
 * sort a[]
 * */
void sortby_index() {
	sort(a, a+n, [](cup &i, cup &j){
		return i.i < j.i;
	});
}

void sortby_volume() {
	sort(a, a+n, [](cup &i, cup &j){
		return i.v > j.v;
	});
}

/**
 * 
 * */
void prf_res(int i) {
	sortby_index();
	cout << n-i-1 << "\n";
	for (int j = 0; j < n; j++) {
		cout << a[j].c << " ";
	} cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	ll s = 0;
	for (int i = 0; i < n; i++) {
		int t, z; cin >> t >> z;
		s += t;
		a[i].i = i; a[i].v = z;
	}
	sortby_volume();
	//
	for (int i = 0; i < n; i++) {
		a[i].c = min((ll) a[i].v, s);
		s -= a[i].v;
		//
		if (s <= 0) {
			// returns
			prf_res(i);
			break;
		}
	}
	return 0;
}
