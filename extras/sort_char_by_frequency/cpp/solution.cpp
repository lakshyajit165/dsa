#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<char,int> map;
        
        for(int i=0;i<s.size();i++)
            map[s[i]]++;
        
        priority_queue<pair<int,char>> pq;
        
        for(auto x : map)
            pq.push({x.second,x.first});
        
        string st="";
        while(!pq.empty())
        {
            pair<int,char>x = pq.top();
            
            int temp = x.first;
            
            while(temp--)
                st += x.second;
            
            pq.pop();
        }
        
        return st;
    }
};

int main() {

    string str;
    cin>>str;

    Solution s;
    cout<<s.frequencySort(str)<<endl;
    return 0;
}