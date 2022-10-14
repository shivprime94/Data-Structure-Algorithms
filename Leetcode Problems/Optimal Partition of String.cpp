class Solution 
{
public:
    int partitionString(string s) 
    {
        unordered_map<int, int> mp;
        int high=0, cnt=0;
        
        while(high<s.size())
        {
            if(mp.find(s[high]-'a') != mp.end())
            {
                mp.clear();
                cnt++;
            }
            mp[s[high]-'a'] = high;
            high++;
        }
        if(!mp.empty()) cnt++;
        return cnt;
    }
};
