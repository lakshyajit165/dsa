/*

Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.




*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char, int> letter_count;
        vector<char> letters;
        
        for(int i = 0; i<s.length(); i++){
            letter_count[s[i]]++;
            letters.push_back(s[i]);
        }
        
//         for(auto c : letter_count)
//             cout<<c.first<<" "<<c.second<<endl;
        
        for(int i = 0; i<letters.size(); i++){
            if(letter_count[letters[i]] == 1)
                return i;
        }
        
        return -1;
    }
};
int main(){

    string str;
    cin>>str;

    Solution s;

    cout<<s.firstUniqChar(str)<<endl;
    return 0;
}