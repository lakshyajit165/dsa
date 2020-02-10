/*
 * You are given a list of n-1 integers and these integers are in the range of 1 to n.
 * There are no duplicates in the list. One of the integers is missing in the list.
 * Write an efficient code to find the missing integer.
 *
 * Logic: xor all elements of the array (x1)
 * xor all numbers from 1 to n (x2)
 *
 * missing element = x1 ^ x2
 *
 * */

#include <iostream>
using namespace std;
int main() {

    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i<n; i++)
        cin>>arr[i];

    int x1 = arr[0];
    for(int i = 1; i<n; i++)
        x1 = x1 ^ arr[i];

    int x2 = 1;
    for(int i = 2; i<=n+1; i++)
        x2 = x2 ^ i;

    int missing = x1 ^ x2;
    cout<<missing;
    return 0;
}