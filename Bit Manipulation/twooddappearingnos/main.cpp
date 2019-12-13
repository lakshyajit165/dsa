/*
 GIven an array of size n, where all numbers appear even no of times, except 2 nos. Find those 2 nos.
 * */

#include <iostream>
using namespace std;
void twoOddAppearingNum(int a[], int n);
int main() {

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    twoOddAppearingNum(arr, n);
    return 0;
}
void twoOddAppearingNum(int a[], int n){

    int res1 = 0, res2 = 0, XOR = 0;
    for(int i = 0; i<n; i++)
        XOR = XOR ^ a[i];

    int sn = XOR & ~(XOR - 1);

    for(int i = 0; i<n; i++){
        if((sn & a[i]) != 0)
            res1 = res1 ^ a[i];
        else
            res2 = res2 ^ a[i];
    }

    cout<<res1<<" "<<res2;


}