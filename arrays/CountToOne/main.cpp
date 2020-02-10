//You are given a number N. You need to convert it to 1 in minimum number of operations.
//
//The operations allowed are as follows:
//
//If N is even then divide the number by 2.
//If N is odd then you can either add 1 to it or subtract 1 from it.
//Using the above operations, find the minimum number of operations require to convert N to 1.
//
//Input:
//The first line of input contains T denoting the number of testcases.
// T testcases follow. Each testcase contains 1 line of input containing N.
//
//Output:
//For each testcase, in a new line, print the minimum number of steps required.
//
//Constraints:
//1 <= T <= 100
//1 <= N <= 107
//
//Examples:
//Input:
//4
//1
//2
//3
//4
//Output:
//0
//1
//2
//2
//
//Explanation:
//Testcase1: 1 can be converted into 1 in 0 steps.
//Testcase2: 2 can be converted into 1 in 1 step: 2-1


#include <bits/stdc++.h>
using namespace std;
int countToOne(int n) {

    if(n == 1)
        return 0;
    else if(n % 2 == 0){
        return 1 + countToOne(n/2);
    }else {
        return 1 + min(countToOne(n-1), countToOne(n+1));
    }

}
int main() {
    //code
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        cout<<countToOne(n)<<endl;
    }
    return 0;
}