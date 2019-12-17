/*
Given a number N. The task is to find the length of the longest consecutive 1s in its binary representation.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N.

Output:
For each test case, in a new line, print the length of the longest consecutive 1's in N's binary representation.

User Task:
The task is to complete the function maxConsecutiveOnes() which returns the length of longest consecutive 1s in the binary representation of given N.

Constraints:
1 <= T < 100
1 <= N <= 103

Example:
Input:
2
14
222

Output:
3
4
 * */


#include <iostream>
using namespace std;
//Position this line where user code will be pasted.
// Driver Code
int maxConsecutiveOnes(int);
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<maxConsecutiveOnes(n)<<endl;
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/*  Function to calculate the largest consecutive ones
*   x: given input to calculate the largest consecutive ones
*/
int maxConsecutiveOnes(int x)
{
    int digit, count = 0, max = 0;
    // Your code here
    while(x != 0){
        digit = x % 2;
        if(digit == 1)
            count++;
        else{
            if(count > max)
                max = count;
            count = 0;
        }
        x /= 2;
    }

    return max > count ? max : count;


}
