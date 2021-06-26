#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M = (int)5e5;

int n, a[M + 5];
int cnt[3][3];

int cal(int n1, int n2)
{
    return (1 * n1 * (n1 - 1) / 2 + 4 * n2 * (n2 - 1) / 2 + 2 * n1 * n2) % 3;
}

void work()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int n1 = 0, n2 = 0;
    ++cnt[n1][n2];
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        n1 = (n1 + (a[i] % 3 == 1)) % 3;
        n2 = (n2 + (a[i] % 3 == 2)) % 3;
        for(int n3 = 0; n3 <= 2; ++n3)
        {
            for(int n4 = 0; n4 <= 2; ++n4)
            {
                if(cal(n1 - n3, n2 - n4) == 0) ans += cnt[n3][n4];
            }
        }
        ++cnt[n1][n2];
    }
    printf("%lld\n", ans);
}

int main()
{
    work();
    return 0;
}
