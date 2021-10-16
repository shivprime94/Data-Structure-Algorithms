//You are asked to define the running sum of the array and return it

/*
  Example :
   Input : nums=[1,2,3,4,5]
   Output : [1,3,6,10,15]

  Explanation : Running sum is obtained as follows : [1, 1+2, 1+2+3, 1+2+3+4, 1+2+3+4+5]
*/   
 
int* runningSum(int* nums, int numsSize, int* returnSize){
    *returnSize=numsSize;
    int* res=(int *)malloc(sizeof(int)*numsSize);
    res[0]=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        res[i]=res[i-1]+nums[i];
    }
    return res;
}
