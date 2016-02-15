//Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.
//Example 
//
//For L=[232, 124, 456], k=7, return 114.



int calcCutNums(vector<int> L, int curlen)
{
    int nums = 0;
    for (int i = 0; i < L.size(); i++)
    {
        nums += L[i]/curlen;
    }
    
    return nums;
}

int woodCut1(vector<int> L, int k)
{
    if ( 0 == L.size())
    {
        return 0;
    }
    
    sort(L.begin(), L.end());
    
    int minlen = 1; int maxlen = L[L.size()-1];
    
    while (minlen +1 < maxlen)
    {
        int mid = minlen + (maxlen-minlen)/2;
        
        int cutNums = calcCutNums(L, mid);
        
        if (cutNums >=  k)
        {
            minlen = mid;
        }
        else 
        {
            maxlen = mid;
        }
    }
        
    if (calcCutNums(L, maxlen) >= k)
    {
        return maxlen;
    }
    if (calcCutNums(L, minlen) >= k)
    {
        return minlen;
    }
    return 0;
}



//////////////////////

int countNumber(vector<int>L, int mid)
{
    int ret = 0; 
    for (int i = 0; i < L.size(); i++)
    {
        ret += L[i]/mid;
    }
    return ret;
}

int woodCut0(vector<int> L, int k)
{
    sort(L.begin(), L.end());
    if ( L.size() == 0)
    {
        return 0;
    }
        
    int start = 1, end = L[L.size()-1];
        
    while(start + 1 < end)
    {
        int mid = start+(end-start)/2;
        if (countNumber (L, mid) >= k )
        {
            start = mid;
        }
        else
        {
            end = mid;
        }
    }
        
    if ( countNumber(L, end) >= k)
    {
        return end;
    }
    if ( countNumber(L, start) >= k)
    {
        return start;
    }
    return 0;
}

class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) 
    {
        int ret = woodCut1( L,  k);
        
        return ret;
    }
};


