import java.util.*;
class Scratch {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String str = sc.nextLine();
        System.out.println(longestPalindrome(str));
    }
    public static String longestPalindrome(String s) {
        int stringLength = s.length();
        int[][] memoise = new int[stringLength][stringLength];
        char[] stringArray = s.toCharArray();
        int maxStartIndex = 0;
        int maxEndIndex = 0;
        int i=0;
        for(int k=0; k<stringLength; k++)
        {
            for(int j=0; j<stringLength-k; j++){
                i=j+k;
                if(stringArray[i] == stringArray[j]){
                    if(k <= 2){
                        memoise[i][j] = 1;
                        maxStartIndex = j;
                        maxEndIndex = i;
                    }
                    else if (memoise[i-1][j+1] == 1){
                        memoise[i][j] = 1;
                        maxStartIndex = j;
                        maxEndIndex = i;
                    }
                    else
                        memoise[i][j] = 0;
                }
                else{
                    memoise[i][j] = 0;
                }
            }
        }
        return s.substring(maxStartIndex, maxEndIndex+1);

    }
}