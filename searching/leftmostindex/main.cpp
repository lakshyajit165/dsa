/*
 * Given a sorted array with repititions, find the left most index of an element
 *
 *
 *
 * */


#include <bits/stdc++.h>
using namespace std;
int leftMostOccurrence(int arr[], int l, int h, int x){

    if(l > h)
        return -1;
    int mid = l + (h-l)/2;
    if(arr[mid] == x && (mid == 0 || arr[mid-1] != x))
        return mid;
    else if(arr[mid] >= x)
        return leftMostOccurrence(arr, l, mid-1, x);
    else
        return leftMostOccurrence(arr, mid+1, h, x);
}
int main() {

    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i<n; i++)
        cin>>arr[i];

    int x;
    cin>>x;
    cout<<leftMostOccurrence(arr, 0, n-1, x);
    return 0;
}