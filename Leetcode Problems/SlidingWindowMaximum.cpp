#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        queue<int> q;
        int i=0,j=0;

        while(j<nums.size()){
            while(q.size()>0 && q.front()<nums[j]){
                q.pop();
             }

             q.push(nums[j]);

            if(j-i+1<k)
                j++;

            else if(j-i+1==k){
                res.push_back(q.front());
                if(q.front()==nums[i])
                    q.pop();
                i++;
                j++;    
            }
        }
        return res;
    }
};