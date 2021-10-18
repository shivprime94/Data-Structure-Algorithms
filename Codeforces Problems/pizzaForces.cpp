#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        long long int time = 0;
        long long int n;
        cin >> n;
        if(n<=6)
        {
            time = 15;
        }
        else if(n%2==0)
        {
            time = (n*5)/2;
        }
        else
        {
            time = ((n+1)*5)/2;
        }
        cout << time << endl;
    }
    return 0;
}
