#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   vector<int> getRow(int k) {
        
        vector<int> ans(k+1,0);
        vector<int> temp(k+1,0);
       
        ans[0] = 1;
        temp[0] = 1;
       
        for(int i=1;i<=k;i++){ //a row
            
            for(int j=0;j<=i;j++){ //within the same row;
                
                if(j==0||j==i){
                    temp[j]=1;
                }
                else{
                    temp[j]=ans[j-1]+ans[j];
                }
            }
            ans=temp;
        }
        return ans;
    }
};
int main() {

    Solution s;

    int k;
    cin>>k;

    vector<int> row = s.getRow(k);

    for(int i: row)
        cout<<i<<" ";
    
    cout<<endl;
    return 0;
}