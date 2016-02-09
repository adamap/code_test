



// Write a function that add two numbers A and B. You should not use + or any arithmetic operators. 
// Example 
//
// Given a=1 and b=2 return 3
//
// Note 
// There is no need to read data from standard input stream. Both parameters are given in function aplusb, you job is to calculate the sum and return it.
//
// Challenge 
// Of course you can just return a + b to get accepted. But Can you challenge not do it like that?
//
// Clarification 
// Are a and b both 32-bit integers?
// Yes.
// Can I use bit operation?
// Sure you can.

class Solution {
public:
      /*
      * @param a: The first integer
      * @param b: The second integer
      * @return: The sum of a and b
      */
  int aplusb(int a, int b) 
  {
    while(b != 0)
    {
      int carry = a & b;
      a = a ^ b;
      b = carry << 1;
    }
         
    return a;
  }
};
