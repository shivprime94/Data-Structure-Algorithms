#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> tower(n + 1, 0);
    int ans = 0;
    int largest = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(all(tower), a[i]);
        if (it == tower.end())
        {
            ans++;
            tower.push_back(a[i]);
        }
        else
        {
            tower[it - tower.begin()] = a[i];
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}