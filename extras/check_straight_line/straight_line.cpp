
/*


You are given an array coordinates, coordinates[i] = [x, y], 
where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

 

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
       
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        if(coordinates.size() == 1 || coordinates.size() == 2)
            return true;
        
        int y_diff = abs(coordinates[1][1] - coordinates[0][1]);
        int x_diff = abs(coordinates[1][0] - coordinates[0][0]);
        
        for(int i = 2; i<coordinates.size(); i++){
            
            int curr_ydiff = abs(coordinates[i][1] - coordinates[i-1][1]);
            int curr_xdiff = abs(coordinates[i][0] - coordinates[i-1][0]);
            
            if(x_diff * curr_ydiff != y_diff * curr_xdiff)
                return false;
        }
        
        return true;
    }
};  
int main() {

    // custom input
    int n;
    cin>>n;

    vector<vector<int>> points;

    for(int i = 0; i<n; i++){
        int x, y;
        cin>>x>>y;
        vector<int> point{x,y};
        points.push_back(point);
    }

    Solution s;
    cout<<s.checkStraightLine(points)<<endl;


    return 0;
}