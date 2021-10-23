import java.util.*;
class Olympics
{
    public static void main(String[]args)
    {
        try
        {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        
        while(t>0)
        {
            int a[]=new int[6];
            for(int x=0;x<6;x++)
            {
                a[x]=sc.nextInt();
            }
            int sum1=a[0]+a[1]+a[2];
            int sum2=a[3]+a[4]+a[5];
            if(sum1>sum2)
            System.out.println("1");
            else
            System.out.println("2");
            t--;
        }
    }
    catch(Exception e)
    {
        return;
    }
    }
}