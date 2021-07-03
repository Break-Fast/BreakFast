/*************************************************************************
    > File Name: k.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com
    > Created Time: Sat Jul  3 10:02:05 2021
 ************************************************************************/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;

using ll=long long;
#define mkp make_pair
const int Ma = 3e5 + 100, mod1 = 1e9 + 7, mod2 = 119 << 23 | 1;

struct Hash {
	ll mod, sg[Ma], pw[Ma], k;
	Hash(ll md, ll k=31) : mod(md), k(k) {
		pw[0] = 1; pw[1] = k;
		for (int i = 2; i < Ma; i++)
			pw[i] = pw[i - 1] * k % mod;
	}
	ll norm(ll x) {
		if (x < 0) x %= mod, x += mod;
		return x % mod;
	}
	void build(string s) {
		sg[0] = 0;
		for (int i = 0; i < (int)s.length(); i++)
			sg[i + 1] = (sg[i] * k % mod + s[i] - 'A' + 1) % mod;
	}
	ll seg(int l, int r) {
		++l, ++r;
		return norm(sg[r] - sg[l - 1] * pw[r - l + 1]);
	}
};

struct HASH {
	size_t operator () (const pair<ll, ll>& t) const {
		return t.first + t.second + t.first * t.second;
	}
};

Hash k1(mod1), k2(mod2);
__gnu_pbds::cc_hash_table<pair<ll, ll>, int, HASH> mp;
int n;

bool ck(int x) {
	mp.clear();
	for (int i = 0; i + x - 1 < n; i++) {
		mp[mkp(k1.seg(i, i + x - 1), k2.seg(i, i + x - 1))]++;
	}
	for (const auto& i : mp) if (i.second == 1) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; cin >> s;
	n = s.length();
	k1.build(s), k2.build(s);
	int l = 0, r = s.length();
	while (r - l > 1) {
		int mid(l + (r - l) / 2);
		if (ck(mid)) r = mid;
		else l = mid;
	}
	assert(ck(r));
	for (int i = 0; i + r - 1 < n; i++) if (mp[mkp(k1.seg(i, i + r - 1 ), k2.seg(i, i + r - 1))] == 1) {
		cout << s.substr(i, r) << endl;
		return 0;
	}
	assert(false);

	return 0;
}
