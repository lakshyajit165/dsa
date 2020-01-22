/*
 You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. The first line of each test case is A and B separated by a space.

Output:
For each testcase, in a new line, print the number of bits needed to be flipped.

User Task:
The task is to complete the function countBitsFlip() that takes A and B as parameters and returns the count of the number of bits to be flipped to convert A to B.

Constraints:
1 ≤ T ≤ 100
1 ≤ A, B ≤ 103

Example:
Input:
2
10 20
20 25
Output:
4
3

Explanation:
Testcase1:
A  = 01010
B  = 10100
Number of bits need to flipped = set bit count in A XOR B value i.e. 4
 */


#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
// Driver Code
int countBitsFlip(int, int);
int main()
{
    int t;
    cin>>t;// input the testcases
    while(t--) //while testcases exist
    {
        int a,b;
        cin>>a>>b; //input a and b
        cout<<countBitsFlip(a, b)<<endl;
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
// Function to find number of bits to be flip
// to convert A to B
int countBitsFlip(int a, int b){

    // Your logic here
    int exor = a^b;
    int res = 0;
    while(exor > 0){
        exor = (exor & (exor - 1));
        res++;
    }
    return res;

}