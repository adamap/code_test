


//
//
//Merge two given sorted integer array A and B into a new sorted integer array.
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
//
// A=[1,2,3,4]
//
// B=[2,4,5,6]
//
// return [1,2,2,3,4,4,5,6]
//
// Challenge 
//
// How can you optimize your algorithm if one array is very large and the other is very small?
//
class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) 
    {
        // write your code here
        int n = A.size();
        int m = B.size();
        
        vector<int>ret(n+m, 0);
        
        int index = 0;
        int i = 0, j = 0;
        while (i < n && j < m )
        {
            if ( A[i] < B[j])
            {
                ret[index++] = A[i++];
            }
            else
            {
                ret[index++] = B[j++];
            }
        }
        
        while ( i < n)
        {
            ret[index++] = A[i++];
        }
        while ( j < m)
        {
            ret[index++] = B[j++];
        }
        
        return ret;
        
    }
};


