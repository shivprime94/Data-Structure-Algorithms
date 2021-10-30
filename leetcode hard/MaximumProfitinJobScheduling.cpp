#include<bits/stdc++.h>
using namespace std;

bool sortcol( const vector<int>& v1, const vector<int>& v2 ) {
 return v1[0] < v2[0];
}
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        
        for(int i=0; i<startTime.size(); i++)
        {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        
        map<int, int> dp = {{0,0}};
        
        for(auto& job:jobs)
        {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if(cur > dp.rbegin()->second)
                dp[job[0]]=cur;
        }
        
        return dp.rbegin()->second;
    }

int main()
{
  vector<int> StartTime{1,2,3,4,6};
  vector<int> EndTime{3,5,10,6,9};
  vector<int> profit{20,20,100,70,60};
  cout<<jobScheduling(StartTime, EndTime, profit);
  return 0;
}
