import java.util.Scanner;

public class Sorting {

    public static int[] merge_sort(int[] ar, int p, int r){
        int q = 0;
        if (p < r){
            q = (int)((p + r) / 2);
            merge_sort(ar, p, q);
            merge_sort(ar, q+1, r);
            return merge_array(ar, p, q, r);
        }
        else {
            return null;
        }
    }

    public static int[] merge_array(int[] ar, int p, int q, int r){
        int n1 = q - p + 1;
        int n2 = r - q;

        int[] L = new int [n1];
        int[] R = new int [n2];

        for(int i=0; i<=n1; i++){
            L[i] = ar[p + i + 1];
        }
        for(int i=0; i<=n2; i++){
            R[i] = ar[q + 1];
        }

        int i=0, j=0;
        for(int x=p; x<=r; x++){
            if(L[i] <= R[j]){
                ar[x] = L[i];
                i++;
            }
            else{
                ar[x] = R[j];
                j++;
            }
        }

        return ar;
    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter size of array: ");
        int size = sc.nextInt();

        int[] ar = new int[size];
        for(int x=0; x<size; x++){
            ar[x] = sc.nextInt();
        }

        System.out.println("Array: ");
        for(int x=0; x<ar.length; x++){
            System.out.print(ar[x]+"\t");
        }

        int[] sorted_ar = merge_sort(ar, 0, ar.length-1);
        System.out.println("Sorted Array");
        for(int x=0; x<sorted_ar.length; x++){
            System.out.print(sorted_ar[x]+"\t");
        }
    }
}
