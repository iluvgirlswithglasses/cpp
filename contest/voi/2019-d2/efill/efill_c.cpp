
// chứng minh trong nháp số 1
// sau bài bfc34/triangle

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

struct pt {
	ld x, y;
	void set(ld a, ld b) {
		x = a; y = b;
	}
	void from(pt a, pt b) {
		x = a.x - b.x;
		y = a.y - b.y;
	}
};

const int N = 104;
const ld PI = acos((ld)0)*2;
int n;
ll gx, gy;
pt a, b, c, d, g, arr[N];

/**
 * quick math
 * */
ld sq(ld x) {
	return x * x;
}

/**
 * geomery utils
 * */
ld angel_of(ld x, ld y) {
	if (y < 0) {
		return PI*2 - acos(x / sqrt(x*x + y*y));
	}
	return acos(x / sqrt(x*x + y*y));
}

ld angel_of(pt p) {
	return angel_of(p.x - g.x, p.y - g.y);
}

ld d_p2p(pt i, pt j) {
	return sqrt(
		(i.x - j.x)*(i.x - j.x) + 
		(i.y - j.y)*(i.y - j.y)
	);
}

ld d_p2d(pt i, pt a, pt b) {
	pt d; d.set(b.y - a.y, a.x - b.x);
	return (d.x*i.x + d.y*i.y - d.x*a.x - d.y*a.y) / sqrt(sq(d.x) + sq(d.y));
}

bool is_samepoint(pt a, pt b) {
	return a.x == b.x && a.y == b.y;
}

bool is_sameline(pt a, pt b, pt c) {
	pt d0; d0.from(a, b);
	pt d1; d1.from(a, c);
	return abs(d0.x/d0.y) == abs(d1.x/d1.y);
}

bool is_intrungtruc(pt i, pt a, pt b) {
	pt v; v.from(a, b);
	pt c; c.set((a.x + b.x) / 2, (a.y + b.y) / 2);
	return v.x*i.x + v.y*i.y - v.x*c.x - v.y*c.y == 0;
}

/**
 * xác định mối quan hệ giữa dây dẫn nguồn & cổng
 * */
bool e_sameline() {
	// 4 điểm cùng nằm trên đường thẳng
	return is_sameline(a, b, c) && is_sameline(a, b, d);
}

bool e_intrungtruc() {
	// trường hợp nằm trên đường trung trực
	// có thể xét một trong 2 c / d thôi cũng được...
	return is_intrungtruc(c, a, b) && is_intrungtruc(d, a, b);
}

/**
 * drivers
 * */
string f2s(ld f) {
	stringstream stream;
	stream << fixed << setprecision(2) << f;
	return stream.str();
}

void prf() {
	for (int i = 0; i < n; i++) {
		cout << arr[i].x << " " << arr[i].y << " (" << angel_of(arr[i]) * 180 / PI << "), ";
	} cout << "\n";
}

int main() {
	//@ input
	ios_base::sync_with_stdio(false); cin.tie(0);
	string t; cin >> t;
	ifstream inp("custom_test/" + t + ".in");
	cin.rdbuf(inp.rdbuf());
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
		gx += arr[i].x;
		gy += arr[i].y;
	}
	cin >> c.x >> c.y >> d.x >> d.y;
	a = arr[0]; b = arr[1];
	g.set(gx/n, gy/n);

	//@ sắp xếp các đỉnh theo một chiều
	sort(arr, arr+n, [](pt i, pt j){
		return angel_of(i) < angel_of(j);
	});

	//@ tính vòng
	ld res = 0, longest = 0;
	for (int i = 0; i < n; i++) {
		ld d = d_p2p(arr[i], arr[(i+1)%n]);
		res += d;
		if (
			(is_samepoint(a, arr[i]) && is_samepoint(b, arr[(i+1)%n])) ||
			(is_samepoint(b, arr[i]) && is_samepoint(a, arr[(i+1)%n]))
		) {
			continue;
		}
		longest = max(longest, d);
	}
	res = res - d_p2p(a, b) - longest;

	//@ tính dây nguồn
	ld pre = res;
	clog << "pre: " << pre << "\n";
	if (e_sameline()) {
		ld len[6] = {
			d_p2p(a, b), d_p2p(c, d), d_p2p(a, c), d_p2p(a, d), d_p2p(b, c), d_p2p(b, d)
		};
		res += *max_element(len, len+6);
		clog << "case sameline: " << res - pre << "\n";
	} else if (e_intrungtruc()) {
		// đường trung trực
		// xem chứng minh trong ~siêu nháp~
		res += d_p2p(c, d);
		ld  da = min(d_p2p(c, a), d_p2p(d, a)),
			ab = d_p2p(a, b),
			ah = ab / 2,
			dh = sqrt(da*da - ah*ah);
		if (
			acos((sq(da) + sq(da) - sq(ab)) / (da*da*2)) > (PI * 2 / 3)
		) {
			// trường hợp có góc > 120 độ --> không dùng fermat
			res += da * (ld)2.0;
			clog << "case sqr b: " << res - pre << "\n";
		} else {
			// nghĩa địa fermat
			ld 	hf = ah * tan(PI/6),
				af = sqrt(hf*hf + ah*ah),
				df = dh - hf;
			res += df + af*2;
			clog << "clog << da << ab << ah << dh\n << hf << af << df;\n";
			clog << da << " " << ab << " " << ah << " " << dh << "\n" << hf << " " << af << " " << df << "\n";
			clog << "case sqr a: " << res - pre << "\n";
		}
	} else {
		res += d_p2p(a, b) * (sqrt((ld)3) + 1);
		clog << "case rect: " << res - pre << "\n";
	} 

	//@ xong bài !
	cout << f2s(res) << "\n";
	// check ans
	ifstream ians("custom_test/" + t + ".out");
	string ans; ians >> ans;
	cout << ans << "\n";
	cout << (f2s(res) == ans) << "\n";
	return 0;
}
