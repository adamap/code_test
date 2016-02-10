//
//
//Given a list of numbers, return all possible permutations.
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
//
// For nums = [1,2,3], the permutations are:
// [
//   [1,2,3],
//     [1,3,2],
//       [2,1,3],
//         [2,3,1],
//           [3,1,2],
//             [3,2,1]
//             ]
//
//
//             Challenge 
//
//             Do it without recursion.
void swap_ct(vector<int> &nums, int a, int b)
{
int temp = nums[a];
nums[a] = nums[b];
nums[b] = temp;
}

void permute_calc_t_helper(vector<int> &nums, vector<vector<int> > &result, int index)
{
if (index == nums.size() - 1)
{
result.push_back(nums);
return;
}

for (int i = index; i < nums.size(); i++)
{
swap_ct(nums, index, i);
permute_calc_t_helper(nums, result, index+1);
swap_ct(nums, index, i);
}

}


class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) 
    {
        // write your code here
        vector<vector<int> > result;

    permute_calc_t_helper( nums, result, 0 );

    return result;
    }
};
