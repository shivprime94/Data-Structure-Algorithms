class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        
        for(int i=2; i<=n; i++) {
            int idx = 0;
            char toMatch = str[0];
            string next = "";
            while(idx < str.size()) {
                int freq = 0;
                while(str[idx] == toMatch) {
                    freq++;
                    idx++;
                }
                next += to_string(freq) + toMatch;
                if(idx >= str.size())
                    break;
                toMatch = str[idx];
            }
            str = next;
        }
        return str;
    }
};
