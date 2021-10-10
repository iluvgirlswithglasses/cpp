#include <string>
#include <iostream>
using namespace std;

int quick_pow(int n) {
    static int pow10[10] = {
        11, // magic trick, fools numbers to degrade themselves to below 11
        11, 
        111, 
        1111, 
        11111, 
        111111, 
        1111111, 
        11111111, 
        111111111, 
        1111111111
    };

    return pow10[n]; 
}


bool calc(int n) {
	int len = to_string(n).length() - 1;
	//
	while (n >= 11) {
		cout << n << " ";
		while (n < quick_pow(len)) {
			len -= 1;
		}
		//
		n %= quick_pow(len);
	}
	return n == 0;
}

//
int main() {
	int t, n; cin >> t;
	while (t--) {
		cin >> n;
		if (calc(n)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	//
	return 0;
}
