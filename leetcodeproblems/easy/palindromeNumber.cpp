#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        bool flag = false;
        if(x==0)
        {
            flag = true;            
        }
        else if(x>0)
        {
            int noOfDigits = log10(x)+1;
            if(noOfDigits%2==0)
            {
                int rev = 0;
                int i = x;
                int ctr = 0;
                for(i=x;ctr<noOfDigits/2;i/=10,ctr++)
                {
                    rev = (rev*10) + (i%10);
                }
                if(i==rev)
                {
                    flag = true;
                }
            }
            else
            {
                int rev = 0;
                int i = x;
                int ctr = 0;
                for(i=x;ctr<noOfDigits/2;i/=10,ctr++)
                {
                    rev = (rev*10) + (i%10);
                }
                i = i/10;
                if(i==rev)
                {
                    flag = true;
                }
            }
        }
        return flag;
    }
};