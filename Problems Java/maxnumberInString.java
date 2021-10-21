import java.util.*;

public class maxnumberInString {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int ans = MaxNumber(str);
        System.out.println("Maximum number in the string is " + ans);
    }
    public static int MaxNumber(String str){
        if(str==null){
            return -2;
        }
        int num = 0, res = 0;
        boolean isdigit = false;
        for(int i=0; i<str.length(); i++){
            if(Character.isDigit(str.charAt(i))){
                num = num*10 +(str.charAt(i)-'0');
                isdigit = true;
            }
            else{
                res = Math.max(res,num);
                num = 0;
            }
        }
        if(isdigit==false){
            return -1;
        }
        
        return Math.max(res,num);
    }
    
}