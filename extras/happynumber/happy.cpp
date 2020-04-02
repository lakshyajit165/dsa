#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        
        set<int> st;
        
         while (n > 1 && st.find(n) == st.end()) {

            st.insert(n);
            n = squareSum(n);

        }

        if (n == 1) return true;

        return false;

        
    }
    
    int squareSum(int n){
        
        int sum = 0;
        while (n) {

            int digit = n % 10;
            n = n / 10;
            sum += digit * digit;
        }

        return sum;
        
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        bool ret = Solution().isHappy(n);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}