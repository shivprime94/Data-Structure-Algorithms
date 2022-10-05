class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>a;
        vector<int>res;
        for(int i=0;i<numbers.size();i++){
            int sum=target-numbers[i];
             if(a.find(sum)!=a.end()){
                 res.push_back(a[sum]+1);
                 res.push_back(i+1);
             }
            else{
                a[numbers[i]]=i;
            }
        }
        return res;
    }
};