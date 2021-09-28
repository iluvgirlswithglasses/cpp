#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 2e5+7;
int n, a[N];

void calc() {
	deque<int> q;
	q.push_back(a[0]);
	//
	for (int i = 1; i < n; i++) {
		if (a[i] < q.front())
			q.push_front(a[i]);
		else
			q.push_back(a[i]);
	}
	//
	for (int i = 0; i < n; i++) {
		cout << q.front() << " ";
		q.pop_front();
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		calc();
	}
	return 0;
}
