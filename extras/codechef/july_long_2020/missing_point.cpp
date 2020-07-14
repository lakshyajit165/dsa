/*

MISSING A POINT:

Chef has N axis-parallel rectangles in a 2D Cartesian coordinate system. 
These rectangles may intersect, but it is guaranteed that all their 4N vertices are pairwise distinct.

Unfortunately, Chef lost one vertex, and up until now, 
none of his fixes have worked (although putting an image of 
a point on a milk carton might not have been the greatest idea after all…). 
Therefore, he gave you the task of finding it! You are given the remaining 4N−1 points and you should find the missing one.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
Then, 4N−1 lines follow. Each of these lines contains two space-separated integers x and y denoting a vertex (x,y) of some rectangle.
Output
For each test case, print a single line containing two 
space-separated integers X and Y ― the coordinates of the missing point. It can be proved that the missing point can be determined uniquely.

Constraints
T≤100
1≤N≤2⋅105
|x|,|y|≤109
the sum of N over all test cases does not exceed 2⋅105
Subtasks
Subtask #1 (20 points):

T=5
N≤20
Subtask #2 (30 points): |x|,|y|≤105
Subtask #3 (50 points): original constraints

Example Input
1
2
1 1
1 2
4 6
2 1
9 6
9 3
4 3
Example Output
2 2


LOGIC:

since the rectangles are axis-parallel, the x and y coordinates of the missing point will appear odd number of times


*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll t, n, x,y,points, res_x, res_y;
 

  cin>>t;

  while(t--) {
    cin>>n;
    points = 4*n - 1;
    
    map<ll, ll> x_map;
    map<ll, ll> y_map;

    for(int i = 0; i<points; i++){
      cin>>x>>y;
      x_map[x]++;
      y_map[y]++;
    }
   
    for(auto it: x_map){
      if(it.second % 2 != 0){
        res_x = it.first;
        break;
      }
    }

    for(auto it: y_map){
      if(it.second % 2 != 0){
        res_y = it.first;
        break;
      }
    }

    cout<<res_x<<" "<<res_y<<endl;
  }
  return 0;
}