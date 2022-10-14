bool isStrictlyPalindromic(int n) {
  
 for(int i = 2;i < n-1; i++)
 {
     if(!solve(n,i))
     {
         return false;
     }
 }
  return true;
