package Sorting;

import java.util.Arrays;

public class CyclicSORT {

    public static void main(String[] args) {

        int[] arr = {3,5,4,1,2};

//        cyclic(arr);

        CyclicSORT ob = new CyclicSORT();

        ob.cyclic(arr);

        System.out.println(Arrays.toString(arr));

    }

    static void cyclic(int[] arr){

        int i = 0;

        while(i< arr.length){

            int correct = arr[i]-1;

            if(arr[i] != arr[correct]){

                swap(arr, i,correct);

            }else {

                i++;

            }

        }

    }

    static void swap(int[] arr, int first, int second){

        int temp= arr[first];

        arr[first] = arr[second];

        arr[second] = temp;

    }

}
