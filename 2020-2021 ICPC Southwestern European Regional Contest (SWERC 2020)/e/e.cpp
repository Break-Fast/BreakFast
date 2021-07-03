#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;

void work()
{
    int n; scanf("%d", &n);
    int ans = inf;
    for(int i = 0, a, b; i < n; ++i)
    {
        scanf("%d %d", &a, &b);
        ans = min(ans, b / a);
    }
    printf("%d\n", ans);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    ios::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
    work();
    return 0;
}
