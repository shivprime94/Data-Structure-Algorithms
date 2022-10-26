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
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int pt1 = 1, pt2 = 0;
    vector<int> mi, mx;
    int st1 = 0, st2 = 0;
    while ((st1 < n))
    {
        if (b[st2] - a[st1] >= 0)
        {
            mi.push_back(b[st2] - a[st1]);
            st1++;
        }
        else
        {
            st2++;
        }
    }
    for (auto v : mi)
    {
        cout << v << " ";
    }
    cout << newl;
    for (int i = 0, j = 0; i < n; i++)
    {
        j = max(j, i);
        while ((j + 1 < n) && (a[j + 1] <= b[j]))
        {
            j++;
        }

        mx.push_back(b[j] - a[i]);
    }
    for (auto v : mx)
    {
        cout << v << " ";
    }
    cout << newl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}