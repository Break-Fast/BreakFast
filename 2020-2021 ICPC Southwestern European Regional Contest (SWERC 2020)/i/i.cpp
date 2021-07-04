#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;
const int inf = 0x3f3f3f3f;

int n, m;
int cnt, head[M + 5];

struct enode
{
    int v, nx;
} Edge[M * 2 + 5];

void init()
{
    cnt = 0;
    for(int i = 1; i <= n; ++i)
    {
        head[i] = -1;
    }
}

void add(int u, int v)
{
    Edge[cnt].v = v;
    Edge[cnt].nx = head[u];
    head[u] = cnt++;
}

int p[M + 5];
int mx;
int dis[M + 5];
int q[M + 5], l, r;

void bfs(int s)
{
    for(int i = 1; i <= n; ++i) dis[i] = inf;
    dis[s] = 0;
    l = 1, r = 0;
    q[++r] = s;
    while(l <= r)
    {
        int u = q[l++];
        for(int i = head[u]; ~i; i = Edge[i].nx)
        {
            int v = Edge[i].v;
            if(dis[v] == inf)
            {
                dis[v] = dis[u] + 1;
                q[++r] = v;
            }
        }
    }
    for(int i = 1; i <= n; ++i) mx = max(mx, dis[i]);
}

void work()
{
    scanf("%d %d", &n, &m); init();
    for(int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d %d", &u, &v);
        add(u, v), add(v, u);
    }
    for(int i = 1; i <= n; ++i) p[i] = i;
    srand(time(NULL));
    random_shuffle(p + 1, p + n + 1);
    mx = 0;
    for(int i = 1; i <= n; ++i)
    {
        bfs(p[i]);
        if(i % 10 && 1.0 * clock() / CLOCKS_PER_SEC > 5.5) break;
    }
    if(mx == inf)   printf("-1\n");
    else
    {
        for(int i = 0; ; ++i)
        {
            if((1<<i) >= mx)
            {
                printf("%d\n", i);
                return;
            }
        }
    }
}

int main()
{
    work();
    return 0;
}
