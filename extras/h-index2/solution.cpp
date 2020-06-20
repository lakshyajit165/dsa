#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
//         
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = citations.size();
        int low = 0, high = n-1;
        int mid;
        
        while(low <= high){
            mid = low + (high - low) / 2;
            if(citations[mid] == n-mid){
                return citations[mid];
            }else if(citations[mid] > n-mid){
                high = mid - 1;
            }else{
                low = mid + 1;
            }    
        }
        
        return n-low;
    }
};
int main() {

    Solution s;
    vector<int> citations;
    int ele;

    while ((cin.peek() != '\n') && (cin.peek() != EOF)) {
        cin >> ele;
        citations.push_back(ele);
    // do something with ele
    }

    cout<<s.hIndex(citations)<<endl;

    return 0;
}