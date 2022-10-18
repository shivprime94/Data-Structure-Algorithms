// sorting stack 


#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &stack, int num) {
    // base case
    if(stack.empty() || (!stack.empty() && stack.top() < num)) {  
        stack.push(num);   
        return;
    }

    int n = stack.top(); 
    stack.pop();

    // recursive call
    sortedInsert(stack , num);  
}


void sortStack(stack<int> &stack)
{
    // base class
    if(stack.empty()) {   
        return ;
    }

    int num = stack.top();   
    stack.pop();


    // recursive call
    sortStack(stack);  

    sortedInsert(stack, num);  
}