//Given n items with size Ai and value Vi, and a backpack with size m. What's the maximum value can you put into the backpack?
//Example 
//
//Given 4 items with size [2, 3, 5, 7] and value [1, 5, 2, 4], and a backpack with size 10. The maximum value is 9.
//
//Note 
//
//You cannot divide item into small pieces and the total size of items you choose should smaller or equal to m.
//
//Challenge 
//
//O(n x m) memory is acceptable, can you do it in O(m) memory?











int backPackII_2(int m, vector<int> A, vector<int> V) 
{
    if ( A.size() == 0 || V.size() == 0)
    {
        return 0;
    }
    
    int n = A.size();
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for ( int i = 1; i <= n; i++)
    {
        for ( int j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i-1][j];            
            
            if ( j >= A[i-1])
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-A[i-1]] + V[i-1]);
            }
        }
    }
    
    return dp[n][m];    
}

int backPackII_1(int m, vector<int> A, vector<int> V) 
{
        if ( A.size() == 0 || V.size() == 0)
        {
            return 0;
        }
        int n = A.size();
        vector<vector<int> >dp(n+1, vector<int>(m+1, 0));
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if ( j >= A[i-1])
                {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]] + V[i-1]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
    
    
}


class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) 
    {
        // write your code here
        return backPackII_2(m, A, V);
    }
};
