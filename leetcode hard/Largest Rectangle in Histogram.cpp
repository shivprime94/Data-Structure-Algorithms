/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/

#include<bits/stdc++.h>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea=0;
      
        stack<int> s;
        int n=heights.size();
        int tp;
        int i=0;
        while(i<n)
        {
            if(s.empty() || heights[s.top()]<=heights[i])
                s.push(i++);
            else
            {
                tp=s.top();
                s.pop();
                int width=(s.empty() ? i : 
								i - s.top() - 1); 
                int area=heights[tp]* width;
                
                if(maxarea<area)
                    maxarea=area;
            }
        }
        
        while(s.empty()==false)
        {
            tp=s.top();
                s.pop();
                int area=heights[tp]* (s.empty() ? i : (i-s.top()-1) );
                
                if(maxarea<area)
                    maxarea=area;
        }
        
        
        return maxarea;
    }
};
