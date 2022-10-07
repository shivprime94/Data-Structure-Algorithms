class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        int ctr = 1;
        if((x<0)&&(x!=-2147483648))
        {
            ctr = -1;
            x = x*ctr;
        }
        else if(x==-2147483648)
        {
            ctr = 0;
        }
        if(ctr!=0)
        {
            int i = x;
            for(i=x;i>9;i/=10)
            {
                rev = (rev*10) + (i%10);
            }
            int max = 214748364;
            if(rev>max)
            {
                rev = 0;
            }
            else if((rev==max)&&(i>7)&&(ctr==1))
            {
                rev = 0;
            }
            else if((rev==max)&&(i>7)&&(ctr==-1))
            {
                rev = 0;
            }
            else
            {
                rev = rev*10 + i;
            }
            rev = rev*ctr;
        }
        return rev;
    }
};