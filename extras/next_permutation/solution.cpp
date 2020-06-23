/*

The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"



*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        string s = "";
    
        for(int i = 1; i<=n; i++){
             s += to_string(i); 
        }
        
        sort(s.begin(), s.end()); 
        int count = 0;
        
        do { 
           count++;
           if(count == k)
               break;
        } while (next_permutation(s.begin(), s.end())); 
        
        return s;
    }
};
int main() {

    int n, k;
    cin>>n>>k;

    Solution s;
    cout<<s.getPermutation(n, k)<<endl;
    return 0;
}