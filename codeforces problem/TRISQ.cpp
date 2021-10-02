// problem code : TRISQ  
// Fit Squares in Triangle 
/* 
What is the maximum number of squares of size 2x2 that can be fit in a right angled isosceles triangle of base B.
One side of the square must be parallel to the base of the isosceles triangle.
Base is the shortest side of the triangle 
*/

#include <iostream>
using namespace std;

int main() {
	int tc,b;
	cin>>tc;
	while(tc!=0){
	    int b;
	    cin>>b;
	    b=b-2;
	    b=b/2;
	    b=(b*(b+1))/2;
	    cout<<b<<endl;
	    tc--;
	}