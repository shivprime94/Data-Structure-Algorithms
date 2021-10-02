#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int W, H;
        cin >> W >> H;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int w, h;
        cin >> w >> h;
        double dist = -1.000000;
        int w1, h1;
        w1 = x2 - x1;
        h1 = y2 - y1;
        double temp = -1.000000;
        if((w1+w)<=W)
        {
            if((W-x2)>x1)
            {
                dist = x2 - W + w;
                if(dist<0)
                    dist = 0.0;
            }
            else
            {
                dist = w - x1;
                if(dist<0)
                    dist = 0.0;
            }
        }
        if((h1+h)<=H)
        {
            if((H-y2)>y1)
            {
                temp = y2 - H + h;
                if(temp<0)
                    temp = 0.0;
            }
            else
            {
                temp = h - y1;
                if(temp<0)
                    temp = 0.0;
            }
        }
        if((temp<dist)&&(temp!=-1.000000)&&(dist!=-1.000000))
        {
            dist = temp;
        }
        else if((dist==-1.000000)&&(temp!=-1.000000))
        {
            dist = temp;
        }
        if(dist!=-1.000000)
        {
            cout << fixed;
            cout << setprecision(6);
            cout << dist << endl;
        }
        else
        {
            cout << fixed;
            cout << setprecision(0);
            cout << dist << endl;
        }
    }
    return 0;
}
