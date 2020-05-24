/*
Interval List Intersections
Solution
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) denotes the set 
of real numbers x with a <= x <= b.  The intersection of two closed intervals 
is a set of real numbers that is either empty, or can be represented as a closed interval. 
 For example, the intersection of [1, 3] and [2, 4] is [2, 3].)

Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Reminder: The inputs and the desired output are lists of Interval objects, and not arrays or lists.

Note:

0 <= A.length < 1000
0 <= B.length < 1000
0 <= A[i].start, A[i].end, B[i].start, B[i].end < 10^9

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int>> res;
        int aptr = 0, bptr=0;
        vector<int> temp(2);
        
        while(aptr < A.size() and bptr < B.size()){
            
            if(B[bptr][1] >= A[aptr][0] and B[bptr][0] <= A[aptr][1]){
                temp[0] = max(A[aptr][0], B[bptr][0]);
                temp[1] = min(A[aptr][1], B[bptr][1]);
                res.push_back(temp);
            }
            
            if(A[aptr][1] > B[bptr][1])
                bptr += 1;
            else
                aptr += 1;
        }
        
        return res;
    }
};
int main() {

    vector<vector<int>> A{{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> B{{1,5},{8,12},{15,24},{25,26}};

    Solution s;
    vector<vector<int>> res = s.intervalIntersection(A, B);
    
    for(int i = 0; i<res.size(); i++){
        cout<<"["<<res[i][0]<<","<<res[i][1]<<"]"<<endl;
    }
    return 0;
}