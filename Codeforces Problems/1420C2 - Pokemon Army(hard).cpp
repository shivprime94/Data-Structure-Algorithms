#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    int n, q;
    cin >> n >> q;
    vector<int> a(n + 2);
    set<int> plus, minus;
    unordered_map<int, bool> mp_a, mp_b;
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
            mp_a[i] = 1;
        }
        if ((a[i] < a[i - 1]) && (a[i] < a[i + 1]))
        {
            ans -= a[i];
            mp_b[i] = 1;
        }
    }

    cout << ans << '\n';
    while (q--)
    {

        int l, m;
        cin >> l >> m;
        for (int i = 0; i < 3; i++)
        {
            ans -= (mp_a[(l - 1 + i)] * a[l - 1 + i]);
            mp_a[(l - 1 + i)] = 0;
            ans += (mp_b[(l - 1 + i)] * a[l - 1 + i]);
            mp_b[(l - 1 + i)] = 0;
        }
        for (int i = 0; i < 3; i++)
        {
            ans -= (mp_a[(m - 1 + i)] * a[m - 1 + i]);
            mp_a[(m - 1 + i)] = 0;

            ans += (mp_b[(m - 1 + i)] * a[m - 1 + i]);
            mp_b[(m - 1 + i)] = 0;
        }

        swap(a[l], a[m]);

        for (int i = 0; i <= 2; i++)
        {
            if (!mp_a[(l - 1 + i)])
            {
                if ((a[l - 1 + i] > ((l + i > 1) ? a[l + i - 2] : 0)) && (((l + i < n + 1)) ? a[l + i] : 0) < a[l - 1 + i])
                {
                    ans += a[l - 1 + i];
                    mp_a[l - 1 + i] = 1;
                }
            }
            if (!mp_b[(l - 1 + i)])
            {
                if ((a[l - 1 + i] < ((l + i > 1) ? a[l + i - 2] : 0)) && (((l + i < n + 1)) ? a[l + i] : 0) > a[l - 1 + i])
                {
                    ans -= a[l - 1 + i];
                    mp_b[(l - 1 + i)] = 1;
                }
            }
        }
        for (int i = 0; i <= 2; i++)
        {
            if (!mp_a[(m - 1 + i)])
            {
                if ((a[m - 1 + i] > ((m + i > 1) ? a[m + i - 2] : 0)) && (((m + i < n + 1)) ? a[m + i] : 0) < a[m - 1 + i])
                {
                    ans += a[m - 1 + i];
                    mp_a[m - 1 + i] = 1;
                }
            }
            if (!mp_b[(m - 1 + i)])
            {
                if ((a[m - 1 + i] < ((m + i > 1) ? a[m + i - 2] : 0)) && (((m + i < n + 1)) ? a[m + i] : 0) > a[m - 1 + i])
                {
                    ans -= a[m - 1 + i];
                    mp_b[m - 1 + i] = 1;
                }
            }
        }
        cout << ans << '\n';
    }
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