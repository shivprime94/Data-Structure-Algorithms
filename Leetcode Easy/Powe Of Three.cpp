class Solution {
public:
    bool isPowerOfThree(int n) {
        long long temp= 1; 
        while(temp<= n){
            if(n== temp){
                return true; 
            }
            temp*= 3; 
        }
        return false; 
    }
};
