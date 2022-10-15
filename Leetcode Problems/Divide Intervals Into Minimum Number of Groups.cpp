int minGroups(vector<vector<int>>& nums) {
        int n = INT_MIN;
        for(int i=0;i<nums.size();i++)
            n = max(n, nums[i][1]);
        
        vector<int> v(n+2, 0);
        for(int i=0;i<nums.size();i++)
        {
            v[nums[i][0]]++;
            v[nums[i][1]+1]--;
        }
        for(int i=1;i<v.size();i++)
            v[i] = v[i] + v[i-1];
        
        int cn = 0;
        for(int i=0;i<v.size();i++)
            cn = max(cn, v[i]);
        
        return cn;
    }
