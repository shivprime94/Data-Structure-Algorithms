class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dito={"2":["a","b","c"],
              "3":["d","e","f"],
              "4":["g","h","i"],
              "5":["j","k","l"],
              "6":["m","n","o"],
              "7":["p","q","r","s"],
              "8":["t","u","v"],
              "9":["w","x","y","z"],
              "0":[" "],
              "1":[]
              }
        if digits=="":
            return []
        ans=[]
        total_digit=[]
        for i in digits:
            total_digit.append(dito[i])
        def combination(val,j,i):
            if j>=len(total_digit) or i>len(total_digit[j]):
                ans.append(val)
                return 
            for it in range(len(total_digit[j])):
                combination(val+total_digit[j][it],j+1,it)

            
                   
        for i in range(len(total_digit[0])):
            combination(total_digit[0][i],1,0)
            
        return ans
            
                
                
                
                