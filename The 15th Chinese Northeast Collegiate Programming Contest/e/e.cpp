/*************************************************************************
    > File Name: e.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jun 19 19:35:43 2021
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;

void solve() {
	ll p; cin >> p;
	cout << p * 6 << ' ' << 3 << endl;
	cout << p * 3 << ' '
		 << p * 2 << ' '
		 << p * 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while (T--) solve();
	
	return 0;
}
