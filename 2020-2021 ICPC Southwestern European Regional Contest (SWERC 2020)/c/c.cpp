/*************************************************************************
    > File Name: c.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com
    > Created Time: Sat Jul  3 10:34:50 2021
 ************************************************************************/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;

#define rep(i, x) for (int i = 0; i < (x); i++)

using db = double;
db X, Y;
int n;
const db eps = 1e-7;
const int Ma = 1e4 + 100;

int sign(db x) {
	return x < -eps ? -1 : x > eps;
}

int cmp(db a, db b) {
	return sign(a - b);
}

db pw(db x) {
	return x * x;
}

struct Point {
	db x, y;
	void scan() {scanf("%lf%lf", &x, &y);}
	db dis(const Point& b) const {
		return pw(x - b.x) + pw(y - b.y);
	}
} p[Ma];

bool ck(const Point& a, const Point& b, const db& x) {
	return cmp(a.dis(b), x * x * 4) == -1;
}

db res[4][Ma];
Point s{0, 0}, t;
int f[Ma];

int findz(int x)
{
    if(f[x] == x) return x;
    return f[x] = findz(f[x]);
}

bool ck(db x) {
    for(int i = 0;i < n; ++i) f[i] = i;
	for (int i = 0; i < n; i++)
		res[0][i] = p[i].y - x, res[1][i] = p[i].y + x,
		res[2][i] = p[i].x - x, res[3][i] = p[i].x + x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (i != j) {
			if (ck(p[i], p[j], x) || findz(i) == findz(j)) {
				res[0][i] = min(res[0][i], res[0][j]);
				res[1][i] = max(res[1][i], res[1][j]);
				res[2][i] = min(res[2][i], res[2][j]);
				res[3][i] = max(res[3][i], res[3][j]);
				f[findz(i)] = findz(j);
			}
		}
		if (sign(res[0][i]) == -1 and cmp(res[1][i], Y) == 1) return false;
		if (sign(res[2][i]) == -1 and cmp(res[3][i], X) == 1) return false;
		if (sign(res[0][i]) == -1 and sign(res[2][i]) == -1) return false;
		if (cmp(res[1][i], Y) == 1 and cmp(res[3][i], X) == 1) return false;
	}
	return true;
}

int main() {
	scanf("%lf%lf", &X, &Y);
	t = {X, Y};
	scanf("%d", &n);
	rep (i, n) p[i].scan();
	db l = 0, r = max(X,Y);
	while(r - l > eps) {
		db mid((l + r) / 2);
		if (ck(mid)) l = mid;
		else r = mid;
	}
	printf("%.6f\n", l);
	return 0;
}
