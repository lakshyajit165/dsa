/*

Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.



*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool mycompare(string &a, string &b) {
        
       return a+b > b+a;

        
    }
    string largestNumber(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<string> temp;
        string res = "";
        int flag = 0;
        
        for(int x:nums){
            if(x) flag = 1;
            temp.push_back(to_string(x));
        }
        
        if(flag == 0) return "0";
        
        sort(temp.begin(), temp.end(), mycompare);
        
        for(string s:temp) res += s;
        
        return res;
        
    }
};
int main() {

  vector<int> s;

  int n;
  cin>>n;

  for(int i = 0; i<n; i++){
    int ele;
    cin>>ele;
    s.push_back(ele);
  }

  Solution sn;
  cout<<sn.largestNumber(s)<<endl;
  return 0;
}
