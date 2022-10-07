class Solution {
  public:
    int canReach(int A[], int N) {
        // code here
        int maximumDistance = 0;
        int current = 0;
        
        
        // Time complexity O(n) of for loop;
        for(int i=0; i<N-1; i++){
            maximumDistance = max(maximumDistance, A[i]+i);
            
            if(i==current ){
                current = maximumDistance;
            }
        }
       
        
        return current >= N-1 ? 1 : 0;
        
        // Time complexity - O(n) becuase of for loop;
        // Space complexity - O(1) as no extra space is used;
    }
};
