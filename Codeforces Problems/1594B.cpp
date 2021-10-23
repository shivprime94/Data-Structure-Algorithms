#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll INF = 1e9 + 7;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll p = 1;
    ll ans = 0;
    for (int i = 0; i < 31; i++)
    {
        if (k & (1 << i))
        {
            ans = (ans + p) % INF;
            // cout << "ans-> " << ans << " " << (1 << i) << " ";
            // cout << "p-> " << p << " ";
        }
        p *= n;
        p %= INF;
    }
    cout << ans << '\n';
}

int main()
{

    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}