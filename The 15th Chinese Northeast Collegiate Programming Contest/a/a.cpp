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
#define endl '\n'
const int inf = 0x3f3f3f3f, mod = 119 << 23 | 1, Ma = 3e7;

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

void solve() {
	int n; cin >> n;
	Mint ans;
	for (int i = 1; i <= n; i++) {
		ans = ans + C(n * n - i, n - 1);
	}
	ans = ans * n * fac[n] * fac[n * n - n];
	cout << ans.x << endl;
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
