/*************************************************************************
    > File Name: a.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jun 19 19:47:20 2021
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define seg(x) x.begin(), x.end()
#define rep(i, x) for (int i = 0; i < x; i++)
#define rap(i, x) for (auto& i : (x))
#define endl '\n'
const int inf = 0x3f3f3f3f, mod = 119 << 23 | 1, Ma = 1e6;

ll inv(ll x, ll b = mod - 2) {
	ll s = 1;
	for (x %= mod; b; b >>= 1, x = x * x % mod)
		if (b & 1) s = s * x % mod;
	return s;
}

struct Mint {
	ll x;
	ll norm(ll x) {
		if (x < 0) x %= mod, x += mod;
		x %= mod;
		return x;
	}
	Mint() {x = 0;}
	Mint(ll x) {
		this->x = norm(x);
	}
	Mint operator + (const Mint& b) {
		return x + b.x;
	}
	Mint operator - (const Mint& b) {
		return x - b.x;
	}
	Mint operator * (const Mint& b) {
		return x * b.x;
	}
	Mint operator / (const Mint& b) {
		return x * inv(b.x);
	}
	Mint& operator = (const ll& x) {
		this->x = norm(x);
		return *this;
	}
};

Mint inv(Mint x) {
	return Mint(inv(x.x));
}

Mint fac[Ma], ifac[Ma];

Mint C(int n, int m) {
	if (m < 0 or m > n) return 0;
	return fac[n] * ifac[m] * ifac[n - m];
}

vector<int> g[Ma];
#define ep emplace_back
Mint f[Ma][3];

ostream& operator << (ostream& out, Mint x) {
	out << x.x;
	return out;
}

void dfs(int u, int fa=0) {
	f[u][0] = 1;
	f[u][1] = 1;
	f[u][2] = 1;
	if (g[u].size() == 1 and u != 1) {
		f[u][2] = 0;
		return ;
	}
	rap (i, g[u]) if (i != fa) dfs(i, u);
	rap (v, g[u]) if (v != fa) {
		f[u][0] = f[u][0] * f[v][1];
		f[u][1] = f[u][1] * (f[v][1] + f[v][2]);
		f[u][2] = f[u][2] * (f[v][0] + f[v][1] + f[v][2]);
	}
	f[u][2] = f[u][2] - f[u][0];
}

void solve() {
	int n; cin >> n;
	rep (i, n + 1) g[i].clear();
	rep (i, n - 1) {
		int u, v; cin >> u >> v;	
		g[u].ep(v), g[v].ep(u);
	}
	dfs(1);
	cout << (f[1][1] + f[1][2]).x << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fac[0] = fac[1] = 1;
	ifac[0] = ifac[1] = 1;
	for (int i = 2; i < Ma; i++) fac[i] = fac[i - 1] * i;
	ifac[Ma - 1] = inv(fac[Ma - 1]);
	for (int i = Ma - 2; i > 1; i--)
		ifac[i] = ifac[i + 1] * (i + 1);
	int T; cin >> T;
	while (T--) solve();
	
	return 0;
}
