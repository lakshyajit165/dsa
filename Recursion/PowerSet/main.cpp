/*
 * You are given a string s. You need to print the lexicographically sorted power-set of the string.
Note: The string s contains lowercase letter of alphabet.

Input Format:
The first line of input contains T, denoting the number of testcases. T testcases follow. Each testcases contains one line of input containing string s.

Output Format:
For each testcase, in a new line, print the lexicographically sorted sub-sets of the powerset of s. Each subset is separated by a space. Each subset starts with empty string represented by " "(space).

Your Task:
This is a function problem. You only need to complete the function powerSet that takes string s as parameter and returns a vector/ArrayList of subsets. The lexicographic-sorting and printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= |s| <= 10

Examples:
Input:
2
a
abc
Output:
 a
 a ab abc ac b bc c

Explanation:
Testcase1: space and a are only sets.
Testcase2: space,  a, ab, abc, ac, b, bc, c are the sets.
 *
 *
 *
 *
 *
 * */


#include<bits/stdc++.h>
using namespace std;
void powerSetUtil(string &s, vector<string> &v, int index = 0, string curr = ""){

    int n = s.length();

    // base case
    if(index == n){
        v.push_back(curr);
        return;
    }

    powerSetUtil(s, v, index+1, curr);
    powerSetUtil(s, v, index+1, curr+s[index]);
}
vector<string> powerSet(string s){
    vector<string> ans;
    powerSetUtil(s, ans);
    return ans;

}
int main() {

    vector<string> ans = powerSet("ABC");
    sort(ans.begin(), ans.end());
    for(int i = 0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    return 0;
}