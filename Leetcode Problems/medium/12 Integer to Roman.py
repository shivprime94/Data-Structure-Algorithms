class Solution:
    def intToRoman(self, num: int) -> str:
        digits = [(1000, "M"), (900, "CM"), (500, "D"), (400, "CD"), (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
               (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")]

        ans = ""
        for n, s in digits:  # Maximum 13 operations
            while num >= n:  # Each while loop, maximum 3 operations, imagine case num=3
                ans += s
                num -= n
        return ans