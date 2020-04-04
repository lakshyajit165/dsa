#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    
    int count = 0;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] != 0){
            nums[count] = nums[i];
            count++;
        }
    }
    
    for(int i = count; i < nums.size(); i++){
        nums[i] = 0;
    }
}


int main() {

    int n,ele;
    cin>>n;

    vector<int> nums;
    
    for(int i = 0; i<n; i++){
        cin>>ele;
        nums.push_back(ele);
    }

    moveZeroes(nums);

    for(int i = 0; i<n; i++)
        cout<<nums[i]<<" ";
    return 0;
}
