package medium;

/*
 * @author: shubhambansal
 * @date: 09/10/21
 */

import java.util.HashMap;
import java.util.Map;

public class ZigZagConversion {

  //remove this static keyword is you want to submit code to leetcode
  static class Solution {

    public String convert(String s, int numRows) {
      if (numRows == 1) {
        return s;
      }
      Map<Integer, StringBuilder> rowMap = new HashMap<>();
      Integer row = 1;
      boolean increasingCycle = true;
      for (char i : s.toCharArray()) {
        rowMap.putIfAbsent(row, new StringBuilder());
        rowMap.get(row).append(String.valueOf(i));
        if (increasingCycle) {
          row++;
        } else {
          row--;
        }
        if (row == 1) {
          increasingCycle = true;
        } else if (row == numRows) {
          increasingCycle = false;
        }
      }
      StringBuilder result = new StringBuilder();
      for (int i = 1; i <= numRows; i++) {
        result.append(rowMap.getOrDefault(i, new StringBuilder()));
      }

      return result.toString();
    }
  }

  //To test your code
  public static void main(String[] args) {
    Solution s = new Solution();
    // Use this for custom input
    System.out.println(s.convert("PAYPALISHIRING", 3));
  }
}
