#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void solve()
{
    ll n;
    cin >> n;
    cout << (long long)(-n + 1) << ' ' << (long long)(n) << '\n';
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