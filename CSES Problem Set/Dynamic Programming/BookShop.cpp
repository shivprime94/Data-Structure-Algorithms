//CSES Problem Set Dynamic Program Question 7 'Book Shop' Solution
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forp(a, b, c) for (int(a) = (b); (a) < (c); (a)++)
#define form(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    forp(i, 0, n) cin >> h[i];

    vector<int> s(n);
    forp(i, 0, n) cin >> s[i];

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    forp(i, 1, n + 1)
    {
        forp(j, 0, x + 1)
        {
            dp[i][j] = dp[i - 1][j];
            int left = j - h[i - 1];
            if (left >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][left] + s[i - 1]);
            }
        }
    }
    cout << dp[n][x] << nl;
    return 0;
}