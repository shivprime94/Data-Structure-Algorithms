#include <iostream>
#include <stdio.h>

using namespace std;

long infi_sum(int x, int n){
    long sum=0;
    for(int i=1;i<=n;i++){
        if((x-1)/i>0){
            sum+=(x-1)/i;
        }
    }
    return sum;
}

int main(){
    //(c(nk+1),ck,c)
    int T;cin>>T;
    for(int i=0;i<T;i++){ 
        int N;cin>>N;
        int ans=0;
        for(int i=1;i<N;i++){
            ans+=infi_sum(N/i,N/i-1);
        }
        cout<<ans<<endl;
    }
    

return 0;
}

//for c=1
    //for k=1, n+1<=N, => n <= N-1 => N-1 values of n
    //for k=2, 2n+1<=N => n <= (N-1)/2 => (N-1)/2 values of n
    //Similarly , for k=N, N-1/N values for n
    //Hence, total= (N-1) + (N-1)/2 + (N-1)/3 +......+ (N-1)/(N-1) + (N-1)/N
//for c=2
    //for k=1 (N/2-1)/1 values of n
    //for k=2 (N/2-1)/2 values of n
    //for k=N (N/2-1)/N values of n
    //Hence, total= (N/2-1)+ (N/2-1)/2 + ..... + (N/2-1)/N

//So, loop this total sum for c=1 to c=N
//But this is O(N^2)
//Instead of taking the total from 1 to N, take the total from 1 to (N/c -1)
//Hence, problem solved

