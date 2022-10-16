// Given a string we need to remove the consecutive duplicates in the string

#include <iostream>
#include <cstring>
using namespace std;
void removeConsecutiveDuplicates(char input[]) {
    int i=0;
    int k=0;
    while(input[i]!='\0')
    {
        if(input[i]==input[i+1])  // If the ith and (i+1)th elements are same we are updating the value of i
        {
            i++; 
        }
        else   // otherwise if the ith and (i+1)th elements are not same, we are adding them into our new character array or we can say that we are adding the unique elements into our character array
        {
            input[k]=input[i];
            i++;
            k++;
        }
    }
    input[k]='\0';  // Since we created our own character array, we need to add the null explicitely by ourself
}

int main() {
    int size = 1e6;
    char str[size];
    cout<<"Enter the string : ";
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}