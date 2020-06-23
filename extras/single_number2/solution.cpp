/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
*/


// USED extra space
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        map<int, int> mymap;
        
        for(int i: nums)
            mymap[i]++;
        
        int res = -1;
        for(auto i: mymap)
            if(i.second == 1){
                res = i.first;
                break;
            }
        
        return res;
    }
};
int main() {

    vector<int> nums;
    int ele;

    while ((cin.peek() != '\n') && (cin.peek() != EOF)) {
        cin>>ele;
        nums.push_back(ele);
    }

    Solution s;
    cout<<s.singleNumber(nums)<<endl;
    return 0;

}