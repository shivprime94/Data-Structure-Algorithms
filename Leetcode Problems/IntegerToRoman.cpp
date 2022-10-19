// 12. Integer to Roman (Medium)
/*
  Example 1
  Input: 3
  Output: "III"
  Explanation: 3 is represented as 3 ones.
  
  Example 2
  Input: 58
  Output: "LVIII"
  Explanation: L = 50, V = 5, III = 3.
  
  Example 3
  Input: 1994
  Output: "MCMXCIV"
  Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        string nos[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        for(int i = 0; num > 0; i++){
            while(num >= val[i]){
                num -= val[i];
                ans += nos[i];
            }
        }
        return ans;
    }
};
