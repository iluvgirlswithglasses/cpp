#include <bits/stdc++.h>
using namespace std;

// perfs
void calc() {
	int n; cin >> n;
	//
	int ** student = new int*[n];	// student[i]: {skill, school}
	// those are dp, which will be updated after every k-calculation loop
	int * schoolcount = new int[n];	// student counts
	int * schoolres = new int[n];	// total skill points
	// input
	for (int i = 0; i < n; i++) {
		student[i] = new int[2];
		cin >> student[i][1];
		//
		schoolres[i] = 0;
		schoolcount[i] = 0;
	}
	for (int i = 0; i < n; i++) cin >> student[i][0];
	//
	sort(student, student + n, [](int * i, int * j) {
		return i[0] > j[0];
	});	// student with more skill appear first
	// calc
	// so...
	int crk = 0;
	for (int i = 0; i < n; i++) {
		int * cr = student[i];
		schoolcount[ cr[1] ] += 1;
		schoolres[ cr[1] ] += cr[0];
		if (schoolcount[ cr[1] ] > crk) {
			cout << schoolres[ cr[1] ] << " ";
			crk += 1;
		}
	}
	// there are n numbers to be printed
	// but most of them are 0, which is not calculated by following loop
	for (int i = crk; i < n; i++) cout << 0 << " "; 
	cout << endl;
	// delete !
	for (int i = 0; i < n; i++) {
		delete[] student[i];
	}
	delete[] student;
	delete[] schoolres;
}

int main() {
	int t; cin >> t;
	while (t--) {
		calc();
	}
	return 0;
}
