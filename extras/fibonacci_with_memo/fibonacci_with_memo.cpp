/*
Fibonacci Number
Solution
The Fibonacci numbers, commonly denoted F(n) form a sequence, 
called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

 

Example 1:

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

*/


// ------------------- MEMOIZATION -----------------------------

/*


Memoization
To eliminate the duplicate calculation in the above case,
 as many of you would have figured out, one of the ideas would be 
 to store the intermediate results in the cache so that we could reuse them later without re-calculation.

This idea is also known as memoization, which is a technique 
that is frequently used together with recursion.

Memoization is an optimization technique used primarily to 
speed up computer programs by storing the results of expensive 
function calls and returning the cached result when the same inputs occur again. (Source: wikipedia)

Back to our Fibonacci function F(n). We could use a hash table to keep track 
of the result of each F(n) with n as the key. The hash table serves
 as a cache that saves us from duplicate calculations. 
 The memoization technique is a good example that demonstrates how one 
 can reduce compute time in exchange for some additional space.

For the sake of comparison, we provide the implementation of Fibonacci number solution with memoization below.

As an exercise, you could try to make memoization more general and 
non-intrusive, i.e. applying memoization without changing the original function.
 (Hint: one can refer to a design pattern called decorator).
 
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<int, int> cache;
    
    int fib(int N) {
    
        
        map<int, int>::iterator it = cache.find(N);
        if(it != cache.end())
           return it->second;
        
        int result;
        if(N < 2)
            result = N;
        else
            result = fib(N-1) + fib(N-2);
        
        cache.insert(make_pair(N, result));
        return result;
    }
};
int main() {

    int n;
    cin>>n;

    Solution s;
    cout<<s.fib(n)<<endl;
    return 0;
}