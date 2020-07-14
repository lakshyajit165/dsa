/*

Having already mastered cooking, 
Chef has now decided to learn how to play the guitar.
 Often while trying to play a song,
  Chef has to skip several strings to reach the string he has to pluck. 
  Eg. he may have to pluck the 1st string and then the 6th string.
   This is easy in guitars with only 6 strings; However,
    Chef is playing a guitar with 106 strings. 
In order to simplify his task, Chef wants you to write a program that will tell him the total number of strings he has to skip while playing his favourite song.



This is how guitar strings are numbered (In ascending order from right to left). Eg. to switch from string 1 to 6, Chef would have to skip 4 strings (2,3,4,5).

Input:
First line will contain T, number of testcases. Then the testcases follow.
The first line of each test case contains N, the number of times Chef has to pluck a string
The second line of each test case contains N space separated integers - S1, S2, …, SN, where Si is the number of the ith string Chef has to pluck.
Output:
For each testcase, output the total number of strings Chef has to skip over while playing his favourite song.

Constraints
1≤T≤10
2≤N≤105
1≤Si≤106
For each valid i, Si≠Si+1
Subtasks
30 points : for each valid i, Si<Si+1
70 points : No additional constraints
Sample Input:
2
6
1 6 11 6 10 11
4
1 3 5 7
Sample Output:
15
3
Explanation:
Test Case 1

Chef skips 4 strings (2,3,4,5) to move from 1 to 6
Chef skips 4 strings (7,8,9,10) to move from 6 to 11
Chef skips 4 strings (10,9,8,7) to move from 11 to 6
Chef skips 3 strings (7,8,9) to move from 6 to 10
Chef skips 0 strings to move from 10 to 11
Therefore, the answer is 4+4+4+3+0=15

Test Case 2

Chef skips 1 string to move from 1 to 3
Chef skips 1 string to move from 3 to 5
Chef skips 1 string to move from 5 to 7
Therefore, the answer is 1+1+1=3


*/

#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--) {
        ll n, ele, res = 0;
        vector<ll> strings;
        cin>>n;
        
        for(int i = 0; i<n; i++){
            
            cin>>ele;
            strings.push_back(ele);

            if(i != 0)
              res += (abs(strings[i] - strings[i-1]) - 1);
        }
        cout<<res<<endl;
    }
}