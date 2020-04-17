#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int left_prod[nums.size()];
        left_prod[0] = 1;
        
        for(int i = 1; i<nums.size(); i++){
            left_prod[i] = left_prod[i-1] * nums[i-1];
        }
        
//         int right_prod[nums.size()];
//         right_prod[nums.size()-1] = 1;
        
//         for(int i = nums.size()-2; i>=0; i--){
//             right_prod[i] = right_prod[i+1]*nums[i+1];
//         }
        int R = 1;
         for(int i = nums.size()-2; i>=0; i--){
            R = R * nums[i+1];
            left_prod[i] = left_prod[i] * R;
        }
//         1 2 3 4
            
//         1 1 2 6
            
//         24    
//         24  12  8
            
//        24 8 4 1
        
        vector<int> v(left_prod, left_prod + sizeof(left_prod) / sizeof(left_prod[0]));
        
        
        return v;
    }
};

int main(){

    Solution s;
    vector<int> v;
    int ele;

    while(cin.peek() != '\n' and cin.peek() != EOF){
        cin>>ele;
        v.push_back(ele);
    }

    vector<int> res = s.productExceptSelf(v);
    
    for(int i : res)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}