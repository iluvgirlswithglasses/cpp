#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
	int a, b;
	//
	cin >> a;
	cin >> b;
	//
	a ^= b;
	b ^= a;
	a ^= b;
	//
	printf("\nres:\n%d\n%d\n", a, b);
	/* code */
	cin.get(); getchar();
	return 0;
}