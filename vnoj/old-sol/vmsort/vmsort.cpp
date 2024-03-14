#include <iostream>
#include <set>
#include <string>
using namespace std;

int k, n;
string u;
set<string> s;

int main() {
	cin >> k;
	while (k--) {
		cin >> n;
		while (n--) {
			cin >> u;
			s.insert(u);
		}
	}
	cout << s.size() << endl;
	//
	system("pause");
	return 0;
}
