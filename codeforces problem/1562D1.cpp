#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;
        string str;
        cin >> str;
        int sign_sum[n+1];
        sign_sum[0] = 0;
        for(int i=0;i<n;i++)
        {
            if((i%2)==0)
            {
                if(str[i]=='+')
                {
                    sign_sum[i+1] = sign_sum[i] + 1;
                }
                else
                {
                    sign_sum[i+1] = sign_sum[i] - 1;
                }
            }
            else
            {
                if(str[i]=='+')
                {
                    sign_sum[i+1] = sign_sum[i] - 1;
                }
                else
                {
                    sign_sum[i+1] = sign_sum[i] + 1;
                }
            }
        }  
        while(q--)
        {
            int l, r;
            cin >> l >> r;
            int value = sign_sum[r]-sign_sum[l-1];
            if(value<0)
            {
                value*=(-1);
            }
            if(value!=0)
            {
                if((value%2)==0)
                {
                    value = 2;
                }
                else
                {
                    value = 1;
                }
            }
            cout << value << endl;
        }
    }
    return 0;
}