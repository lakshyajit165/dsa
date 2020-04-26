/*

Vinit & Vaibhaw are siblings. These days, they're at home due to the lockdown.
 One day Vinit's brother Vaibhaw got angry with him for waking him in the morning, 
 so he gave a tough task to Vinit to take the revenge.

The task is "Given a number, find the most occurring digit in it.
 If two or more digits occur same number of times, then return the highest of them.
  Input integer is given as a string".

Vinit needs your help to complete this task as it is difficult for him to solve alone.

Input Format

The first line of input contains an integer T denoting the number of test cases.
 Then T test cases follow. The first line of each test case contains the number N

Constraints

1<= T <=100
1<= N <=101000

Output Format

Print the most occurring digit in the number. 
If two or more digits occur same number of times, then print the highest of them. 
Print the answer for each test case in a new line.

Sample Input 0

1
12234
Sample Output 0

2
Explanation 0

2 occurs maximum number of times in 12234



*/

/*

SAMPLE INPUT & OUTPUT

5
1001
1
12334
3
56678
6
12345
5
1000
0

*/
#include<bits/stdc++.h>
using namespace std;
int countDigits(string s, char d){
    
    int count = 0;
    for(char ch : s){
        if(ch == d)
            count++;
    }
    return count;
}
char maxFrequency(string s){
    
    int count = 0, max_count = 0;
    char res;
    for(char d = '0'; d<='9'; d++){
        count = countDigits(s, d);
        if(count >= max_count){
            max_count = count;
            res = d;
        }    
    }
    return res;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    
    while(t--){
        string s;
        cin>>s;
        
        if(s[0] == '0' and s.size() == 1){
            cout<<'0'<<endl;
        }else{
            sort(s.begin(), s.end());
            // cout<<s<<endl;
        

            cout<<maxFrequency(s)<<endl;
        }
        
    }
    return 0;
   
}
