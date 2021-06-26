/*************************************************************************
    > File Name: i.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jun 19 18:06:25 2021
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int dish[] = {7,27,41,49,63,78,108};
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define rep(i, x) for (int i = 0; i < x; i++)

void solve() {
	int tot = 0;
	int n; cin >> n;
	rep (i, n) {
		int id; cin >> id;
		tot += dish[id - 1];
	}
	int ans = tot;
	if (tot >= 69) ans = min(ans, tot - 15);
	if (tot >= 89) ans = min(ans, tot - 30);
	if (tot >= 120) ans = min(ans, tot - 50);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while (T--) solve();
	
	return 0;
}
