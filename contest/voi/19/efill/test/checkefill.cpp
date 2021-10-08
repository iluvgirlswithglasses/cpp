/*input

*/
#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define bit(x, y) ((x >> y) & 1LL)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; i++)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; i--)
// const int N=;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}

#define EPS 1E-2
int main(int argc, char *argv[]) {
#ifdef THEMIS
	registerTestlibThemis("efill.inp", "efill.out");
#else
	registerTestlibCmd(argc, argv);
#endif // THEMIS
	double Answer = ans.readDouble();
	double Cont = ouf.readDouble();
	if (!doubleCompare(Answer, Cont, EPS))
		quitf(_wa, "Expected %.6lf, found %.6lf, error %.6lf", Answer, Cont, doubleDelta(Answer, Cont));
	quitf(_ok, "Correct solution, Expected %.6lf, found %.6lf", Answer, Cont);
}