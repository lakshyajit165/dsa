#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = num.size();
        stack<char> s;
        
        // pop from stack, if a peak is encountered, push to stack if char is not 0 (or stack not empty) 
        for(char c : num){
            
           
            while(!s.empty() and k > 0 and s.top() > c){
                s.pop();
                k--;
            }
            
            if(!s.empty() or c != '0')
                s.push(c);
        }
            
        // if all the characters are in ascending order
        while(!s.empty() and k--){
            s.pop();
        }    
        if(s.empty())
            return "0";
            
        // form a string out of the stack for the smallest number
            
       while(!s.empty()){
           num[n-1] = s.top();
           s.pop();
           n--;
       }
        
       return num.substr(n);
        
        
    }
};
int main() {

    string str;
    int k;

    cin>>str>>k;

    Solution s;

    cout<<s.removeKdigits(str, k)<<endl;
}