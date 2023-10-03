int Solution::maxArea(vector<int> &A)
{
    int n = A.size();
    int mx = 0;
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (A[i] < A[j])
        {
            mx = max(mx, A[i] * (j - i));
            i++;
        }
        else
        {
            mx = max(mx, A[j] * (j - i));
            j--;
        }
    }
    return mx;
}
