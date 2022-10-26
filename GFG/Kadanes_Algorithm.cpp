    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        long long int max_sum=arr[0],res=arr[0];
        for(int i=1;i<n;i++){
           max_sum= (arr[i]> (arr[i]+max_sum)) ?arr[i]: (arr[i]+max_sum);
           res= (res> max_sum) ?res: max_sum;
        }
        return res;
        
    }
};


// Question - https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
