#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{

    string s;
    cin >> s;
    n = s.size();
    bool ans = true;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            x++;
        else if (s[i] == ')')
            y++;
    }
    x = n / 2 - x;
    y = n / 2 - y;
    if (x == 0 || y == 0)
    {
        cout << "YES" << "\n";
        return;
    }
    int sum = 0;
    bool flg = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            sum++;
        else if (s[i] == ')')
            sum--;
        else
        {
            if (x == 1 && flg)
            {
                sum--;
                y--;
                flg = 0;
            }
            else if (x > 0)
            {
                sum++;
                x--;
            }
            else
            {

                sum--;
                y--;
            }
        }

        if (sum < 0)
        {
            ans = 0;
            break;
        }
    }

    if (ans)
        cout << "NO" << "\n";
    else
    {
        cout << "YES" << '\n';
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