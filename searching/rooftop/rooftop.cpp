#include<bits/stdc++.h>
using namespace std;

int maxStep(int a[], int n){

    int start = 0, end = 0, steps = 0;
    for(int i = 1; i<n; i++){
        if(a[i] > a[i-1])
            end++;
        else{
            steps = max(steps, end-start);
            start = i;
            end = i;
        }
    }

    return max(end-start, steps);
}

int main() {

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int a[n];

        for(int i = 0; i<n; i++)
            cin>>a[i];

        cout<<maxStep(a, n)<<endl;
    }
    return 0;
}