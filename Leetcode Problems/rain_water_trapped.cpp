int Solution::trap(const vector<int> &A) {
    int n = A.size();
    int ans = 0;
    int h = 0, l = 0, r = n - 1;
    while (l <= r)
    {
        if (A[l] <= A[r])
        {
            if (h > A[l])
                ans += h - A[l++];
            else
                h = A[l++];
        }
        else
        {
            if (h > A[r])
                ans += h - A[r--];
            else
                h = A[r--];
        }
    }
    return ans;
}
