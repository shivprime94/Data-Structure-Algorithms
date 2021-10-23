class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0],maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            maxi=max(maxi+nums[i],nums[i]);
            ans=max(ans,maxi);
        }return ans;
    }
};
