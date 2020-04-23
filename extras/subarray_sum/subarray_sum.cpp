/*

Given an array of integers and an integer k, you 
need to find the total number of continuous subarrays 
whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] 
and the range of the integer k is [-1e7, 1e7].

*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        if(n == 0)
            return 0;
        
        unordered_map<int, int> mymap;
        int currSum = 0;
        int count = 0;
        int i = 0;
        
        while(i < n){
            
            currSum += nums[i];
            
            if(currSum == k)
                count+=1;
            
            if(mymap.find(currSum-k) != mymap.end())
                count += mymap[currSum-k];
            
            mymap[currSum] += 1;
            i++;
        }
        
        return count;
    }
};

int main() {

    int k,ele;
    vector<int> arr;

    
    while(cin.peek() != '\n' and cin.peek() != EOF){
        cin>>ele;
        arr.push_back(ele);
    }

    cin>>k;

    Solution s;
    cout<<s.subarraySum(arr, k)<<endl;

    return 0;
}