/*************************************************************************
    > File Name: j.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jun 19 21:20:17 2021
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

using db=double;

const db PI = acos(-1);

struct P3 {
	db x, y, z;
	P3 operator / (db k1) {return {x / k1, y / k1, z / k1};}
	db abs() {return sqrt(x * x + y * y +z * z);}
	P3 unit() {return (*this) / abs();}
	void print() {
		cout << x << ' ' << y << ' ' << z << endl;
	}
};

P3 turn3D(db k1, P3 l, P3 p) {
	l = l.unit(); P3 ans; db c = cos(k1), s = sin(k1);
	ans.x = p.x * (l.x * l.x * (1 - c) + c) +
		    p.y * (l.x * l.y * (1 - c) - l.z * s) +
   		    p.z * (l.x * l.z * (1 - c) + l.y * s);
	ans.y = p.x * (l.x * l.y * (1 - c) + l.z * s) +
		    p.y * (l.y * l.y * (1 - c) + c) +
			p.z * (l.y * l.z * (1 - c) - l.x * s);
	ans.z = p.x * (l.x * l.z * (1 - c) - l.y * s) +
		    p.y * (l.y * l.z * (1 - c) + l.x * s) +
			p.z * (l.z * l.z * (1 - c) + c);
	return ans;
}

void solve() {
	P3 go, p; cin >> go.x >> go.y >> go.z;
	cin >> p.x >> p.y >> p.z;
	P3 pp = p, qq = p;
	db r; cin >> r; r = PI * r / 180;
	pp = turn3D(r, go, p);
	qq = turn3D(-r, go, p);
	if (pp.z > qq.z) pp.print();
	else qq.print();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(10);
	int T; cin >> T;
	while (T--) solve();
	
	return 0;
}
