#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
       
        int n = nums.size();
        int reachable = 0;
        
        for(int i = 0; i<n; i++){
            if(reachable < i)
                return false;
            
            reachable = max(reachable, i+nums[i]);
        }
        return true;
        
        
    }
};

int main() {

    int ele;
    vector<int> nums;
    while(cin.peek() != '\n' and cin.peek() != EOF){
        cin>>ele;
        nums.push_back(ele);
    }

    Solution s;
    s.canJump(nums) ? cout<<"true"<<endl : cout<<"false"<<endl;
    return 0;
}