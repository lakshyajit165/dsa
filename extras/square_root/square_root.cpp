/*

Square Root of Integer

Given an integer A.

Compute and return the square root of A.

If A is not a perfect square, return floor(sqrt(A)).

DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY



Input Format

The first and only argument given is the integer A.
Output Format

Return floor(sqrt(A))
Constraints

1 <= A <= 10^9
For Example

Input 1:
    A = 11
Output 1:
    3

Input 2:
    A = 9
Output 2:
    3





*/

#include<bits/stdc++.h>
using namespace std;

int sqrt(int A) {
    
    // Base cases 
    if (A == 0 || A == 1)  
       return A; 
  
    // Do Binary Search for floor(sqrt(x)) 
    int start = 1, end = A, ans;    
    while (start <= end)  
    {         
        int mid = (start + end) / 2; 
  
        // If x is a perfect square 
        if (mid == A/mid) 
            return mid; 
  
        // Since we need floor, we update answer when mid*mid is  
        // smaller than x, and move closer to sqrt(x) 
        
        // Don’t do (mid * mid)>a logic because mid*mid definitely will lead to
        // overflow and TLE because of wraparound so do mid>a/mid . 
        // To make sure mid doesn’t become zero intialise start=1 and end=a.
        if (mid < A/mid)  
        { 
            start = mid + 1; 
            ans = mid; 
        }  
        else // If mid*mid is greater than x 
            end = mid-1;         
    } 
    return ans; 
}

int main() {

    int x;
    cin>>x;
    cout<<sqrt(x)<<endl;
    return 0;
}