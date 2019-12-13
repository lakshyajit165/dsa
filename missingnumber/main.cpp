// A variation of odd times appearing number in an array

/*
 Given an array of n numbers that has values in the range [1...n+1]. Every no. appears exactly once,
 and hence one no. is missing. Find the missing no.
 */

#include <iostream>
using namespace std;
int findMissing(int a[], int n);
int main() {

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<findMissing(arr, n);

    return 0;
}
int findMissing(int a[], int n){

    int res1 = 0, res2 = 0;
    for(int i = 0; i<n; i++){
        res1 = res1 ^ a[i];
    }

    for(int i = 1; i<=n+1; i++){
        res2 = res2 ^ i;
    }

    return res1 ^ res2;
}