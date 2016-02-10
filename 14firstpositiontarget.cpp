//
//
//For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.
//
//If the target number does not exist in the array, return -1.
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
//
// If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.
//
// Challenge 
//
// If the count of numbers is bigger than 2^32, can your code work properly?
//
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) 
    {
        // write your code here
        int start = 0; int end = array.size()-1;
        int found = 0;

        while (start <= end)
        {
            int mid = start + (end-start)/2;
            
            if (array[mid] > target)
            {
                end = mid-1;
                
            }
            else if ( array[mid] < target)
            {
                start = mid+1;
            }
            else
            {
                found = 1;
                end = mid-1;
            
            }
        }
        
        if (found == 1)
        {
            return end+1;
            
        }
        else
        {
            return -1;
        }
    }
};
