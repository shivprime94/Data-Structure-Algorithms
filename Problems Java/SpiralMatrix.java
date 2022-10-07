import java.util.Scanner;
class SpiralMatrix
{
    int n,k,x[][];
    Scanner sc=new Scanner(System.in);
    SpiralMatrix(int n1)
    {
        n=n1;
        x=new int[n][n];
    }
    void input()
    {
        k=0;
        for(int i=0;i<=n-1;i++)
        {
            for(int j=i;j<=n-i-1;j++)
                x[i][j]=++k;
            for(int j=i+1;j<=n-i-1;j++)
                x[j][n-i-1]=++k;
            for(int j=n-i-2;j>=i;j--)
                x[n-i-1][j]=++k;
            for(int j=n-i-2;j>=i+1;j--)
                x[j][i]=++k;
        }
    }
    void display()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                System.out.print(x[i][j]+"\t");
            }
            System.out.println();
        }
    }
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter size of matrix");
        int n=sc.nextInt();
        SpiralMatrix obj=new SpiralMatrix(n);
        obj.input();
        obj.display();
    }
}