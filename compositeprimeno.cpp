// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
int prime[MAX + 1];

void updatePrimes()
{
    // prime[] marks all prime numbers as true
    // so prime[i] = 1 if ith number is a prime
 
    // Initialization
    for (int i = 2; i <= MAX; i++) {
        prime[i] = 1;
    }
 
    // 0 and 1 are not primes
    prime[0] = prime[1] = 0;
 
    // Mark composite numbers as false
    // and prime numbers as true
    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i] == 1) {
            for (int j = i * i; j <= MAX; j += i) {
                prime[j] = 0;
            }
        }
    }
 
    for (int i = 1; i <= MAX; i++) {
        prime[i] += prime[i - 1];
    }
}
 
int getDifference(int l, int r)
{
 
    // Total elements in the range
    int total = r - l + 1;
 
    // Count of primes in the range [l, r]
    int primes = prime[r] - prime[l - 1];
 
    // Count of composite numbers
    // in the range [l, r]
    int composites = total - primes;
 
    // Return the sbsolute difference
    return (abs(primes - composites));
}
 
// Driver code
int main()
{
    int queries[][2] = { { 1, 10 }, { 5, 30 } };
    int q = sizeof(queries) / sizeof(queries[0]);
 
    updatePrimes();
 
    // Perform queries
    for (int i = 0; i < q; i++)
        cout << getDifference(queries[i][0],
                              queries[i][1])
             << endl;
 
    return 0;
}
