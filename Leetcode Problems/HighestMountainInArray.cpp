class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
     //   vector<int> ans;
        int largest=0;
        for(int i=1;i<=n-2;)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                int count =1;
                //left count
                int j=i;
                while(j>=1 && arr[j]>arr[j-1])
                {
                    j--;
                    count++;
                }
                //right count
                while(i<=n-2 && arr[i]>arr[i+1])
                {
                    i++;
                    count++;
                }
                largest=max(largest,count);
              //  ans.push_back(largest);
            }
            else
            {
                i++;
            }
        }
        // return ans[ans.size() - 1];
        return largest;
        
    }
};