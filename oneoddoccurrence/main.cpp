/*
 Given an array of n numbers where each number appears even number of times except one. Find the number
 which appears odd number of times
 */

#include <iostream>
using namespace std;
int findOdd(int a[], int n);
int main() {

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<findOdd(arr, n);
    return 0;
}
int findOdd(int a[], int n){
     int res = 0;
     for(int i = 0; i<n; i++){
         res = res ^ a[i];
     }
     return res;
}