#include <iostream>
using namespace std;
void powerSet(string s, string curr = "", int index = 0){

    if(index == s.length()) {
        cout << curr << " ";
        return;
    }

    powerSet(s, curr, index+1);
    powerSet(s, curr+s[index], index+1);

}
int main() {

    powerSet("ABC");
    return 0;
}