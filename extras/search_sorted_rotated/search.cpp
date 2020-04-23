#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() < 1) return -1;
        
        if(nums.size() == 0){
            return nums[0] == target ? 0 : -1;
        }
        
        int low = 0, high = nums.size()-1;
        while(low <= high){
            
            int pivot = low + (high - low)/2;
            if(nums[low] == target) return low;
            
            if(nums[high] == target) return high;                                           
            
            if(nums[pivot] == target) return pivot;
            
            // left half is sorted
            if(nums[low] < nums[pivot]){
                
                if(target < nums[low] || target > nums[pivot])
                    low = pivot + 1;
                else
                    high = pivot - 1;
            }else{
                // right half is sorted
                if(target > nums[high] || target < nums[pivot])
                    high = pivot - 1;
                else
                    low = pivot + 1;
            }
            
        }
        return -1;
    }
};

int main(){

    vector<int> arr;
    int ele, target;

    while(cin.peek() != '\n' and cin.peek() != EOF){
        cin>>ele;
        arr.push_back(ele);
    }
    cin>>target;

    Solution s;
    cout<<s.search(arr, target)<<endl;
    return 0;

}