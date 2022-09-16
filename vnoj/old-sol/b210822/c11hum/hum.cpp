// credit to vietcodes

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;	// typedef is read by compiler

struct pack {
	ll value;
	ll prime;
	int index;
};

int k, n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//
	cin >> k >> n;
	vector<pack> p(k);
	//
	for (pack &p: p) {
		cin >> p.prime;
		p.value = p.prime;
		p.index = 0;
	}
	//
	vector<ll> res;
	while (n--) {
		vector<pack>::iterator i = min_element(p.begin(), p.end(), [](pack i, pack j){
			return i.value < j.value;
		});
		res.push_back(i->value);
		for (pack &p: p) {
			if (p.value == res.back())
				p.value = p.prime * res[++p.index];
		}
	}
	cout << res.back() << endl;
	return 0;
}
