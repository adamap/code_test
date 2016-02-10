//
//
//Given a list of numbers with duplicate number in it. Find all unique permutations.
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
//
// For numbers [1,2,2] the unique permutations are:
// [
//   [1,2,2],
//     [2,1,2],
//       [2,2,1]
//       ]
//
//
//       Challenge 
//
//       Using recursion to do it is acceptable. If you can do it without recursion, that would be great!
//
void permuteUnique_helper(vector<int>nums, vector<int>visited, vector<vector<int> >&result, vector<int>temp)
{
if (temp.size() == nums.size())
{
result.push_back(temp);
return;
}

for (int i = 0; i < nums.size(); i++)
{
if (visited[i] == 1)
{
continue;
}
int j = i;
while (j > 0 )
{
    if( nums[i] == nums[j - 1] && visited[j - 1] == 0)
    {
        break;
    }
    j--;
}
if (j > 0)
{
    continue;
}

visited[i] = 1;
temp.push_back(nums[i]);
permuteUnique_helper(nums, visited, result, temp);
temp.pop_back();
visited[i] = 0;
}
}



class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) 
    {
        // write your code here
        vector<vector<int> > result;
    vector<int> visited(nums.size(), 0);
    vector<int> temp;

    permuteUnique_helper(nums, visited, result, temp);

    return result;
    }
};
