#include <fstream>
#include <algorithm>
using namespace std;

#define u64 unsigned long long
#define pi pair<u64, u64>
#define st first
#define nd second

const int N = 1e5+7;
u64 n, b; pi a[N];

int main() {
	// ios_base::sync_with_stdio(false); inp.tie(0);
	ifstream inp("CHOCOLATE.INP");
	ofstream out("CHOCOLATE.OUT");
	//
	inp >> n >> b;
	for (int i = 0; i < n; i++) inp >> a[i].st >> a[i].nd;
	sort(a, a+n, [](pi &i, pi &j){
		return i.st < j.st;
	});
	//
	u64 c = 0;
	for (int i = 0; i < n; i++) {
		u64 add = min(a[i].nd, b / a[i].st);
		if (add == 0) break;
		c += add;
		b -= a[i].st * add;
	}
	out << c << "\n";
	return 0;
}
