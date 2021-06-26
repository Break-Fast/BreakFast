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
#define lowbit(x) ((x)&(-(x)))
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

#define ep emplace_back

ostream& operator << (ostream& out, Mint x) {
	out << x.x;
	return out;
}

ll a[Ma];
Mint pw[Ma];
int n;

struct SegTree {
	Mint sum[Ma * 4];
	int tag[Ma * 4], lazy[Ma * 4];
	void build(int o, int l, int r) {
		lazy[o] = 0;
		if (l == r) {
			sum[o] = a[l];
			tag[o] = 0;
			return ;
		}
		int mid((l + r) >> 1);
		build(o << 1, l, mid);
		build(o << 1 | 1, mid + 1, r);
		push(o);
	}
	void push(int o) {
		sum[o] = sum[o << 1] + sum[o << 1 | 1];
		tag[o] = min(tag[o << 1], tag[o << 1 | 1]);
	}
	void pull(int o) {
		sum[o << 1] = sum[o << 1] * pw[lazy[o]];
		sum[o << 1 | 1] = sum[o << 1 | 1] * pw[lazy[o]];
		lazy[o << 1] += lazy[o];
		lazy[o << 1 | 1] += lazy[o];
		lazy[o] = 0;
	}
	void modify(int o, int l, int r, int L, int R) {
		if (r < L or R < l) return ;
		int mid((l + r) >> 1);
		if (tag[o] < 32) {
			if (l == r) {
				++tag[o];
				a[l] += lowbit(a[l]);
				sum[o] = a[l];
				return ;
			}
			modify(o << 1, l, mid, L, R);
			modify(o << 1 | 1, mid + 1, r, L, R);
			push(o);
		} else {
			if (L <= l and r <= R) {
				sum[o] = sum[o] * 2;
				lazy[o]++;
				return ;
			}
			pull(o);
			modify(o << 1, l, mid, L, R);
			modify(o << 1 | 1, mid + 1, r, L, R);
			push(o);
		}
	}
	void modify(int l, int r) {
		modify(1, 1, n, l, r);
	}
	Mint query(int o, int l, int r, int L, int R) {
		if (r < L or R < l) return 0;
		if (L <= l and r <= R) return sum[o];
		pull(o);
		int mid((l + r) >> 1);
		return query(o << 1, l, mid, L, R) +
		       query(o << 1 | 1, mid + 1, r, L, R);

	}
	Mint query(int l, int r) {
		return query(1, 1, n, l, r);
	}
} st;

void solve() {
	cin >> n;
	rep (i, n) cin >> a[i + 1];
	st.build(1, 1, n);
	int m; cin >> m;
	rep (i, m) {
		int op, l, r; cin >> op >> l >> r;
		if (op == 1) st.modify(l, r);
		else cout << st.query(l, r) << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	pw[0] = 1; pw[1] = 2;
	for (int i = 2; i < Ma; i++) pw[i] = pw[i - 1] * 2;
	int T; cin >> T;
	while (T--) solve();
	
	return 0;
}
