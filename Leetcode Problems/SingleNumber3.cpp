class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>answer;
        unordered_map<int,int>map;
        for(auto i:nums)
        {
            map[i]++;
        }
        for(auto i:map)
        {
            if(i.second == 1)
            {
                answer.push_back(i.first);
            }
        }
        return answer;
    }
};
