class Solution
{
    public:
    int josephus(int n, int k)
    {
       queue<int> q;
       for(int i=1;i<=n;i++)
            q.push(i);
        
        int c = 0;
        while(q.size()!=1)
        {
            int x = q.front();
            c++;
            q.pop();
            if(c%k!=0)
                q.push(x);
            // cout<<x<<" ";
        }
        
        return q.front();
    }
};
