// Here importing the required package 
   
import java.util.*;   
   
// creating the class name:valid_parentheseis_in_java for implementing Balanced Parentheses using stack   
public class valid_parentheseis_in_java {   
      
    // creating method balancedParenthesis() to check whether the input string is balanced or not   
  
    public static boolean balancedParenthesis(String inputStr) {   
          
        // create an empty stack   
        Stack stack = new Stack();   
          
        // convert inputStr to char array   
        char[] charArray = inputStr.toCharArray();   
          
        // iterate charArray   
        for (int i = 0; i < charArray.length; i++) {   
              
            // get char   
            char current = charArray[i];   
              
            //check whether current is '(', '[' or '{'   
            if (current == '{' || current == '[' || current == '(') {   
                // push current to stack   
                stack.push(current);   
                continue;   
            }   
            // if stack is empty, return false   
            if (stack.isEmpty()) {    
                return false;   
            }   
              
            // use switch statement to pop element from stack and if it is '(', '[' or '{', return false   
            char popChar;   
            switch (current) {   
                case ')':   
                popChar = (char) stack.pop();   
                if (popChar == '{' || popChar == '[')   
                    return false;   
                break;   
                case '}':   
                popChar = (char) stack.pop();   
                if (popChar == '(' || popChar == '[')   
                    return false;   
                break;   
                case ']':   
                popChar = (char) stack.pop();   
                if (popChar == '(' || popChar == '{')   
                    return false;   
                break;   
            }   
        }   
        return (stack.isEmpty());   
    }   
    // main() method start   
    public static void main(String[] args) {   
          
        String inputStr;   
          
        // create an instance of Scanner class   
        Scanner sc = new Scanner(System.in);   
          
        System.out.println("Enter input string to check:");   
        // take input sring from user   
        inputStr = sc.nextLine();   
          
        // call balancedParenthesis() method to check whether input string is balanced of not   
        if (balancedParenthesis(inputStr))   
            System.out.println("Input string "+inputStr+" is balanced.");   
        else   
            System.out.println("Input string "+inputStr+" is not balanced.");   
    }   
}  