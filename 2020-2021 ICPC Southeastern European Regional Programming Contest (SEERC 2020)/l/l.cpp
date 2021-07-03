/*************************************************************************
    > File Name: solve.cpp
    > Author: liupo
    > Mail: lanzongwei@gmail.com
    > Created Time: 2021-07-01 23:08:21
 ************************************************************************/

#define GOODOJ
#define SYNC 0

#ifdef GOODOJ
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <chrono>
#include <random>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#else
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <vector>
#include <limits>
#include <cassert>
#include <sstream>
#include <iterator>
#include <functional>
#endif
using namespace std;

#define endl '\n'
#define fep(i,b,e) for(int i=(b);i<(e);++i)
#define rep(i,x) for(int i=0;i<(x);++i)
#define rap(i,x) for(auto& i : (x))
#define seg(t) (t).begin(), (t).end()
#define ep emplace_back
#define mkp make_pair
#define mkt make_tuple
#define qxx(i,x) for(int i = head[x]; ~i; i = node[i].nex)
#define F first
#define S second
#define lowbit(x) ((-(x))&(x))
#define RE register
#define getchar() getchar_unlocked()
#ifdef DEBUG
void err(istream_iterator<string>){}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ' ';
	err(++it, args...);
}
#define debug(args...) {string _s=#args;replace(seg(_s),',',' ');\
cerr<<"DEBUG:";istringstream it(_s);\
err(istream_iterator<string>(it), args);cerr<<endl;}
#else
#define debug(...)
#endif

template<typename T> inline bool cmax(T& a,const T& b) {return a<b?a=b,1:0;}
template<typename T> inline bool cmin(T& a,const T& b) {return a>b?a=b,1:0;}

#ifdef GOODOJ
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
typedef __gnu_pbds::priority_queue<int> pq;
#endif
typedef std::string str;
typedef long long ll;
typedef double db;
typedef pair<int, int> pa;

const double P = acos(-1.0), eps = 1e-9;
struct point { db x ,y;};
inline int sign(db a) {return a < -eps ? -1 : a > eps;}
#define dot(p1,p2,p3) ((p2.x-p1.x)*(p3.x-p1.x)+(p2.y-p1.y)*(p3.y-p1.y))
#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))

#ifdef GOODOJ
constexpr
#else
const
#endif
int Ma = 1e6, inf = 0x3f3f3f3f, mod = 1e9 + 7;

int m[Ma], p[Ma], id[Ma], n;
ll mx[Ma], mi[Ma];

bool ck(int x) {
	if (x * 2 > n) return false;
	if (x == 0) return true;
	__gnu_pbds::priority_queue<int, greater<int> > a;
	__gnu_pbds::priority_queue<int> b;
	memset(mx, 0, sizeof(ll) * n);
	memset(mi, 0, sizeof(ll) * n);
	for (int i = 0; i < x; i++)
		mx[i] = m[id[i]] + (i ? mx[i - 1] : 0), a.push(m[id[i]]);
	for (int i = x; i < n; i++) {
		mx[i] = mx[i - 1];
		if (m[id[i]] > a.top()) mx[i] += m[id[i]] - a.top();
		a.push(m[id[i]]);
		a.pop();
	}
	for (int i = n - 1; i >= n - x; i--)
		mi[i] = p[id[i]] + (i + 1 == n ? 0 : mi[i + 1]), b.push(p[id[i]]);
	for (int i = n - x - 1; i >= 0; i--) {
		mi[i] = mi[i + 1];
		if (p[id[i]] < b.top()) mi[i] -= b.top() - p[id[i]];
		b.push(p[id[i]]);
		b.pop();
	}
	ll ret = mx[x - 1] - mi[x];
	for (int i = x; i < n - x; i++)
		cmax(ret, mx[i] - mi[i + 1]);
	return ret >= 0;
}

signed main() {
	#if SYNC==0
    ios::sync_with_stdio(false);
    cin.tie(0); cout<<fixed<<setprecision(6);
    #endif
	cin >> n;
	iota(id, id + n, 0);
	rep (i, n) cin >> m[i];
	rep (i, n) cin >> p[i];
	sort(id, id + n, [&](int a, int b) {
				if (m[a] + p[a] == m[b] + p[b])
					return m[a] > m[b];
				return m[a] + p[a] > m[b] + p[b];
			});
	int l = 0, r = n / 2 + 1;
	while (r - l > 1) {
		int mid(l + (r - l) / 2);
		if (ck(mid)) l = mid;
		else r = mid;
	}
	cout << l << endl;
    
    return 0;
}
