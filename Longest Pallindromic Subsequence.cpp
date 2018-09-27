
//RECURSIVE
int lps(char *seq, int i, int j) 
{ 
   // Base Case 1: If there is only 1 character 
   if (i == j) 
     return 1; 
  
   // Base Case 2: If there are only 2 characters and both are same 
   if (seq[i] == seq[j] && i + 1 == j) 
     return 2; 
  
   // If the first and last characters match 
   if (seq[i] == seq[j]) 
      return lps (seq, i+1, j-1) + 2; 
  
   // If the first and last characters do not match 
   return max( lps(seq, i, j-1), lps(seq, i+1, j) ); 
} 




//DP----TOP DOWN

public int longestPalindromeSubseq(String s) {
        if(s == null || s.isEmpty())
            return 0;
        int n = s.length();
        int [][] dp = new int[n][n];
        return func(s,0,n-1,dp);
    }
    private int func(String s, int start, int end, int[][] dp) {
        if(start>end || (start<0) || (start>s.length()) || (end<0) || (end>s.length()))
            return 0;
        if(start == end)
            return 1;
        if(dp[start][end]>0)
            return dp[start][end];
        int val = 0;
        if(s.charAt(start) == s.charAt(end)) {
            val = 2+func(s,start+1,end-1,dp);
        }
        else {
            val = Math.max(func(s,start+1,end,dp),func(s,start,end-1,dp));
        }
        dp[start][end] = val;
        return val;
    }
