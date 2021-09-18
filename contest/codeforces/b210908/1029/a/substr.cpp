#include <string>
#include <iostream>
using namespace std;

string s;
int k, len;

int get_point() 
// return p
// where s[0:p) = s[len-p:len)
{
	int maxlen = 0;
	// maxlen < len --> min(tail.length()) == 1
	for (int i = 1; i < len; i++) {
		bool matched = true;
		for (int j = 0; j < i; j++) {
			if (s.at(j) != s.at(len - i + j)) {
				matched = false;
				break;
			}
		}
		if (matched) maxlen = i;
	}
	//
	return maxlen;
}

int main() 
{
	cin >> k >> k >> s;
	// calc
	len = s.length();
	int p = get_point();
	string tail = s.substr(p, len - p);
	// out
	cout << s;
	k--;
	while (k--) {
		cout << tail;
	}
	// returns 
	// cin >> k;
	return 0;
}
