class Solution:
    def myAtoi(self, s: str) -> int:
        ans=0
        s=s.lstrip()
        minus=False
        plus=False
        if s=="":
            return 0
        if s[0]=='-':
            minus=True
        if s[0]=='+':
            plus=True
        num={'1','2','3','4','5','7','8','9','0','6'}
        if not minus and not plus and s[0] not in num:
            return 0
        word=False
        if minus or plus:
            s=s[1:]
        for i in s:
            if i in num:
                if word:
                    if minus:
                        return ans*-1
                    return ans
                ans=ans*10+int(i)
            else:
                word=True
        if minus:
            ans=ans*-1
        if ans<-2147483648:
            return -2147483648
        elif ans>2147483646:
            return 2147483647
        
        
        return ans