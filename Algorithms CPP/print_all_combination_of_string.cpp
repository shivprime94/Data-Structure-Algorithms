#include<bits/stdc++.h>
using namespace std;
vector<string> result; // act as a container stores all the combination created by the string_combination function
void string_combination(string str, string level_str,int level)
{
    if(level==str.length())
    {
        result.push_back(level_str);
        return;
    }
    level_str.push_back(str[level]);
    string_combination(str,level_str,level+1);
    level_str.pop_back();
    string_combination(str,level_str,level+1);
}
int main()
{
    string str,level_str;
    cout<<"please enter the string:-";
    cin>>str;
    string_combination(str,level_str,0);
    cout<<"printing all combination of a string"<<endl;
    for(auto x: result)
    {
        cout<<x<<" ";
    }
    
}
