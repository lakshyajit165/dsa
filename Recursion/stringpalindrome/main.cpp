#include <iostream>
using namespace std;
bool isPalin(string s, int start, int end){

    if(start == end || start > end)
        return true;
    if(s[start] != s[end])
        return false;
    return isPalin(s, start + 1, end - 1);
}
int main() {

    string s = "racecar";
    cout<<isPalin(s, 0, s.length()-1);
    return 0;
}