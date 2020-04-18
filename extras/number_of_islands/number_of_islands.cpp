/*


Given a 2d grid map of '1's (land) and '0's (water), 
count the number of islands. An island is surrounded by water and
 is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3


*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void markIslands(vector<vector<char>>& mat, int x, int y, int r, int c) {
        
        // handling base case
        if(x < 0 || x >= r || y < 0 || y >= c || mat[x][y] != '1')
            return;
        
        mat[x][y] = '2';
        
        // mark the islands in all 4 directions
        markIslands(mat, x+1, y, r, c); // RIGHT
        markIslands(mat, x-1, y, r, c); // LEFT
        markIslands(mat, x, y+1, r, c); // BOTTOM
        markIslands(mat, x, y-1, r, c); // TOP
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        // for FAST IO
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int num = 0;
        int rows = grid.size();
        
        if(rows == 0)
            return 0;
        
        int cols = grid[0].size();
        
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == '1'){
                    num++;
                    markIslands(grid, i, j, rows, cols);
                    
                }
            }
        }
        
        return num;
    }
};
int main(){

    // first input the rows and columns
    int r,c;
    char ele;
    cin>>r>>c;

    vector<vector<char>> A(r);

    for(int i = 0; i<r; i++){
        for(int j = 0; j<c; j++){
            cin>>ele;
            A[i].push_back(ele);
        }
    }
    
    Solution s;
    cout<<s.numIslands(A)<<endl;
    return 0;
}