//@soumyaagr427

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
	

	
	int search(string word, string text) {
	
	   int n1 = text.length();
	    \int n2 = word.length();
        
        if (n1 < 0 || n2 < 0
        
            || n1 < n2)
            return 0;
        //cutting corver cases for null strings
 
 
        constexpr int CHARACTERS = 256;
        int count = 0;
        int index = 0;
        
        
        std::array<char, CHARACTERS> wordArr;
        wordArr.fill(0);
        std::array<char, CHARACTERS> textArr;
        textArr.fill(0);
 
        // till window size
        for (; index < word_length; index++) {
            wordArr[CHARACTERS - word[index]]++;
            textArr[CHARACTERS - text[index]]++;
        }
        if (wordArr == textArr)
            count += 1;
        // next window
        for (; index < text_length; index++) {
            textArr[CHARACTERS - text[index]]++;
            textArr[CHARACTERS
                    - text[index - word_length]]--;
 
            if (wordArr == textArr)
                count += 1;
        }
        return count;
	
	
	 
	}
	
	

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
