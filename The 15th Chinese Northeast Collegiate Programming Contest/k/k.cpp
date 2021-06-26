/*************************************************************************
    > File Name: k.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jun 19 19:07:38 2021
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int Ma = 1e6, inf=0x3f3f3f3f;
#define seg(x) x.begin(), x.end()
#define rep(i, x) for (int i = 0; i < x; i++)
#define endl '\n'
int fa[Ma], siz[Ma];
using ll=long long;
ll ans;
void init(int n) {
	ans = 0;
	for (int i = 0; i < n; i++) fa[i] = i, siz[i] = 1;
}

int find(int x) {return fa[x] = fa[x] == x ? x : find(fa[x]);}
ll cal(int p) {
	return (ll)p * (p - 1) / 2;
}
void unio(int a, int b) {
	int p1 = find(a), p2 = find(b);
	if (p1 == p2) return ;
	ans -= cal(siz[p1]);
	ans -= cal(siz[p2]);
	fa[p2] = p1;
	siz[p1] += siz[p2];
	ans += cal(siz[p1]);
}

#define rap(i, x) for (auto& i : (x))
#define F first
#define S second
ll res[Ma];

void solve() {
	int n, m, q; cin >> n >> m >> q; 
	init(n);
	vector<tuple<int, int, int> > gs(m);
	rap (i, gs) cin >> get<1>(i) >> get<2>(i) >> get<0>(i);
	sort(seg(gs), greater<tuple<int, int, int> >());
	vector<pair<int, ll*> > qu(q);
	int cnt = 0;
	rap (i, qu) cin >> i.F, i.S = res + (cnt++);
	sort(seg(qu), greater<pair<int, ll*> >());
	int pos = 0;
	rap (i, qu) {
		while (pos < m and get<0>(gs[pos]) >= i.F)
			unio(get<1>(gs[pos]) - 1, get<2>(gs[pos]) - 1),
			++pos;
		*i.S = ans;
	}
	rep (i, q) cout << res[i] << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while (T--) solve();
	
	return 0;
}
