//     SIEVE OF ERATOSTHENSES (finding prime numbers between [0,n])
//     time complexity : O(N * log(log(N)))

//find all prime numbers less than equal to n

#include<bits/stdc++.h>
using namespace std;

void sieve(int n){
    vector<bool>isPrime(n+1,true);   //true in vector means that the number is prime 
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=n; i++){

        if(isPrime[i] && i*i <= n) {                  // check till only sqrt of n
            for (int j = i*i; j <= n; j += i){
                isPrime[j] = false;                   // make all the multiple of its to false 
            }       
        }   
    }
    // printing all the prime numbers till N
    // if the the value is true in bool vector then print i
    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            cout<<i<<" "<<endl;
        }
    }                
}
int main(){
    int n;
    cin>>n;              // checking from 0 --> n
    sieve(n);
    return 0;
}