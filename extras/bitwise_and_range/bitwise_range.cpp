#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
   
    int rangeBitwiseAnd(int m, int n) {
        
        int count = 0;
        while(m != n){
            
            // right shit until common set of bits are found
            m = m >> 1;
            n = n >> 1;
            
            count++;
        }
        
        // left shift count times
        return m<<=count;
    }
};

int main() {

    int m,n;
    cin>>m>>n;

    Solution s;
    cout<<s.rangeBitwiseAnd(m,n)<<endl;
    return 0;
}