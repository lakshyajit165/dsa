#include<bits/stdc++.h>
using namespace std;
class Solution {
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int rows, int cols, int newColor, int source){
        
        if(sr < 0 or sr >= rows or sc < 0 or sc >= cols)
            return;
        else if(image[sr][sc] != source)
            return;
        else {
             image[sr][sc] = newColor;
             dfs(image, sr, sc-1, rows, cols, newColor, source);
             dfs(image, sr, sc+1, rows, cols, newColor, source);
             dfs(image, sr-1, sc, rows, cols, newColor, source);
             dfs(image, sr+1, sc, rows, cols, newColor, source);
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        if(newColor == image[sr][sc])
            return image;
        
        int rows = image.size();
        int cols = image[0].size();
        int source = image[sr][sc];
        
        dfs(image, sr, sc, rows, cols, newColor, source);
        
        return image;
    }

    // custom display function
    void display(vector<vector<int>> result){

        for(int i = 0; i<result.size(); i++){
            for(int j = 0; j<result[0].size(); j++)
                cout<<result[i][j]<<" ";
            cout<<endl;
        }
    }
};
int main() {

    vector<vector<int>> image{{1,2,1,1},{2,1,1,2},{1,0,1,0}};

    int sr = 1, sc = 2, newColor = 3;
    Solution s;

    vector<vector<int>> result = s.floodFill(image, sr, sc, newColor);
    s.display(result);

    cout<<endl;

    vector<vector<int>> image2{{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> result2 = s.floodFill(image2, 1, 1, 2);
    s.display(result2);
    
    return 0;
}