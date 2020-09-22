/*

You are given an infix expression S of length N. You need to convert the given expression S to its postfix equivalent using stack.
Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the length of S.
The second line contains a string S, the infix expression.
Output
For each test case print a single line containing the postfix equivalent for the given infix expression.

Constraints
1≤T≤10
1≤N≤102
S contains only uppercase English letters (A...Z), and these characters - (,),+,−,∗,/,^. S is a valid infix expression.
Example Input
2
15
((A+B)*D)^(E-F)
19
A+(B*C-(D/E^F)*G)*H
Example Output
AB+D*EF-^
ABC*DEF^/G*-H*+
Explanation
Example case 1: The postfix equivalent for ((A+B)∗D)^(E−F) is AB+D∗EF−^.

*/

#include<bits/stdc++.h>
using namespace std;
int prec(char ch) {

  if(ch == '^')
    return 3;
  else if(ch == '*' or ch == '/')
    return 2;
  else if(ch == '+' or ch == '-')
    return 1;
  else 
    return -1;
}
string infix_to_postfix(string str) {

  string ns = "";
  stack<char> st;
  st.push('N');

  for(char c: str) {

    if((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'))
      ns+=c;

    else if(c == '(')
      st.push(c);

    else if(c == ')'){
      while(st.top() != '('){
        char ch = st.top();
        st.pop();
        ns += ch;
      }
      if(st.top() == '(')
        st.pop();
    }else{

      while((st.top() != 'N') and (prec(c) <= prec(st.top()))){
        char ch = st.top();
        st.pop();
        ns += ch;
      }
      st.push(c); 
    }
  }
  // pop remaining elements from the stack
  while(st.top() != 'N'){
    char ch = st.top();
    st.pop();
    ns += ch;
  }

  return ns;
}
int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t,n;
  string s;
  cin>>t;

  while(t--){
    cin>>n;
    cin>>s;
    cout<<infix_to_postfix(s)<<endl;
  }
  return 0;
}
