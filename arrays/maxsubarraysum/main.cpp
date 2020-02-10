#include <bits/stdc++.h>
using namespace std;
int max_sum(int arr[], int n){

    int curr_max = arr[0];
    int max_so_far = arr[0];
    for(int i = 1; i<n; i++){
        curr_max = max(curr_max+arr[i], arr[i]);
        max_so_far = max(max_so_far, curr_max);
    }

    return max_so_far;

}
int main() {

    int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<max_sum(a, n);
    return 0;
}