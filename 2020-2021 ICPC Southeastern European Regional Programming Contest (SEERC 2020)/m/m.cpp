/*************************************************************************
    > File Name: m.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jun 26 10:05:26 2021
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

const int Ma = 1e6;
int c[Ma];
int cn[Ma];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, m; cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
	}
	for (int i = 0; i < n * k; i++) {
		int t; cin >> t; ++cn[t];
		cout << cn[t]; cout << " \n"[i == n * k - 1];
	}
	
	return 0;
}
