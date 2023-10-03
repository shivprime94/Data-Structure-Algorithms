class Solution {
public:
    void sum(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
     if(ind==arr.size()){
         if(target==0){
            ans.push_back(ds);
         }
         return;
     }
        //if we decide to pick up the element we need to check
        if(arr[ind]<=target){
          ds.push_back(arr[ind]);
          sum(ind,target-arr[ind],arr,ans,ds);
          ds.pop_back(); //when u comeback make sure to pop this element
        }
        sum(ind+1,target,arr,ans,ds);
    
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        sum(0,target,candidates,ans,ds);
        return ans;
    }
};
