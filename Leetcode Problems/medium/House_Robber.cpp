#include <bits/stdc++.h>
using namespace std;
  
int House_Robber(vector<int>& nums) {
        int a=0,b=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) a = max(a+nums[i],b);
            else b = max(a,b+nums[i]);
        }
        return max(a,b);
    }
  
// Driver program
int main()
{
    vector<int> nums;
    int n,a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back(a);
    }
    cout<<House_Robber(nums);
    return 0;
}