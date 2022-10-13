/*
https://leetcode.com/problems/edit-distance/description/

Algorithm -
Basic idea is
if the 2 strings first char matches then we can simply call recursion on rest of the string
if they dont match then we have 3 options - 1) delete 2)insert 3) replace
*/

int DP(string s1, string s2, int **arr)
{
    int n = s1.size(), m = s2.size();

    for (int i = 0; i <= n; i++)
    {
        arr[i][0] = i;
    }

    for (int j = 0; j <= m; j++)
    {
        arr[0][j] = j;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[n - i] == s2[m - j])
            {
                arr[i][j] = arr[i - 1][j - 1];
            }
            else
            {
                arr[i][j] = min(arr[i - 1][j], min(arr[i][j - 1], arr[i - 1][j - 1])) + 1;
            }
        }
    }
    return arr[n][m];
}
int minDistance(string s, string ss)
{
	int **arr = new int *[s.size() + 1];
    for (int i = 0; i <= s.size(); i++)
    {
        arr[i] = new int[ss.size() + 1];
        for (int j = 0; j <= ss.size(); j++)
            arr[i][j] = -1;
    }
    
    return DP(s,ss,arr);

}

//Time Complexity O(m*n)
