/*************************************************************************
    > File Name: a.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jun 26 10:25:35 2021
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; cin >> s;
	int cnt = 0, pre = 0;
	for (int i = s.size() - 1; i >= 0; --i) {
		if (s[i] == '1')
			cnt += s.size() - 1 - i - pre, ++pre;
		cnt %= 3;
	}
	if (cnt == 0) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	
	return 0;
}
