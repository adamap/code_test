//Given n items with size Ai, an integer m denotes the size of a backpack. How full you can fill this backpack? 
//
//If we have 4 items with size [2, 3, 5, 7], the backpack size is 11, we can select [2, 3, 5], so that the max size we can fill this backpack is 10. If the backpack size is 12. we can select [2, 3, 7] so that we can fulfill the backpack.
//
//You function should return the max size we can fill in the given backpack.


nt backPack2(int m, vector<int> A) 
{
    int n = A.size();
    
    int totalsize = 0;
    for ( int i = 0; i < A.size(); i++)
    {
        totalsize += A[i];
    }
    
    if ( totalsize <= m)
    {
        return totalsize;
    }

    //dp[i][j] if selecting from i items can full up j space in bag
    // 1 yes, 0 no
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    
    // seletc 0 item can always fill up to 0 space, set 1
    for ( int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    
    // 0 items can not fill up 1...m space of bad
    for ( int i = 1; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    
    
    for ( int i = 1; i <= n; i++)
    {
        for ( int j = 1; j <= m; j++)
        {
            // dont select A[i-1], then dp[i][j] = dp[i-1][j]
            dp[i][j] = dp[i-1][j];
            
            if ( j >= A[i-1] && 1 == dp[i-1][j-A[i-1]] )
            {
                dp[i][j] = 1;        
            }
        }
    }
    
    for ( int i = m; i >= 0; i--)
    {
        if ( dp[n][i] == 1)
        {
            return i;
        }
    }
    
    return 0;    
    
}

int backPack1(int m, vector<int> A)
{
       if ( 0 == A.size() )
        {
            return 0;
        }
        int n = A.size();
        
        int sum = 0;
        for (int i = 0; i < A.size(); i++)
        {
            sum += A[i];
        }
        
        if ( sum <= m)
        {
            return sum;
        }
        
        vector<vector<int> >dp(n+1, vector<int>(m+1, 0));
        
        dp[0][0] = 1;
        
        for ( int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = dp[i-1][j];
                
                if ( j >= A[i-1] && (1 == dp[i-1][j-A[i-1]]))
                {
                    dp[i][j] = 1;
                }
            }
        }
        
        for ( int i = m; i >= 0; i--)
        {
            if ( dp[n][i] == 1)
            {
                return i;
            }
        }
        
        return 0;
    
    
}

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) 
    {
        // write your code here
        return backPack2( m,  A); 
    }
};
