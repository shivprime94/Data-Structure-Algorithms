/*

Link- https://leetcode.com/problems/strong-password-checker/

Input: password = "a"
Output: 5

Input: password = "aA1"
Output: 3

Input: password = "1337C0d3"
Output: 0
*/

#include <bits/stdc++.h>
using namespace std;

int strongPasswordChecker(string password) {
         int n = password.size();
        int missing_types = 3, replace_for_repeats = 0;
        bool has_lower = false, has_upper = false, has_digit = false, has_three_repat = false;
        int opt_by_remove_last = 0, opt_by_remove_last_two = 0, opt_by_remove_last_three = 0;
        for (int i = 0; i < n; ++i) {
            if (isdigit(password[i])) {
                has_digit = true;
            } else if (islower(password[i])) {
                has_lower = true;
            } else if (isupper(password[i])) {
                has_upper = true;
            }
            if (i+2 < n && password[i+2] == password[i+1] && password[i+1] == password[i]) {
                int iend = i+2, repeats = 3;
                while (iend+1 < n && password[iend+1] == password[iend]) {
                    ++iend; ++repeats;
                }
                replace_for_repeats += repeats/3;
            
                if (repeats%3 == 0) opt_by_remove_last += 1;
                if (repeats%3 == 1) opt_by_remove_last_two += 1;
                if (repeats%3 == 2) opt_by_remove_last_three += 1;
                i = iend;
            }
        }
        if (has_lower) missing_types -= 1;
        if (has_upper) missing_types -= 1;
        if (has_digit) missing_types -= 1;
        if (n < 6) return std::max(missing_types, 6-n);
        if (n <= 20) return std::max(missing_types, replace_for_repeats);
        int required_delete = n-20;
        int extra_changes = replace_for_repeats;
        extra_changes -= std::min(required_delete, opt_by_remove_last);
        extra_changes -= std::min(std::max(required_delete-opt_by_remove_last, 0), 2*opt_by_remove_last_two)/2;
        extra_changes -= std::min(std::max(required_delete-opt_by_remove_last-2*opt_by_remove_last_two, 0), 3*opt_by_remove_last_three)/3;
        extra_changes -= std::max(required_delete-opt_by_remove_last-2*opt_by_remove_last_two-3*opt_by_remove_last_three, 0) /3;
        
        return required_delete+std::max(missing_types, extra_changes);
    }
int main()
{
	string str;
    cin>>str;
	cout <<endl<< "Password Strength is: "<< strongPasswordChecker(str);
	return 0;
}