#include<iostream>
#include<stack>
using namespace std;

class TwoStack {
    int *arr;
    int top1;   
    int top2;   
    int size;   

public:
    // initilize two stack // constructor
    TwoStack(int s) {
        this -> size = s; 
        top1 = -1;   
        top2 = s;    
        arr = new int[s];
    }

    // push in stack 1
    void push(int num) {
        // atleast a empty space present 
        if(top2- top1 >0) {   
            top1++;   
            arr[top1] = num;   

        }
    }
     // push in stack 2
     void push2(int num){
        if(top2 - top1 > 1 ) {   // same logic
            top2--;   
            arr[top2] = num;
        } 
       
    }
    // pop from stack 1
    int pop1() {
        if ( top1 >= 0) {     
            int ans = arr[top1];   
            top1--;  
            return ans;
        }
        else
        {
            return -1;

        }
    }

    // pop from stack 2
     int pop2() {
		if( top2 < size) {
            int ans = arr[top2];
            top2++;  
            return ans;
        }
        else
        {
            return -1;
        }
    }

};