// Problem : 17 Letter Combinations of a Phone Number
// Problem Link : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        map<char,vector<char>> mp;
        mp['2'] = {'a','b','c'};
        mp['3'] = {'d','e','f'};
        mp['4'] = {'g','h','i'};
        mp['5'] = {'j','k','l'};
        mp['6'] = {'m','n','o'};
        mp['7'] = {'p','q','r','s'};
        mp['8'] = {'t','u','v'};
        mp['9'] = {'w','x','y','z'};
        
        int n = digits.size();
        vector<string> ans;   
        if(n == 1)
        {
            for(auto i:mp[digits[0]])
            {
                string temp = "";
                temp += i;
                ans.push_back(temp);
            }
        }
        else if(n == 2)
        {
            for(auto i:mp[digits[0]])
            {
                for(auto j:mp[digits[1]])
                {
                    string temp = "";
                    temp += i;
                    temp += j;
                    ans.push_back(temp);
                }
            }
        }
        else if(n == 3)
        {
            for(auto i:mp[digits[0]])
            {
                for(auto j:mp[digits[1]])
                {
                    for(auto k:mp[digits[2]])
                    {
                        string temp = "";
                        temp += i;
                        temp += j;
                        temp += k;
                        ans.push_back(temp);   
                    }
                }
            }
        }
        else if(n == 4)
        {
            for(auto i:mp[digits[0]])
            {
                for(auto j:mp[digits[1]])
                {
                    for(auto k:mp[digits[2]])
                    {
                        for(auto l:mp[digits[3]])
                        {
                            string temp = "";
                            temp += i;
                            temp += j;
                            temp += k;
                            temp += l;
                            ans.push_back(temp);      
                        }
                    }
                }
            }
        }
        return ans;
    }
};
