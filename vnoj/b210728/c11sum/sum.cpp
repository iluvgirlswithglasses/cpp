// với mỗi số trong dãy có độ dài n
// --> chọn được bao nhiêu dãy con có chứa số đó

#include <iostream>
#include <string>
using namespace std;

/**
 * vars
 * */
typedef unsigned long long ll;
const int lim = 1e9+7;
string s;
int len;
ll res = 0;

/**
 * tính từng số một
 * O(n*n)
 * */
ll gen_num(int a, int len) {
    ll r = 0;
    ll pow10 = 1;
    for (int i = 0; i < len; i++) {
        r += a * pow10;
        pow10 *= 10;
        r %= lim;
        pow10 %= lim;
    }
    return r;
}

/**
 * drivers
 * */
int main() {
	cin >> s;
    len = s.length();
    // calc
    long long k = 0;
    for (int i = 0; i < len; i++) {
        long long a = s.at(i) - '0';
        /**
         * tính từng số một
         * O(n*n)
        ll s = gen_num(a, len-i) * (i+1) % lim;
        res = (res + s) % lim;
         * */
        // như thế này số thứ i sẽ được *10 len-i lần
        k = k*10 + a*(i+1); k %= lim;
        res = res + k; res %= lim;
    }
    cout << res << endl;
	// 
    system("pause");
	return 0;
}
