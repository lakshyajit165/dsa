#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int m = word1.length();
        int n = word2.length();
        // create a table to store results of subproblems
        int dp[m + 1][n + 1];
        
        // fill the dp table
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                
                // if first string is empty, only option 
                // is to insert all characters of second string
                if(i == 0)
                    dp[i][j] = j; // min operations = j
                
                // if second string is empty, only option is
                // to insert all characters of first string
                else if(j == 0)
                    dp[i][j] = i; // Min operations = i
                
                // if last chars are equal, ignore the last characters
                // and recur for the remaining string
                else if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                
                // if the last character is different, consider all 
                // possibilities and find the minimum
                else 
                    dp[i][j] = 1 + min(dp[i][j - 1], // Insert
                                      min(dp[i - 1][j], // Remove
                                      dp[i - 1][j - 1] // Replace
                                      ));
            }
        }
        
        return dp[m][n];
    }
};
int main() {

    string s1,s2;
    cin>>s1>>s2;

    Solution s;
    cout<<s.minDistance(s1, s2)<<endl;
    return 0;
}