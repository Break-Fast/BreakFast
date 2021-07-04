#include <bits/stdc++.h>
using namespace std;

const int M = (int)1e5;
const int N = (int)2e5;

int n;
int day[M + 5];
int tot, rt[N + 5], ops;
struct tnode
{
    int lc, rc, cnt;
} tree[N * 40 + 5];

inline void push_up(int k)
{
    tree[k].cnt = tree[tree[k].lc].cnt + tree[tree[k].rc].cnt;
}

void update(int p, int q, int l, int r, int a, int b)
{
    if(l == r)
    {
        tree[q].cnt += b;
        return;
    }
    int mid = (l + r) >> 1;
    if(a <= mid)
    {
        tree[q].lc = ++tot, tree[tree[q].lc].cnt = tree[tree[p].lc].cnt, tree[q].rc = tree[p].rc;
        update(tree[p].lc, tree[q].lc, l, mid, a, b);
    }
    else
    {
        tree[q].rc = ++tot, tree[tree[q].rc].cnt = tree[tree[p].rc].cnt, tree[q].lc = tree[p].lc;
        update(tree[p].rc, tree[q].rc, mid + 1, r, a, b);
    }
    push_up(q);
}

int query(int p, int l, int r, int a, int b)
{
    if(l >= a && r <= b)    return tree[p].cnt;
    int mid = (l + r) >> 1, s = 0;
    if(a <= mid && tree[p].lc)    s += query(tree[p].lc, l, mid, a, b);
    if(mid < r  && tree[p].rc)    s += query(tree[p].rc, mid + 1, r, a, b);
    return s;
}

void work()
{
    cin >> n;
    rt[ops = 0] = ++tot;
    string s; cin.ignore();
    for(int i = 1; i <= n; ++i)
    {
        getline(cin, s);
        int sz = s.size();
        day[i] = day[i - 1];
        for(int j = 0, f = 0, x = 0; j < sz; ++j)
        {
            if(s[j] == '+')         f = 1;
            else if(s[j] == '-')    f = -1;
            else if(isdigit(s[j]))  x = x * 10 + s[j] - '0';
            if(s[j] == ' ' || j == sz - 1)
            {
                rt[day[i] = ++ops] = ++tot;
                update(rt[ops - 1], rt[ops], 1, n, x + 1, f);
                f = 0, x = 0;
            }
        }
    }
    int x = 0;
    for(int i = 1, d; i <= n; ++i)
    {
        cin >> d;
        x = (x + query(rt[day[d]], 1, n, x + 1, n)) % n;
    }
    cout << x << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    work();
    return 0;
}
