/*
C++ Program to check if string is balanced or not.(Link=> https://leetcode.com/problems/valid-parenthesis-string/)
  input=> s="({[]})"
  output=> YES
  explanation: string is balanced.
  
  input=> s="({[])"
  output=> NO
  explantion: string is not balanced.
  
*/

#include<iostream>
#include<stack>
using namespace std;

void isValid(string s) {
        stack<char> st;
        st.push('@');
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else if(!st.empty() && ((s[i]==')' && st.top()=='(') || (s[i]==']' && st.top()=='[') || (s[i]=='}' && st.top()=='{'))){
                st.pop();
            }
            else{
                cout << "NO" << endl;
                return;
            }
        }
        if(st.top()=='@')
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

int main(){
    string a;
    cout<<"Enter string: "<<endl;
    cin>>a;

    isValid(a);
    return 0;
}
