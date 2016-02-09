//
//
//Given a string, find all permutations of it without duplicates.
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
//
// Given "abb", return ["abb", "bab", "bba"].
//
// Given "aabb", return ["aabb", "abab", "baba", "bbaa", "abba", "baab"].
// 

void stringPermutation2_helper(string str, vector<int>& isVisited, string temp, vector<string> &result)
{
    if (temp.size() == str.size())
    {
        result.push_back(temp);
        return;
    }
    
    
    for ( int i = 0; i < str.size(); i++)
    {
        if ( i > 0 && str[i] == str[i-1] && isVisited[i-1] == 0)
        {
            continue;
        }
        if (0 == isVisited[i] )
        {
            isVisited[i] = 1;
            temp.push_back(str[i]);        
            stringPermutation2_helper(str, isVisited, temp, result);
            temp.pop_back();
            isVisited[i] = 0;
        }
    }
}

class Solution {
public:
    /**
     * @param str a string
     * @return all permutations
     */
    vector<string> stringPermutation2(string& str) 
    {
        // Write your code here
        vector<string> result;

        if (0 == str.size())
        {
            result.push_back(""); 
            return result;
        }
        sort(str.begin(), str.end());
        string temp;
        vector<int>isVisited(str.size(), 0);
        
        stringPermutation2_helper(str, isVisited, temp, result);
        
        return result;
    }
};
