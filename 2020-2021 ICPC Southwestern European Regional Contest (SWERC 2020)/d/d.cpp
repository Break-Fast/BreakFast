/*************************************************************************
    > File Name: d.cpp
    > Author: ghost_lzw
    > Mail: lanzongwei@gmail.com 
    > Created Time: Sat Jul  3 12:56:38 2021
 ************************************************************************/

#include<bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

using ll = long long;

const int Ma = 1e6 + 100, inf = 0x3f3f3f3f;

#define rep(i, x) for (int i = 0; i < x; i++)
#define qxx(i, x) for (int i = head[x]; ~i; i = node[i].nxt)

struct Node {
	int v, w, id, nxt;
} node[Ma];

int head[Ma], cnt;

void add(int u, int v, int w, int id) {
	node[cnt].v = v, node[cnt].w = w; node[cnt].id = id;
	node[cnt].nxt = head[u]; head[u] = cnt++;
}

typedef __gnu_pbds::priority_queue<int> pq;
bool vis[Ma];

ll dis[Ma]; bool dvis[Ma];
#define mkp make_pair
#define F first
#define S second

void dij(int u) {
	memset(dis, inf, sizeof dis);
	dis[u] = 0;
	__gnu_pbds::priority_queue<pair<ll, int> > q;
	q.push(mkp(0, 0));
	while (!q.empty()) {
		auto t = q.top(); q.pop();
		if (dvis[t.S]) continue;
		dvis[t.S] = true;
		qxx(i, t.S) if (dis[node[i].v] > dis[t.S] + node[i].w) {
			dis[node[i].v] = dis[t.S] + node[i].w;
			q.push(mkp(-dis[node[i].v], node[i].v));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(head, -1, sizeof head);
	int n, m; ll l, r; cin >> n >> m >> l >> r;
	rep (i, m) {
		int u, v, w; cin >> u >> v >> w;
		add(u, v, w, i);
		add(v, u, w, i);
	}
	dij(0);
	for (int i = 0; i < n; i++) if (2 * dis[i] < r) {
		qxx(j, i) vis[node[j].id] = true;
	}
	int res = 0;
	for (int i = 0; i < m; i++) res += vis[i];
	cout << res << endl;
	
	return 0;
}
