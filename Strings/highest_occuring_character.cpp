// Given a string, we need to find and print the character which has occured maximum number of times

#include <iostream>
#include <cstring>
using namespace std;

char highestOccurringChar(char input[]) {
    int frequency[256]={0};  // Initialised all the indexes to initially
    
    for(int i=0;input[i]!='\0';i++)
    {
        frequency[input[i]]++;   // Increasing the count of each character at the index corresponding to the ascii value of the character (Ex. ascii of 'a' is 97 so at index 97 the value will become 1 after the first occurence of the character)
    }
    int max=0;  // initialised the max value to 0
    int maxindex=-1;  // and the index to -1 indicating no index have been found yet
    for(int i=0;i<256;i++)
    {
        if(frequency[i]>max)
        {
            max=frequency[i];  // Updating the max value 
            maxindex=i;  // Updating the index corresponding to the max value
        }
    }
    return char(maxindex);
}

int main() {
    int size = 1e6;
    char str[size];
    cout<<"Enter the string : ";
    cin >> str;
    cout << highestOccurringChar(str);
}