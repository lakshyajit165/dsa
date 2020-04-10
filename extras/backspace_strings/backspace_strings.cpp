/*

Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Example 1:

Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
Example 2:

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
Example 3:

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
Example 4:

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
Note:

1 <= S.length <= 200
1 <= T.length <= 200
S and T only contain lowercase letters and '#' characters.


*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        
        deque<char> first;
        deque<char> second;
        
        string finalfirst = "";
        string finalsecond = "";
        
        for(int i = 0; i<S.length(); i++){
            if(S[i] != '#')
                first.push_back(S[i]);
            else if(!first.empty())
                    first.pop_back();
        }
        
        for(int i = 0; i<T.length(); i++){
            if(T[i] != '#')
                second.push_back(T[i]);
            else if(!second.empty())
                    second.pop_back();
        }
        
        while(!first.empty()){
            finalfirst += first.front();
            first.pop_front();
        }
        
        while(!second.empty()){
            finalsecond += second.front();
            second.pop_front();
        }
        
        return finalfirst == finalsecond;
    }
};

int main() {

    string s1, s2;
    cin>>s1>>s2;

    Solution s;
    cout<<s.backspaceCompare(s1, s2);

    return 0;
}