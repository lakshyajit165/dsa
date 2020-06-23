/*

The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) 
was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer.
 If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers)
 upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below,
 the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)
 

Note:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int r = dungeon.size();
        int c = dungeon[0].size();
        
        vector<vector<int>> dp(r, vector<int>(c));
        
        for(int i = r-1; i>=0; i--){
            for(int j = c-1; j>=0; j--){
                
                // last cell
                if(i == r-1 and j == c-1)
                    dp[i][j] = min(0, dungeon[i][j]);
                // last row
                else if(i == r-1)
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j+1]);
                // last column
                else if(j == c-1)
                    dp[i][j] = min(0, dungeon[i][j] + dp[i+1][j]);
                // any other cell
                else
                    dp[i][j] = min(0, max(dungeon[i][j] + dp[i+1][j], dungeon[i][j] + dp[i][j+1]));
                
            }
        }
        
        return abs(dp[0][0]) + 1;
    }
};
int main() {

    vector<vector<int>> dungeon;

    // custom input
    int m, n, ele;
    cin>>m>>n;

    for(int i = 0; i<m; i++){
        vector<int> row;
        for(int i = 0; i<n; i++){
            cin>>ele;
            row.push_back(ele);
        }
        dungeon.push_back(row);
    }

    Solution s;
    cout<<s.calculateMinimumHP(dungeon)<<endl;
    return 0;
}