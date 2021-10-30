
/* problem statement:
You are given a positive integer N. You have to print exactly N+1 positive integers satisfying the following conditions:

Exactly one value should appear twice, all the remaining values should appear only once.
Sum of all these values should be equal to 2N.
You have to print the values in non-decreasing order. If there are multiple solutions, you can print any of them.

*/

//input: 3  output: 1 2 2 3
/*
explanation: 2 is repeated twice and the remaining elements occurred only once and the sum of all the elements is equal to 8, which is 23.
*/

//input: 4  output: 1 2 3 3 7
/*
 3 is repeated twice and the remaining elements occurred only once and the sum of all the elements is equal to 16, which is 24.
*/


//Solution:


#include<bits/stdc++.h>
using namespace std;

int main()
 {
    
   long long tc;
   cin>>tc;
   while(tc--)
    {  long long n,i,ans,sum;
        long long final;
        cin>>n;
        if(n==1){cout<<"1"<<" "<<"1"<<endl;}
        else{
      long long int y= pow(2,n);
        sum=0;
        cout<<"1"<<" ";
            for(i=1;i<n;i++){
                sum += i;
            ans=sum+1;
            final=y-ans;
            cout<<i<<" ";
           
            }cout<<final<<endl;}
        }
        
    }