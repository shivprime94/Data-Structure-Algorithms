import java.util.Scanner; 
class ColoumnSum
{public static void main(String args[])
{int a[][]=new int[4][4];
Scanner sc=new Scanner (System.in);
int Sum=0;
System.out.println("Enter the array");	 
for(int x=0;x<4;x++)
{for(int y=0;y<4;y++)
{
int z=sc.nextInt(); 
a[x][y]=z;
}}
System.out.println("Array -");	
for(int x=0;x<4;x++)
{for(int y=0;y<4;y++)
{System.out.print(a[x][y]+" ");
}System.out.print("\n");
}
for(int y=0;y<4;y++)
{for(int x=0;x<4;x++)
{
Sum=Sum+a[x][y];
}
System.out.println("Sum of column "+(y+1)+" is "+Sum); 
Sum=0;
}
}
}
