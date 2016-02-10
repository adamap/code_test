//
//
//For a given source string and a target string, you should output the first index(from 0) of target string in source string.
//
//If target does not exist in source, just return -1.
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
//
// If source = "source" and target = "target", return -1.
//
// If source = "abcdabcdefg" and target = "bcd", return 1.
//
// Challenge 
//
// O(n2) is acceptable. Can you implement an O(n) algorithm? (hint: KMP)
//
class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) 
    {
        // write your code here
        const char *source1 = source;

       if (source == NULL || target == NULL)
       {
    	return -1;
       }	
    
       if (*source == '\0' && *target == '\0')
       {
        return 0;
       }
   
    while (*source1 != '\0')
    {
      const char *source2 = source1;
      const char *target2 = target;

    while (*source2 && *target2 && *source2 == *target2)
    {
      source2++;
      target2++;
    }

    if (*target2 == '\0')
    {
      return (source1 - source);
    }
    else if (*source2 == '\0')
    {
      return -1;
    }
    else
    {
      source1++;
    }
    }

    return -1;
    }
};
