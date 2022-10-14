/*
Given two integers L and R find (number of composites - number of primes) between the range L and R (both inclusive).
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
	bool isPrime(int n){
    if(n==1)
        {return false;}
    if(n==2 || n==3)
        {return true;}
    if(n%2==0 || n%3==0)
    {return false;}

    for(int i=5;i*i<=n; i=i+6)
        {
            if(n%i==0 || n%(i+2)==0)
            {return false;}
        }
return true;
}
	
	int Count(int L, int R){
		    // Code here
	int count_p=0, count_c=0, n=R-L+1;
    for(int i=L;i<=R;i++){
        if(isPrime(i)){
            count_p++;}
    }
    count_c=n-count_p;
    if(L==1)
    count_c--;
    
    return count_c-count_p;
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int L, R;
		cin >> L >> R;
		Solution obj;
		int ans = obj.Count(L, R);
		cout << ans << "\n";
	}
	return 0;
}


/*
Example 1:

Input: L = 4, R = 6
Output: 1
Explanation: Composite no. are 4 and 6.
And prime is 5.

Example 2:

Input: L = 4, R = 4
Output: 1
Explanation: There is no prime no. in [L,R]
*/
