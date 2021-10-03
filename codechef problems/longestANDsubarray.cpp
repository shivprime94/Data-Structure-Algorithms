// CodeChef October challenge-2021 Division 3 (Rated)
// problem name :  ANDSUBAR 

/* problem statement:
You are given an integer N. Consider the sequence containing the integers 1,2,…,N in increasing order (each exactly once). 
Find the length of the longest subarray in this sequence such that the bitwise AND of all elements in the subarray is positive.
*/

//input: 7   output: 4
/*explaination : It is optimal to take the subarray [4,5,6,7] 
and the bitwise AND of all integers in this subarray is 4
*/

//input: 4  output: 2
/*It is optimal to take the subarray [2,3]
 and the bitwise AND of 2 and 3 is 2.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;              
    cin>>t;           // number of test cases
    while(t--){ 
        ll n;        //1 ≤ n ≤ 10^9
        cin>>n;      //Each test case contains a single integer N on a single line

        int p = (log(n)/log(2));
        int k = pow(2,p);          // k = 2^p
        int x=k/2;
        int y=n-k+1;
        if(x>y){
            cout<<x<<endl;
        }
        else{
            cout<<y<<endl;
        }
    }
    return 0;
}