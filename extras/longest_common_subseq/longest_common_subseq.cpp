#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int m = text1.length();
        int n = text2.length();
        
        int dp[m+1][n+1];
        
        memset(dp, 0, sizeof(dp[0][0])*(m+1)*(n+1));
        
        for(int i = m-1; i>=0; i--)
            for(int j = n-1; j>=0; j--){
                if(text1[i] == text2[j]) dp[i][j] = 1+dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        
        return dp[0][0];
    }
};
int main() {

    string s1, s2;
    cin>>s1>>s2;
    
    Solution s;
    
    cout<<s.longestCommonSubsequence(s1, s2)<<endl;
    return 0;
}