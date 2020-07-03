// Increasing Decreasing

/*

Chef received a new sequence A1,A2,…,AN. He does not like arbitrarily ordered sequences,
 so he wants to permute the elements of A in such a way that it would satisfy the following condition:
  there is an integer p (1≤p≤N) such that the first p elements of the new (permuted) 
  sequence are strictly increasing and the last N−p+1 elements are strictly decreasing.

Help Chef and find a permutation of the given sequence which satisfies this
 condition or determine that no such permutation exists. If there are multiple solutions, you may find any one.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
Output
For each test case:

If there is no permutation of A that satisfies the given condition, print a single line containing the string "NO" (without quotes).
Otherwise, print two lines.
The first of these lines should contain the string "YES" (without quotes).
The second line should contain N space-separated integers ― the elements of your permuted sequence.
Constraints
1≤T≤100
1≤N≤105
1≤Ai≤2⋅105 for each valid i
the sum of N over all test cases does not exceed 106
Subtasks
Subtask #1 (50 points):

N≤103
Ai≤2⋅103 for each valid i
the sum of N over all test cases does not exceed 104
Subtask #2 (50 points): original constraints

Example Input
5
4
1 3 2 4
4
1 3 2 4
6
1 10 10 10 20 15
5
1 1 2 2 3
4
1 2 3 3
Example Output
YES
1 2 3 4
YES
4 3 2 1
NO
YES
1 2 3 2 1
NO

*/



// ----------------------------- LOGIC ---------------------------------------------

// Initialize two vectors v1 and v2 which stores increasing and decreasing numbers.
// Use hashing to know the occurrence of the number in the array.
// If the number appears to come for the first time, then store it in v1.
// If the number appears to come for the second time, then store it in v2.
// If the number appears for more than 2 times, then it is not possible to store to create a strictly increasing and strictly decreasing array.
// At last, sort the first vector in increasing order and the second vector in decreasing order and print them.


#include<bits/stdc++.h>
using namespace std;
int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, n;
  cin>>t;

  while(t--) {
    cin>>n;

    int ele;
    vector<int> a;
    int flag = 0;

    for(int i = 0; i<n; i++){
      cin>>ele;
      a.push_back(ele);
    }

    // Store both arrays 
    vector<int> v1, v2; 
  
    // Used for hashing 
    unordered_map<int, int> mymap; 
  
    // Iterate for every element 
    for (int i = 0; i < n; i++) { 
  
        // Increase the count 
        mymap[a[i]]++; 
  
        // If first occurrence 
        if (mymap[a[i]] == 1) 
            v1.push_back(a[i]); 
  
        // If second occurrence 
        else if (mymap[a[i]] == 2) 
            v2.push_back(a[i]); 
  
        // If occurs more than 2 times 
        else { 
            cout << "NO"; 
            flag = 1;
            break;
        } 
    } 

     if(!flag){

     
       // Sort in increasing order 
      sort(v1.begin(), v1.end()); 

      // Sort in reverse order 
      sort(v2.begin(), v2.end(), greater<int>()); 

      // to prevent repeating elements from getting printed
    
      if(v2.size() >= 1 and v2[0] == v1[v1.size() - 1])
        cout<<"NO"<<endl;

      else{
         cout<<"YES"<<endl;
         // print the first array
      for (auto it : v1) 
          cout << it << " "; 
    
      // Print the decreasing array 
      for (auto it : v2) 
          cout << it << " ";
      }
      
      
    }
    cout<<endl;
   
  
   
  }
}