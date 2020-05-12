/*

In a town, there are N people labelled from 1 to N.  
There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing 
that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge. 
Otherwise, return -1.



*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<pair<int,int>> arr(N+1,{0,0});
        
        for(int i = 0; i<trust.size(); i++){
            arr[trust[i][0]].first += 1;
            arr[trust[i][1]].second += 1;
            
            }
        
        for(int i = 1; i<=N; i++){
            if(arr[i].first == 0 and arr[i].second == N-1)
                return i;
    }
        return -1;
        }
};

int main() {

    Solution s;

    vector<vector<int>> v1{{1,3},{2,3},{3,1}};
    cout<<s.findJudge(3, v1)<<endl;

    vector<vector<int>> v2{{1,3},{1,4},{2,3},{2,4},{4,3}};
    cout<<s.findJudge(4, v2)<<endl;
    return 0;
}