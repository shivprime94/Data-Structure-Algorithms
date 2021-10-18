class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0;
        int right = height.size()-1;
        int maxval = INT_MIN;
        while(left<right)
        {
            //we need area of the container i.e length*breadth
            //index wont be an issue (border)
            //height of bar will determine the length we need the min height else water spills
            //
            int minval = min(height[left],height[right]); //bar height
            //check for all possible combo and then pick the height 
            maxval = max(maxval,minval*(right-left));
            //comparing and updating the pointers
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
            
        }
        return maxval;
    }
};
