// To find whether a given number is a power of 2
/*
 n & n-1 gives 0 if n is a power of 2 as, subtracting 1 reverses the bits of a number which is power of 2
 */

#include <iostream>
using namespace std;
int main() {

    int n;
    cin>>n;
    if((n & n-1) == 0 && n != 0)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}