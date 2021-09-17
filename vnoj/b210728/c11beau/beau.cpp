#include <iostream>
using namespace std;

/**
 * vars
 * */
int ca, cb, ma, mb;

/**
 * perf
 * */
long long calc(long long _ca, long long _cb, long long _ma, long long _mb) {
    if (_ca > _cb * _ma) {
    	return min(_ca, _ma * (_cb + 1)) + _cb;
    }
    return _ca + _cb;
}

/**
 * drivers
 * */
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> ca >> cb >> ma >> mb;
		//
		if (ma == 0) {
			cout << min(cb, mb) << endl;
		} else if (mb == 0) {
			cout << min(ca, ma) << endl;
		} else {
			if (ca < cb) {
				ca ^= cb; cb ^= ca; ca ^= cb;
				ma ^= mb; mb ^= ma; ma ^= mb;
			}
			cout << calc(ca, cb, ma, mb) << endl;
		}
	}
	//
	return 0;
}

