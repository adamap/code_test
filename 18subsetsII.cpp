//
//
//Given a list of numbers that may has duplicate numbers, return all possible subsets
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
//
// If S = [1,2,2], a solution is:
// [
//   [2],
//     [1],
//       [1,2,2],
//         [2,2],
//           [1,2],
//             []
//             ]
//
//
//             Note 
//             Each element in a subset must be in non-descending order.
//             The ordering between two subsets is free.
//             The solution set must not contain duplicate subsets.
//
//             Challenge 
//
//             Can you do it in both recursively and iteratively?
//
void subsetsWithDup_helper(const vector<int> &S, vector<vector<int> >&result,  vector<int>list, int pos)
{
    result.push_back(list);
    
    for (int i = pos; i < S.size(); i++)
    {
        if ( i > pos && S[i] == S[i-1])
        {
            continue;
        }
        
        list.push_back(S[i]);
        subsetsWithDup_helper(S, result, list, i+1);
        list.pop_back();
    }

}

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup( vector<int> &S) 
    {
        // write your code here
        vector<vector<int> >result;
        vector<int>list;
        sort(S.begin(), S.end());
        subsetsWithDup_helper(S, result, list, 0);
        
        return result;
    }
};

