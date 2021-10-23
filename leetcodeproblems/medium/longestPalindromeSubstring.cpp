/*
Given a string s, return the longest palindromic substring in s.

Link: https://leetcode.com/problems/longest-palindromic-substring/

Input: s = "babad"
Output: "bab"

Input: s = "cbbd"
Output: "bb"

Input: s = "a"
Output: "a"

Input: s = "ac"
Output: "a"
*/

#include <bits/stdc++.h>
using namespace std;

string longestPalSubstr(string str)
{
	int n = str.size();

	bool table[n][n];

	memset(table, 0, sizeof(table));

	int maxLength = 1;

	for (int i = 0; i < n; ++i)
		table[i][i] = true;

	int start = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (str[i] == str[i + 1]) {
			table[i][i + 1] = true;
			start = i;
			maxLength = 2;
		}
	}

	for (int k = 3; k <= n; ++k) {
		for (int i = 0; i < n - k + 1; ++i) {
            
			int j = i + k - 1;

			if (table[i + 1][j - 1] && str[i] == str[j]) {
				table[i][j] = true;

				if (k > maxLength) {
					start = i;
					maxLength = k;
				}
			}
		}
	}

	string s="";
    for (int i = start; i <= start + maxLength - 1; ++i)
        s+=str[i];

    return s;
}

int main()
{
	string str;
    cin>>str;
	cout <<endl<< "Longest Palindrome Substring is: "<< longestPalSubstr(str);
	return 0;
}
