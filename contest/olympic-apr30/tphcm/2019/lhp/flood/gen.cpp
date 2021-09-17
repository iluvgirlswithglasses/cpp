#include <fstream>
#include <time.h>
#include <random>
using namespace std;

int n = 500;

//
ofstream out("flood.inp");

int main() {
	srand((unsigned) time(0));
	//
	int boats = rand() % 40;
	out << n << " " << n << " " << boats << endl;
	//
	char ** arr = new char*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new char[n];
		for (int j = 0; j < n; j++) {
			rand() % 100 > 5 ? arr[i][j] = '.' : arr[i][j] = 'S';
		}
	}
	arr[rand() % n][rand() % n] = 'H';
	arr[rand() % n][rand() % n] = 'G';
	//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << arr[i][j] << " ";
		} out << endl;
	}
	//
	return 0;
}
