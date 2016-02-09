

//
//
//Find K-th largest element in an array.
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
//
// In array [9,3,2,4,8], the 3rd largest element is 4.
//
// In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.
//
// Note 
//
// You can swap elements in the array
//
// Challenge 
//
// O(n) time, O(1) extra memory.


    void swap_qsort(vector<int>&arr, int index1, int index2)
    {   
      int temp = arr[index1];
      arr[index1] = arr[index2];
      arr[index2] = temp;
    }
    
    int qsort_part_l(vector<int> &arr, int l, int r)
    {
      int pivot = arr[r];
      int pivot_pos = r;

      for (int i = r-1; i >=l; i--)
      {
        if ( arr[i] > pivot)
        {
         swap_qsort(arr, i, --pivot_pos);
        }
      }

      swap_qsort(arr, r, pivot_pos);

      return pivot_pos;
    }
     
    int kthlargestelement_helper(vector<int> &arr, int l, int r, int k)
    {   
      if (k > 0 && k <= r-l+1)
      {
        int pos = qsort_part_l(arr, l, r);

        if ( r-pos+1 == k)
        {
          return arr[pos];
        }
        else if ( r-pos+1  < k)
        {
          return kthlargestelement_helper(arr,  l, pos-1, k - (r-pos+1) );
        }
        else
        {
          return kthlargestelement_helper(arr, pos+1, r, k);
        }
      } 

      return INT_MAX;

    }

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
     
   
     
    int kthLargestElement(int k, vector<int> nums) 
    {
        int ret = kthlargestelement_helper(nums, 0, nums.size()-1, k);
        
        return ret;
    }
};
