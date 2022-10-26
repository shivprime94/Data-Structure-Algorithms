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
    queue<int> q;
    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.count(a[i]))
        {
            ans = max(int(q.size()), ans);
            while (q.front() != a[i])
            {
                int x = q.front();
                q.pop();
                s.erase(s.find(x));
            }
            q.pop();
            q.push(a[i]);
        }
        else
        {
            s.insert(a[i]);
            q.push(a[i]);
        }
    }
    ans = max(int(q.size()), ans);

    cout << ans << "\n";
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