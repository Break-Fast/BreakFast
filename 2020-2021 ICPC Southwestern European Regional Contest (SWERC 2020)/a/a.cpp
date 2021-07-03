#include <bits/stdc++.h>
using namespace std;

int n, k;
map<string, int> mp;
map<string, int> pos;
vector<string> v;

bool cmp(const string& a, const string& b)
{
    if(mp[a] != mp[b])  return mp[a] > mp[b];
    return pos[a] > pos[b];
}

void work()
{
    cin >> n >> k;
    cin.ignore();
    string s;
    for(int i = 1; i <= 3 * n; ++i)
    {
        getline(cin, s);
        mp[s]++;
        pos[s] = i;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());
    k = min(k, (int)v.size());
    for(int i = 0; i < k; ++i) cout << v[i] << "\n";
}

int main()
{
//    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    work();
    return 0;
}
