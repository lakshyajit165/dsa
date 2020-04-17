/*


Given a string containing only three types of characters: '(', ')' and '*', 
write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')'
 or a single left parenthesis '(' or an empty string.
An empty string is also valid.

Example 1:
Input: "()"
Output: True


Example 2:
Input: "(*)"
Output: True


Example 3:
Input: "(*))"
Output: True

Note:
The string size will be in the range [1, 100].




*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int> st, star_st;
        
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == '*')
                    star_st.push(i);
            else if(s[i] == ')'){
                if(!st.empty())
                    st.pop();
                else if(!star_st.empty())
                        star_st.pop();
                else
                    return false;
            }
        }
        
        while(!st.empty() and !star_st.empty()){
            if(st.top() < star_st.top()){
                st.pop();
                star_st.pop();
            }else
                break;
        }
        
        return st.empty();
        
        
        
    }
};

int main() {

    Solution s;
    string str;
    cin>>str;
    
    s.checkValidString(str) ? cout<<"True"<<endl : cout<<"False"<<endl;

    return 0;
}