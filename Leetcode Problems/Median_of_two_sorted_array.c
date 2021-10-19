/* num1 and num2 are two sorted arrays of size m and n respectively,
   return the median of the two sorted arrays.
*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int size=nums1Size+nums2Size;
    double nums3[size];
    int i=0,j=0,k=0;
    for(;i<nums1Size&&j<nums2Size;)
    {
        if(nums1[i]<=nums2[j])
            nums3[k++]=nums1[i++];
        else
            nums3[k++]=nums2[j++];
    }
    while(i<nums1Size)
        nums3[k++]=nums1[i++];
    while(j<nums2Size)
        nums3[k++]=nums2[j++];
    k--;
    if(k%2==0)
        return nums3[k/2];
    else 
        return (nums3[k/2]+nums3[(k/2)+1])/2;
} 
