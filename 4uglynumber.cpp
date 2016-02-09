


//
//
//Ugly number is a number that only have factors 3, 5 and 7. 
//
//Design an algorithm to find the Kth ugly number. The first 5 ugly numbers are 3, 5, 7, 9, 15 ...
//
//Have you met this question in a real interview? 
//
//Yes
// 
// Example 
//
// If K=4, return 9.
//
// Challenge 
//
// O(K log K) or O(K) time.
// 
//
//



long long maxdivide(long long no, long long b)
{
    while(no%b == 0)
    {
        no = no/b;
    }
    return no;
}


int isugly(long long no)
{
    no = maxdivide(no, 3);
    no = maxdivide(no, 5);
    no = maxdivide(no, 7);
    
    return (no == 1)?1:0;
}

long long kthPrimeNumber1(int k) 
{
    long long i = 1;
    int count  = 1;
        
    while ( k >= count)
    {
        i++;
        if ( isugly(i))
        {
            count++;
        }
    }
    return i;    
}

long long kthPrimeNumber2(int k) 
{
    priority_queue<long long, vector<long long>,greater<long long>>q;
    unordered_map<long long, int>hash_table;
    
    long long primes[3];
    primes[0] = 3;
    primes[1] = 5;
    primes[2] = 7;
    
    for (int i = 0; i < 3; i++)
    {
        q.push(primes[i]);
        hash_table[primes[i]] = 1;
    }
    
    long long number = 0;
    for (int i = 0; i < k; i++)
    {
        number = q.top();
        q.pop();
        
        for (int j = 0; j < 3; j++)
        {
            if ( hash_table.find(number*primes[j]) == hash_table.end())
            {
                q.push(number*primes[j]);
                hash_table[number*primes[j]] = 1;
            }
        }
        
    }
    return number;    
}



class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) 
    {
        // write your code here
        long long ret = kthPrimeNumber2(k);
        return ret;
    }
};
