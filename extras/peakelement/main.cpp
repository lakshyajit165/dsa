/*
 *
 * A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

Example 1:

Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
Example 2:

Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
             or index number 5 where the peak element is 6.
 *
 *
 *
 *
 * */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int begin = 0, end = nums.size() - 1;

        while(begin <= end) {

            int mid = begin + (end - begin)/2;

            if(mid + 1 < nums.size() && nums[mid] < nums[mid+1]){
                begin = mid + 1;
            }else if(mid - 1 >= 0 && nums[mid] < nums[mid - 1]){
                end = mid - 1;
            }else {
                return mid;
            }
        }
        return 0;
    }
};

int main() {

    int n;
    cin>>n;
    vector<int> nums;

    int ele;

    for(int i = 0; i<n; i++){
        cin>>ele;
        nums.push_back(ele);
    }

    Solution s;
    cout<<s.findPeakElement(nums);
    return 0;
}