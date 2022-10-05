class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost=0;
        int n=colors.size(),i=0,j=1;
        for(int k=0;k<n-1;k++){
            if(colors[i]==colors[j]){
                if(neededTime[i]>neededTime[j]){
                    cost+=neededTime[j];
                    j++;
                }
                else{
                    cost+=neededTime[i];
                    i=j;
                    j++;
                }
            }
          else{
              i=j;
              j++;
          }
    }

        return cost;
    }
};