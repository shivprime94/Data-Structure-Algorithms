class Solution {
    public static int reverse(int x) {
        String temp = String.valueOf(x);
        String[] arr = new String[temp.length()];
        for(int i = 0; i < temp.length(); i++){
            if(!String.valueOf(temp.charAt(i)).equals("-")){
                arr[temp.length()-i-1] = String.valueOf(temp.charAt(i));
            }
        }
        String st = "";
        for(String digit : arr){
            if(digit!=null) st+=digit;
        }
        int num = 0;
        try{
        num = Integer.valueOf(st);
        } catch(NumberFormatException e){
            return 0;
        }
        if(x < 0) num = num*=-1;
        return num;
    }
}
