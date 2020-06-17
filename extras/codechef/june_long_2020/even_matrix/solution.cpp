/*
Chef has an integer N and he wants to generate a
 matrix M with N rows (numbered 1 through N) and N columns (numbered 1 through N). 
He thinks that M would be delicious if:

Each element of this matrix is an integer between 1 and N2 inclusive.
All the elements of the matrix are pairwise distinct.
For each square submatrix containing cells in rows r through r+a and in columns c through c+a (inclusive) for some valid integers r, c and a≥0:
Mr,c+Mr+a,c+a is even
Mr,c+a+Mr+a,c is even
Can you help Chef generate a delicious matrix? It can be proved that a solution always exists. 
If there are multiple solutions, you may find any one.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.
Output
For each test case, print N lines describing a delicious matrix M. For each valid i, the i-th of these lines should contain N space-separated integers Mi,1,Mi,2,…,Mi,N.

Constraints
1≤T≤10
1≤N≤103
the sum of N over all test cases does not exceed 103
Subtasks
Subtask #1 (100 points): original constraints

Example Input
1
2
Example Output
1 2
4 3
Explanation
Example case 1: The matrix M has five square submatrices. 
Four of them ([1], [2], [4], [3]) have a=0, so they obviously satisfy all conditions. 
The last square submatrix is the whole matrix M, with r=c=a=1, and we can see that M1,1+M2,2=1+3=4 and M1,2+M2,1=2+4=6 are both even.



-----------------------------------MY LOGIC -----------------------------------
Generate an NxN spiral matrix consisting of numbers from 1 to N2(squared)



---------------------------------Editorial's LOGIC--------------------------
Fill the matrix MM in a checkerboard pattern where all black cell
s have an odd integer and white cells have an even integer (or vice versa). 
See Setter’s code for implementation. Since we just iterate over all the integers and place them, complexity is simply O(N^2)O(N 
2
 ).

*/

#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000; 
void spiralFill(int M[][MAX], int m, int n) 
{ 
    // Initialize value to be filled in matrix 
    int val = 1; 
  
    /*  k - starting row index 
        m - ending row index 
        l - starting column index 
        n - ending column index */
    int k = 0, l = 0; 
    while (k < m && l < n) 
    { 
        /* Print the first row from the remaining 
          rows */
        for (int i = l; i < n; ++i) 
            M[k][i] = val++; 
  
        k++; 
  
        /* Print the last column from the remaining 
          columns */
        for (int i = k; i < m; ++i) 
            M[i][n-1] = val++; 
        n--; 
  
        /* Print the last row from the remaining 
           rows */
        if (k < m) 
        { 
            for (int i = n-1; i >= l; --i) 
                M[m-1][i] = val++; 
            m--; 
        } 
  
        /* Print the first column from the remaining 
           columns */
        if (l < n) 
        { 
            for (int i = m-1; i >= k; --i) 
                 M[i][l] = val++; 
            l++; 
        } 
    } 
} 
int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);

  int M[MAX][MAX]; 
  int t, n;
  cin>>t;
  while(t--){
    cin>>n;
    spiralFill(M, n, n);

    for (int i=0; i<n; i++) 
      { 
        for (int j=0; j<n; j++) 
            cout << M[i][j] << " "; 
        cout << endl; 
      } 
    
  }
  
	
	return 0;
}


/*

Editorial COde:

#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll a[1005][1005];
int main()
{
    
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        
        ll j = 1;
        
        for(ll i=0;i<n;i++)
        {
            if (i%2==0)
            for(ll k=0;k<n;k++)
                a[i][k]=j++;
            else
            {
                j+=n-1;
                for(ll k=0;k<n;k++)
                a[i][k]=j--;
                j=a[i][0]+1;
            }
        
        }
 
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
                cout<<a[i][j]<<" ";
            cout<<"\n";
        }
    }
}   

*/