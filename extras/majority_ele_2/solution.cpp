/*


LOGIC

Approach 1: Boyer-Moore Voting Algorithm
Intuition

To figure out a O(1)O(1) space requirement, we would need to get this simple intuition first. For an array of length n:

There can be at most one majority element which is more than ⌊n/2⌋ times.
There can be at most two majority elements which are more than ⌊n/3⌋ times.
There can be at most three majority elements which are more than ⌊n/4⌋ times.
and so on.

Knowing this can help us understand how we can keep track of majority elements which satisfies O(1)O(1) space requirement.

If the current element is equal to one of the potential candidate, the count for that candidate is increased while leaving the count of the other candidate as it is.
If the counter reaches zero, the candidate associated with that counter will be replaced with the next element if the next element is not equal to the other candidate as well.
Both counters are decremented only when the current element is different from both candidates.














*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        //1st pass
        int count1 = 0, count2 = 0;
        int n = nums.size();
        
        int candidate1 = 1000000007, candidate2 = 1000000007;
        
        for(int i : nums){
            
            if(candidate1 != 1000000007 and candidate1 == i){
                count1++;
            }else if(candidate2 != 1000000007 and candidate2 == i){
                count2++;
            }else if(count1 == 0){
                candidate1 = i;
                count1++;
            }else if(count2 == 0){
                candidate2 = i;
                count2++;
            }else{
                count1--;
                count2--;
            }
            
        }
        
        vector<int> res;
        
        // 2nd pass
        count1 = 0;
        count2 = 0;
        
        for(int i : nums){
            if(i == candidate1 and candidate1 != 1000000007)
                count1++;
            else if(i == candidate2 and candidate1 != 1000000007)
                    count2++;
        }
        
        if(count1 > (n/3))
            res.push_back(candidate1);
        
        if(count2 > (n/3))
            res.push_back(candidate2);
        
        return res;
    }
};