#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

const int N = 1e5+7, I = 1e9+7;
int n, k, a[N];

string calc() {
	// v: splited array
	// v[i] is sorted and starts with i.first, end with i.second
	vector<pair<int, int>> v;
	int pre = a[0], start = a[0];
	//
	for (int i = 1; i < n; i++) {
		if (a[i] < pre) {
			v.push_back({start, pre});
			start = a[i];
		}
		pre = a[i];
	}
	v.push_back({start, a[n-1]});
	sort(v.begin(), v.end(), [](pair<int, int> i, pair<int, int> j){
		if (i.first == j.first) {
			return i.second <= j.first;
		}
		return i.first < j.first;
	});
	// debug
	for (pair<int, int> i: v) cout << i.first << " " << i.second << ", "; cout << endl;
	//
	if (v.size() > k) return "No";
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i].second > v[i+1].first) return "No";
	}
	//
	return "Yes";
}

int main() {
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];
		// should be O(n)
		cout << calc() << endl;
	}
	// system("pause");
	return 0;
}
