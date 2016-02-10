//
//
//Implement a stack with min() function, which will return the smallest number in the stack.
//
//It should support push, pop and min operation all in O(1) cost.
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
// push(1)
// pop()   // return 1
// push(2)
// push(3)
// min()   // return 2
// push(1)
// min()   // return 1
//
//
// Note 
//
// min operation will never be called if there is no number in the stack.
stack<int>s;
stack<int>min_s;

int min_calc(int a, int b)
{
    return (a<b)?a:b;    
}

class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) 
    {
        s.push(number);
        if (!min_s.empty())
        {
            min_s.push(min_calc(number, min_s.top()));
        }
        else
        {
            min_s.push(number);
        }
        // write your code here
    }

    int pop() 
    {
        // write your code here
        int num = s.top();
        min_s.pop();
        s.pop();
        return num;

    }

    int min() 
    {
        // write your code here
        return min_s.top();
    }
};



