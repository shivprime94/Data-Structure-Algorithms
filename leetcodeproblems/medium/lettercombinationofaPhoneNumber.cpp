class Solution {
public:
    
    void recur_comb(string digits, vector<string>&res,string comb[],int index, string s)
    {
        //s is the combination which gets updated & added the recursive call is executed
        if(digits.length()==index)
        {
            res.push_back(s);
            return;
        }
        //else statement
        string str = comb[digits[index]-'0'];
        for(int i =0; i<str.length();i++)
        {
            //recursive function call
            recur_comb(digits,res,comb,index+1,s+str[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.length()==0)
        {
            return res;
        }
        string comb[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        recur_comb(digits,res,comb,0,"");
        return res;
    }
};
