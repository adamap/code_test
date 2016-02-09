







//Write an algorithm which computes the number of trailing zeros in n factorial.
//Example 
//
//11! = 39916800, so the out should be 2
//
//Challenge 
//
//O(log N) time

class Solution 
{
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) 
    {
    //int nums = 0;
    //for (int i = 5; i <= n; i=i+5)
    //{
    //    int temp = i;
    //    while( temp%5 == 0)
    //    {
    //    nums++;
    //    temp = temp/5;
    //   }
    //}
        long sum = 0;
        while (n != 0) {
            sum += n / 5;
            n /= 5;
        }
        return sum;

    }
};

