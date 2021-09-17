#include <iostream>
using namespace std;

typedef long long int lli;

//@ vars
int n;
int * arr;
int cnt[(int) 5e5+1];	// counts


//@ calc
lli calc() {
	lli res = 0;
	// two pointers
	int l = 0, r = 0;
	for (; r < n; r++) {
		int i = arr[r];
		cnt[i]++;
		if (cnt[i] > 2) {
			// we can only stop once we have deleted the number
			// that causes the array ugly
			while (cnt[i] > 2) cnt[arr[l++]]--;
		}
		//
		res += r - l + 1;
	}
	//
	return res;
}


//@ driver
void getinp() {
	cin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
}

int main() {
	getinp();
	cout << calc() << endl;
	//
	system("pause");
	return 0;
}
