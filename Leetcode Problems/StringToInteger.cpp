/* Problem Description:

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.

Examples:

Example 1:

Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
Step 2: "42" (no characters read because there is neither a '-' nor '+')
Step 3: "42" ("42" is read in)
     
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
Example 2:

Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
Step 2: "   -42" ('-' is read, so the result should be negative)
Step 3: "   -42" ("42" is read in)
             
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
*/

class Solution {
public:
    int myAtoi(string s) {
        int i=0, num=0, sign=1;
        bool flag=false;
        
        while(i<s.size() && (s[i]==' ' || s[i]==0)){
            i++;
        }
        
        if(i==s.size())
            return 0;
        
        if(s[i]=='-'){
            sign = -1;
            i++;
        }
        else if(s[i]=='+'){
            i++;
        }
        
        while(i<s.size()){
            if(s[i]>'9' || s[i]<'0')
                break;
            if(num>INT_MAX/10){
                flag=true;
                break;
            }
            num *= 10;
            if(num>INT_MAX-(s[i]-'0')){
                flag=true;
                break;
            }
            num += s[i]-'0';
            i++;
        }
        
        if(flag){
            if(sign==1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        return num*sign;
    }
};