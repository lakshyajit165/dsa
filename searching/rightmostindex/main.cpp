/*
 *
 * Given a sorted array with repititions, count the occurrences of an element
 *
 * Logic: rightmostindex - leftmostindex + 1
 *
 *
 *
 * */




#include <bits/stdc++.h>
using namespace std;
int leftMostIndex(int arr[], int l, int h, int x);
int rightMostIndex(int arr[], int l, int h, int x, int n);
int main() {

    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i<n; i++)
        cin>>arr[i];

    int x;
    cin>>x;
    if(leftMostIndex(arr, 0, n-1, x) == -1 || rightMostIndex(arr, 0, n-1, x, n) == -1)
        cout<<-1;
    else
        cout<<rightMostIndex(arr, 0, n-1, x, n) - leftMostIndex(arr, 0, n-1, x) + 1;
    return 0;
}
int leftMostIndex(int arr[], int l, int h, int x){

    if(l > h)
        return -1;
    int mid = l + (h-l)/2;

    if(arr[mid] == x && (mid == 0 || arr[mid-1] != x))
        return mid;
    else if(arr[mid] >= x)
        return leftMostIndex(arr, l, mid-1, x);
    else
        return leftMostIndex(arr, mid+1, h, x);
}
int rightMostIndex(int arr[], int l, int h, int x, int n){

    if(l > h)
        return -1;

    int mid = l + (h-l)/2;

    if(arr[mid] == x && (mid == n-1 || arr[mid+1] != x))
        return mid;
    else if(arr[mid] >= x)
        return rightMostIndex(arr, l, mid-1, x, n);
    else
        return rightMostIndex(arr, mid+1, h, x, n);

}