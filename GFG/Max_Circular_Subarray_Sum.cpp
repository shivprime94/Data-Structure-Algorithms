    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    
    int normal(int arr[],int  num){
        int max_sum=arr[0], res=arr[0];
        for(int i=1;i<num;i++){
           max_sum= (arr[i]> (arr[i]+max_sum)) ?arr[i]: (arr[i]+max_sum);
           res= (res> max_sum) ?res: max_sum;}
           return res;
    }
    
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int sum=normal(arr, num);
        if(sum<0)
            return sum;
            int sum_n=0;
        for(int i=0;i<num;i++){
            sum_n+=arr[i];
            arr[i]=-arr[i];
        }
        int sum_s= sum_n + normal(arr, num);
        return (sum>sum_s?sum:sum_s);
        
    }
};


//Question - https://practice.geeksforgeeks.org/problems/max-circular-subarray-sum-1587115620/0
