/*************************************************************************
    > File Name: e.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jun 26 09:28:42 2021
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define rep(i, x) for (int i = 0; i < x; i++)
constexpr int Ma = 1e6, mod = 3;
using ll=long long;
int a[Ma];
int pre[2][3][3];

#define debug(x) cerr<<#x<<" == " << x<<endl

int norm(int x) {
	if (x < 0) x %= mod;
	x += mod;
	return x % mod;
}

int main() {
	int n; cin >> n;
	rep (i, n) cin >> a[i];
	ll ans = 0;
	int cur = 0;
	pre[0][0][a[0] % 3]++;
	for (int i = 1; i < n; i++) {
		cur ^= 1;
		a[i] %= 3;
		memset(pre[cur], 0, sizeof pre[cur]);
		pre[cur][0][0] +=
			pre[cur ^ 1][0][0] +
			pre[cur ^ 1][1][] +
			pre[cur ^ 1][2][norm(1 - j - a[i])];
		pre[cur][1][0] +=
			pre[cur ^ 1][0][norm(1 - j - a[i])] +
			pre[cur ^ 1][1][norm(3 - j - a[i])] +
			pre[cur ^ 1][2][norm(2 - j - a[i])];
		pre[cur][2][0] +=
			pre[cur ^ 1][0][norm(2 - j - a[i])] +
			pre[cur ^ 1][1][norm(1 - j - a[i])] +
			pre[cur ^ 1][2][norm(3 - j - a[i])];
		for (int j = 0; j < 3; j++)	
			ans += pre[cur][0][j];
	}
	cout << ans << endl;

	return 0;
}
