//
//
//Given a set of distinct integers, return all possible subsets.
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
//
// If S = [1,2,3], a solution is:
// [
//   [3],
//     [1],
//       [2],
//         [1,2,3],
//           [1,3],
//             [2,3],
//               [1,2],
//                 []
//                 ]
//
//
//                 Note 
//                 Elements in a subset must be in non-descending order.
//                 The solution set must not contain duplicate subsets.
//
//                 Challenge 
//
//                 Can you do it in both recursively and iteratively?
//
void subsets_helper( vector<int> &nums, vector<vector<int> >&result, vector<int>list, int pos )
{
    result.push_back(list);
    
    for (int i = pos; i < nums.size(); i++)
    {
        list.push_back(nums[i]);
        subsets_helper(nums, result, list, i+1);
        list.pop_back();
    }
}

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) 
    {
    // write your code here
    vector<vector<int> >result;
    vector<int>list;
    
    subsets_helper(nums, result, list, 0);
    return result;
    
    }
};
