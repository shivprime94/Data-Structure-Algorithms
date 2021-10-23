#include<bits/stdc++.h>
using namespace std;
vector<string> result; // act as a container stores all the permutation created by the string_permutation function
void string_permutation(string str,int start)
{
    if(start==str.length())
    {
        result.push_back(str);
        return;
    }
    for(int i=start; i<str.length(); i++)
    {
        swap(str[start],str[i]);         
        string_permutation(str,start+1);  //reccursive all on the valid permutation of the string
        swap(str[start],str[i]);          //backtracking
    }


}
int main()
{
    string str;
    cout<<"please enter the string:-";
    cin>>str;
    string_permutation(str,0);
    cout<<"printing all permutation of a string"<<endl;
    for(auto x: result)
    {
        cout<<x<<" ";
    }
    
}
