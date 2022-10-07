#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// SCRAMBLED STRING
bool Scrambled_string(string a, string b)
{
    int n = a.length();
    
    // Base Condition
    if (n == 0)
    {
        return true;
    }
  
    // If our both string are same then we simply return true , as same string are always scrambled string
    if (a == b)
        return true;
  
    // Traversing the array
    for (int i = 1; i < n; i++)
    {   
      
        //  We check for first condition that , if the first part of string a (0 to i) equal to end part of string b(n-i , i) and vice versa , If yes then return true
        if (Scrambled_string(a.substr(0, i), b.substr(n - i, i)) && Scrambled_string(a.substr(i, n - i), b.substr(0, n - i)))
        {
            return true;
        }
      
        // Secondly we also check that the first part of string a is equal to first part of string b (0 to i) and end part of string a (0 to n-i) equal to end part of
        // string b , If yes return true
        if (Scrambled_string(a.substr(0, i), b.substr(0, i)) && Scrambled_string(a.substr(i, n - i), b.substr(i, n - i)))
        {
            return true;
        }
    }
    return false;
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    string a = "coder";
    string b = "ocred";
    if (Scrambled_string(a, b))
    {
        cout << "Scrambled string";
    }
    else
        cout << "Not Scrambled string";

    return 0;
}
