#include <stdio.h>
#include <vector>
using namespace std;
class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            vector<int> v;
            bool flag = false;
            for(int i=0;i<nums.size()-1;i++)
            {
                for(int j=i+1;j<nums.size();j++)
                {
                    if(nums[i]+nums[j]==target)
                    {
                        v.push_back(i);
                        v.push_back(j);
                        flag = true;
                        break;
                    }
                }
                if(flag == true)
                {
                    break;
                }
            }
            return v;
        }
};