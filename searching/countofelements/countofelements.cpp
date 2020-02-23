/*


Given an array arr[] of N positive integers, where elements are consecutive (sorted). Also, there is a single element which is repeating X (any variable) number of times. Now, the task is to find the element which is repeated and number of times it is repeated.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array N. Next line contains the array elements.

Output:
For each testcase, there will be a single line containing the element which is repeated and the number of times it is repeated, seperated by space.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= arr[i] <= 1015

Input:
2
5
1 2 3 3 4
5
2 3 4 5 5

Output:
3 2
5 2

Example:
Testcase 1: In the given array, 3 is occuring two times.So the output is 3 2.
Testcase 2: In the given array, 5 is occuring two times.So the output is 5 2.



*/


#include <iostream>
using namespace std;

int main() {
	//code
	long long t, n, res, count;
	cin>>t;
	while(t--){
	    cin>>n;
	    res = 0;
	    count = 1;
	    long long arr[n];
	    for(int i = 0; i<n; i++){
	        cin>>arr[i];
	        if(i > 0){
	            if(arr[i] == arr[i-1]){
	                res = arr[i];
	                count++;
	            }
	        }
	    }
	    cout<<res<<" "<<count<<endl;
	    
	}
	return 0;
}