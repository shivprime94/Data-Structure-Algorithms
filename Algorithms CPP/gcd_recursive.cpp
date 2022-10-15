
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int32_t main()
{
    int a = 98, b = 56;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b);
    return 0;
}

/*


#include <bits/stdc++.h>
using namespace std;

int func()
{

}

int32_t main()
{
    
    return 0;
}



*/