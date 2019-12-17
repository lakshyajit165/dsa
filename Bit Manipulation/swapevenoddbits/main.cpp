/*
 Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43(00101011). Here, every even position bit is swapped with adjacent bit on right side(even position bits are highlighted in binary representation of 23), and every odd position bit is swapped with adjacent on left side.

Input:
The first line of input contains T, denoting the number of testcases. Each testcase contains single line.

Output:
For each testcase in new line, print the converted number.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:
Input:
2
23
2

Output:
43
1

Explanation:
Testcase 1: BInary representation of the given number; 00010111 after swapping 00101011.

 */


#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        unsigned int n;
        cin >> n;

        unsigned int even = n & 0xAAAAAAAA;//get even position bits
        unsigned int odd = n & 0x55555555;//get odd position bits

        even >>= 1;//shifting to odd pos
        odd <<= 1;//shifting to even pos

        cout << (even | odd) << endl;
    }
        return 0;
}