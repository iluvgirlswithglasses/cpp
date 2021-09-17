#include <bits/stdc++.h>
using namespace std;

int s, n, d;
// if found one => delete that index
vector<int> sx;
vector<int> sy;
vector<int> sr;
vector<int> sm;
//
vector<int> nx;
vector<int> ny;

// utils
void del_rada(int i) {
	sx.erase(sx.begin() + i);
	sy.erase(sy.begin() + i);
	sr.erase(sr.begin() + i);
	sm.erase(sm.begin() + i);
}

double points_dist(int i, int j) {
	return abs(sqrt(
		pow(nx[i] - sx[j], 2) + pow(ny[i] - sy[j], 2)
	));
}

bool is_inline(int i, int j) {
	double travel_distance = abs(sqrt(
		pow(nx[i] - nx[i+1], 2) + pow(ny[i] - ny[i+1], 2)
	));
	//
	double a_len = points_dist(i, j);
	double b_len = points_dist(i + 1, j);
	// 
	if (travel_distance >= a_len && travel_distance >= b_len) return true;
	//
	return a_len <= sr[j] + d || b_len <= sr[j] + d;
}

//
int calc() {
	int total = 0;
	// có n + 2 trạm
	for (int i = 0; i < nx.size() - 1; i++) {
		// phương trình đường thẳng xài hồi lớp 10
		int a = ny[i+1] - ny[i], 
			b = -(nx[i+1] - nx[i]);
		int c = - a*nx[i] - b*ny[i];
		// check xem có đứa nào thỏa k
		for (int j = sx.size() - 1; j > -1; j--) {
			double dist = abs(
				(double) (a*sx[j] + b*sy[j] + c) / 
				(double) (sqrt(pow(a, 2) + pow(b, 2)))
			);
			//
			if (dist <= (double) (sr[j] + d) && is_inline(i, j)) {
				// printf("GET [%d, %d] %d %d\n", sx[j], sy[j], sr[j], sm[j]);
				//
				total += sm[j];
				del_rada(j);
			}
		}
	}
	//
	return total;
}

// io
void getinp() {
	ifstream inp("concor.inp");
	inp >> s >> n >> d;
	//
	for (int i = 0; i < s; i++) {
		int x, y, r, m; inp >> x >> y >> r >> m;
		sx.push_back(x);
		sy.push_back(y);
		sr.push_back(r);
		sm.push_back(m);
	}
	//
	nx.push_back(0); ny.push_back(0);
	for (int i = 0; i < n; i++) {
		int x, y; inp >> x >> y;
		nx.push_back(x);
		ny.push_back(y);
	}
	nx.push_back(0); ny.push_back(0);
}

// driver
int main() {
	getinp();
	cout << calc();
	//
	getchar();
	return 0;
}
