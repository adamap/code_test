

//
//
//Given a string and an offset, rotate string by offset. (rotate from left to right)
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
//
// Given "abcdefg".
// offset=0 => "abcdefg"
// offset=1 => "gabcdef"
// offset=2 => "fgabcde"
// offset=3 => "efgabcd"
//
//
// Challenge 
//
// Rotate in-place with O(1) extra memory.
// 

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset)
    {
        //wirte your code here
        int n = str.size();
        
        if ( n == 0)
        {
            return;
        }
        
        offset = offset%n;
        
        for (int i = 0; i < offset; i++)
        {
            char c = str[str.size()-1];
            
            for ( int i = str.size()-1; i >=1; i--)
            {
                str[i] = str[i-1];
            }
            str[0] = c;
        }
        
        
    }
};

