//Given an integer array, adjust each integers so that the difference of every adjacent integers are not greater than a given number target.
//
//If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i]-B[i]|
//
//
//Given [1,4,2,3] and target = 1, one of the solutions is [2,3,2,3], the adjustment cost is 2 and it's minimal. 
//
//Return 2.
//
//Note 
//
//You can assume each number in the array is a positive integer and not greater than 100.



int abs_calc(int a)
{
    return (a>0)?a:(-a);
}

int min_calc( int a, int b)
{
    return (a<b)?a:b;
}



////////////////////////////////


// most straightforward using recursion, exceed time limit of course

void MinAdjustmentCost_helper2(vector<int> &A, vector<int> &B, int index, int target, int cost, int &min_cost)
{
  if (index == A.size() )
  {
    if (cost < min_cost)
    {
//cout << B[0] << " " << B[1] << " " << B[2] << " " << B[3] << " " << cost << " " << endl;
      min_cost = cost;
    }
    return;
  }

  for (int i = 1; i <= 100; i++)
  {
    if ( index > 0 && abs(i - B[index - 1]) > target)
    {
      continue;
    }
    B[index] = i;
    cost += abs(i - A[index]);
    MinAdjustmentCost_helper2(A, B, index + 1, target, cost, min_cost);
    cost -= abs(i - A[index]);
    B[index] = A[index];
  }
}

int MinAdjustmentCost2(vector<int> A, int target)
{
  vector<int>B(A);

  int min_cost = INT_MAX;

  int cost = 0;

  MinAdjustmentCost_helper2(A, B, 0, target, cost, min_cost);

  return min_cost;
}

////////////////////////////////
//memorization to speed up optimization
int MinAdjustmentCost3(vector<int> A, int target)
{
  vector<int>B(A);

  int cost = 0;

  vector<vector<int> > m(A.size(), vector<int>(100, INT_MAX));

  int min_cost = MinAdjustmentCost_helper3(A, B, 0, target, m);

  return min_cost;
}


int MinAdjustmentCost_helper3(vector<int> &A, vector<int> &B, int index, int target, vector<vector<int> > &m)
{
  if (index >= A.size())
  {
    return 0;
  }

  int diff = 0;
  int min = INT_MAX;

  for (int i = 1; i <= 100; i++)
  {
    if (index > 0 && abs(i - B[index - 1]) > target)
    {    
      continue;
    }

    //memorization to speed up
    if (m[index][i] != INT_MAX)
    {
      diff = m[index][i];
      min = (min < diff) ? min : diff;
      continue;
    }

    B[index] = i;
    diff = abs(i - A[index]);
    diff += MinAdjustmentCost_helper3(A, B, index + 1, target, m);
    min = (min < diff)?min:diff;

    //memorization to speed up
    m[index][i] = diff;
    B[index] = A[index];
  }
  return min;
}

///////////////////////////

int MinAdjustmentCost1_helper(vector<int>&A, vector<int>&B, vector<vector<int> > &m, int target, int index)
{
    int len = A.size();
    if ( index >= len)
    {
        return 0;
    }
    
    int diff = 0;
    int min = INT_MAX;
    
    for (int i = 0; i <= 100; i++)
    {
        if ( index != 0 && abs_calc(i - B[index-1]) > target)
        {
            continue;
        }
        
        if (m[index][i] != INT_MAX)
        {
            diff = m[index][i];
            min = min_calc(diff, min);
            continue;
        }
        
        B[index] = i;
        
        diff = abs_calc(i-A[index]);
        
        diff += MinAdjustmentCost1_helper(A, B, m, target, index+1);
        
        min = min_calc(min, diff);
        
        m[index][i] = diff;
        
        B[index] = A[index];
    }
    
    return min;
}

int MinAdjustmentCost1(vector<int> A, int target)
{
    if ( 0 == A.size())
    {
        return 0;
    }
    vector<int> B(A);
    
    int n = A.size();
        
    vector<vector<int> > m(n, vector<int>(101, INT_MAX));

    return MinAdjustmentCost1_helper(A, B, m,  target, 0);
    
}

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) 
    {
        // write your code here
            
        //int ret = MinAdjustmentCost1(A, target);  
        int ret = MinAdjustmentCost2(A, target);
            
        return ret;
            
    }
};
