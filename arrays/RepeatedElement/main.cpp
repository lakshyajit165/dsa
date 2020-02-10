/*
 * Given an array of distinct integers, only one element appears twice
 * Find the repeated element
 *
 * Logic: xor all array elements, if at any point xor == 0, print the repeated element
 * */


#include <iostream>
using namespace std;
int main() {

    int n;
    cin>>n;
    int arr[n];

    int repeated;

    for(int i = 0; i<n; i++)
        cin>>arr[i];

    int x = arr[0];

    for(int i = 1; i<n; i++){
        if((x ^ arr[i]) == 0) {
            cout << arr[i];
            break;
        }else{
            x = arr[i];
        }
    }
    return 0;
}