int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    vector<int> l(n), r(n);
    stack<int> st;
    int mx = 0;
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && A[st.top()] >= A[i])
            st.pop();
        if(st.empty())
            l[i] = 0;
        else
            l[i] = st.top() + 1;
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    for(int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && A[st.top()] >= A[i])
            st.pop();
        if(st.empty())
            r[i] = n - 1;
        else
            r[i] = st.top() - 1;
        st.push(i);
    }
    
    for(int i = 0; i < n; i++)
        mx = max(mx, A[i] * (r[i] - l[i] + 1));
    
    return mx;
}
