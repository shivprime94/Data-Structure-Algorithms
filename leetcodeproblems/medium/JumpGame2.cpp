#include<bits/stdc++.h>

using namespace std;

int jump(vector<int>& nums) {
        int len=nums.size()-1, curr=-1, next=0, ans=0;
        
        for(int i=0; next<len; i++)
        {
            if(i>curr)
                ans++, curr=next;
            next=max(next, nums[i]+i);
        }
        return ans;
    }

int main()
{
  vector<int> arr{2,3,1,1,4};
  cout<<jump(arr);
  return 0;
}
