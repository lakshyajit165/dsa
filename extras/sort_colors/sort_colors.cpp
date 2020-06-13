#include<bits/stdc++.h>
using namespace std;
class Solution {

    public:
        void sort_colors(vector<int>& arr){

            int l = 0, m = 0, h = arr.size() - 1;
            while(m <= h) {
                if(arr[m] == 0){
                    swap(arr[m], arr[l]);
                    l++;
                    m++;
                }else if(arr[m] == 1){
                    m++;
                }else if(arr[m] == 2){
                    swap(arr[m], arr[h]);
                    h--;
                }
            }
        }
};
int main() {

    Solution s;

    int ele;
    vector<int> arr;
    while ((cin.peek() != '\n') && (cin.peek() != EOF)) {
        cin >> ele;
        arr.push_back(ele);
    }

    s.sort_colors(arr);

    for(int i : arr)
        cout<<i<<" ";

    return 0;
}