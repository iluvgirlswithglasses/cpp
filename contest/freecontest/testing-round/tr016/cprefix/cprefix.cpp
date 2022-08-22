#include <string>
#include <list>
#include <iostream>
using namespace std;

//
int n;
string s;
list<int> lst;


//
void init() {
	char start = s.at(0);
	int rep = 1;
	//
	for (int i = 1; i < n; i++) {
		if (s.at(i) == start) {
			rep += 1;
			lst.push_back(i);
		}
	}
	cout << rep << " ";
}

void calc(int len) {
	// break condition
	if (len == n) return;
	//
	char start = s.at(len - 1);
	int rep = 1;
	//
	int pre_cases = lst.size();
	for (int i = 0; i < pre_cases; i++) {
		int j = lst.front(); lst.pop_front();
		//
		if (++j == n) break;
		//
		if (s.at(j) == start) {
			rep += 1;
			lst.push_back(j);
		}
	}
	// 
	cout << rep << " ";
	calc(len + 1);
}


//
int main() {
	//
	cin >> s;
	n = s.length();
	//
	init();
	calc(2);
	// returns
	cout << 1 << endl;
	return 0;
}
