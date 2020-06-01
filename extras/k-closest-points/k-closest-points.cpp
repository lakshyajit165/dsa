/*

We have a list of points on the plane.  Find the K closest points to the origin (0, 0).

(Here, the distance between two points on a plane is the Euclidean distance.)

You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

 

Example 1:

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]
Explanation: 
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].
Example 2:

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]
(The answer [[-2,4],[3,3]] would also be accepted.)
 

Note:

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000



*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(K == points.size())
            return points;
        
        multimap<double, vector<int>> mymap;
        
        // store dist from origin and the points in multimap(sort the values in asc, acc to key, by default)

        for(auto point : points) {
            double dist = sqrt(pow(point[0], 2) + pow(point[1],2));
            mymap.insert(make_pair(dist, point));
        }
        
        // store the first k values from the multimap
        int count = 0;
        vector<vector<int>> res;
        for(auto m : mymap){
            if(count == K)
                break;
            res.push_back(m.second);
            count++;
        }
        
        return res;
        
    }
};
int main() {

   
    vector<vector<int>> points = {{3,3}, {5,-1}, {-2, 4}};
    int k = 2;

    Solution s;
    vector<vector<int>> res = s.kClosest(points, k);

    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<res[i].size(); j++)
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}