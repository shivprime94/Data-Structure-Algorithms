#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    a[0] = 0;
    a[n + 1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((a[i] > a[i + 1]) && (a[i] > a[i - 1]))
        {
            ans += a[i];
        }
        if ((a[i] < a[i - 1]) && (a[i] < a[i + 1]))
        {
            ans -= a[i];
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}