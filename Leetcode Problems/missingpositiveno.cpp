#include<bits/stdc++.h>
using namespace std;
// r is size
int findMissingNumber(int *arr, int r){
   int missing_no= r;
   for(int i=0;i<r;i++){
      missing_no^= i^arr[i];
   }
   return missing_no;
}
int main(){
   int n= 6;
   int arr[n]= {0,4,2,1,6,3};
   cout<<findMissingNumber(arr,n)<<endl;
   return 0;
}
