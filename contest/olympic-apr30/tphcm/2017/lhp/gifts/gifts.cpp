#include <bits/stdc++.h>
using namespace std;

#define lli long long int

vector<lli> arr;
vector<lli> val;
// id wont be dup

//
void genval() {
	for (int i = 0; i < arr.size(); i++) {
		// 2 số liền kề nhau không cộng nhau, vì cũng chẳng ra gì cả
		for (int j = i + 2; j < arr.size(); j++) {
			lli s = arr[i] + arr[j];
			if (!(s & 1)) val.push_back(s / 2);	// min(arr[x]) == 1 -> s >= 2
		}
	}
	sort(val.begin(), val.end(), [](lli i, lli j){return i < j;});
	// cout << "sort val completed\n";
}

int calc() {
	int counts = 0;
	int index = 0;
	for (int i = 0; i < val.size(); i++) {
		if (index == arr.size()) break;
		// id shouldn't be duplicated
		// however,...
		// ...if value in arr can be duplicated, use i -= 1;
		if (val[i] > arr[index]) {
			index += 1;
		} else if (val[i] == arr[index]) {
			index += 1;
			counts += 1;
		}
	}
	return counts;
}

//
void getinp() {
	ifstream inp("gifts.inp");
	lli n;
	while (inp >> n) arr.push_back(n);
	sort(arr.begin(), arr.end(), [](lli i, lli j){return i < j;});
	// cout << "sort inp completed\n";
}

int main() {
	getinp();
	genval();
	cout << calc();
	//
	getchar();
	return 0;
}
