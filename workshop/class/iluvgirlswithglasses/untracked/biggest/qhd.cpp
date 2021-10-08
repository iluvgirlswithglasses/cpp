#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

int s = 200;
int * arr = new int[s];

int main() {
	// generator
	for (int i = 0; i < s; i++) arr[i] = rand() % 100;
	//
	int * res = new int[s];
	//
	for (int i = 0; i < s; i++) {
		res[i] = 1;
		for (int j = 0; j < i; j++) {
			if (res[i] <= res[j] && arr[i] > arr[j]) {
				res[i] = res[j] + 1;
			}
		}
	}
	//
	for (int i = 0; i < s; i++) cout << res[i] << " "; cout << endl << endl;
	cout << *max_element(res, res + s);
	getchar();
	return 0;
}
