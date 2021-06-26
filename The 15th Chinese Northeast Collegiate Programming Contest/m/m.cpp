/*************************************************************************
    > File Name: m.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jun 19 18:23:26 2021
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

map<string, string> tb = {
	{"iu", "q"}, {"ei", "w"},
	{"uan", "r"}, {"ue", "t"},
	{"un", "y"}, {"sh", "u"},
	{"ch", "i"}, {"uo", "o"},
	{"ie", "p"}, {"ong", "s"},
	{"iong", "s"}, {"ai", "d"},
	{"en", "f"}, {"eng", "g"},
	{"ang", "h"}, {"an", "j"},
	{"uai", "k"}, {"ing", "k"},
	{"uang", "l"}, {"iang", "l"},
	{"ou", "z"}, {"ia", "x"},
	{"ua", "x"}, {"ao", "c"},
	{"zh", "v"}, {"ui", "v"},
	{"in", "b"}, {"iao", "n"},
	{"ian", "m"},
{"a", "a"},
{"b", "b"},
{"c", "c"},
{"d", "d"},
{"e", "e"},
{"f", "f"},
{"g", "g"},
{"h", "h"},
{"i", "i"},
{"j", "j"},
{"k", "k"},
{"l", "l"},
{"m", "m"},
{"n", "n"},
{"o", "o"},
{"p", "p"},
{"q", "q"},
{"r", "r"},
{"s", "s"},
{"t", "t"},
{"u", "u"},
{"v", "v"},
{"w", "w"},
{"x", "x"},
{"y", "y"},
{"z", "z"}
};

void cal(string t) {
	if (t.length() == 1) {
		cout << t << t; return ;
	}
	if (t.length() == 2) {
		cout << t; return ;
	}
	if (tb.count(t)) {
		cout << t[0] << tb[t];
		return ;
	}
	string p;
	for (int i = 0; i < (int)t.length() - 1; i++) {
		p += t[i];
		if (tb.count(p) and tb.count(t.substr(i + 1))) {
			cout << tb[p] << tb[t.substr(i + 1)];
			return ;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; 
	while (getline(cin, s)) {
		istringstream is(s);
		string t;
		bool can = false;
		while (is >> t) {
			if (can) cout << ' ';
			else can = true;
			cal(t);
		}
		cout << endl;
	}
	
	return 0;
}
