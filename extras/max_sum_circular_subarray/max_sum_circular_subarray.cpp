/*

Given a circular array C of integers represented by A, 
find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to
the beginning of the array.  
(Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the
 fixed buffer A at most once.  (Formally, 
 for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
Example 4:

Input: [3,-2,2,-3]
Output: 3
Explanation: Subarray [3] and [3,-2,2] both have maximum sum 3
Example 5:

Input: [-2,-3,-1]
Output: -1
Explanation: Subarray [-1] has maximum sum -1
 

Note:

-30000 <= A[i] <= 30000
1 <= A.length <= 30000



*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkAllNegative(vector<int>& A){
        
        for(int i : A){
            if(i > 0)
                return false;
        }
        
        return true;
        
    }
    
    int kadane(vector<int>& A) 
    {
        // stores maximum sum sub-array found so far
        int max_sum = A[0];

        // stores maximum sum of sub-array ending at current position
        int max_ending = A[0];

        // traverse the given array
        for (int i = 1; i < A.size(); i++)
        {
            // update maximum sum of sub-array "ending" at index i (by adding
            // current element to maximum sum ending at previous index i-1)


            // if maximum sum is negative, set it to 0 (which represents
            // an empty sub-array)
            max_ending = max(max_ending + A[i], A[i]);

            // update result if current sub-array sum is found to be greater
            max_sum = max(max_sum, max_ending);
        }

        return max_sum;
    }

    // Function to find maximum sum circular subarray in a given array
    int kadane_circular(vector<int>& A)
    {
        // negate all elements of the array
        for (int i = 0; i < A.size(); i++)
            A[i] = -A[i];

        // run Kadane's algorithm on modified array
        int negMaxSum = kadane(A);

        // restore the array
        for (int i = 0; i < A.size(); i++)
            A[i] = -A[i];

        /*  return maximum of

            1. sum returned by Kadane's algorithm on original array.

            2. sum returned by Kadane's algorithm on modified array +
                sum of all elements of the array.
        */

        return max(kadane(A), accumulate(A.begin(), A.end(), 0) + negMaxSum);
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(checkAllNegative(A))
            return *max_element(A.begin(), A.end());
        
        return kadane_circular(A);
    }
};

int main() {

    int ele;
    vector<int> A;
    while(cin.peek() != '\n' and cin.peek() != EOF){
        cin>>ele;
        A.push_back(ele);
    }

    Solution s;
    cout<<s.maxSubarraySumCircular(A)<<endl;
    return 0;
}