#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int sum = 0, start = 0, gas_tank = 0;
        
        for(int i = 0; i<gas.size(); i++){
            
            sum += gas[i] - cost[i];
            
            gas_tank += gas[i] - cost[i];
            
            if(gas_tank < 0){
                start = i+1;
                gas_tank = 0;
            }
        }
        return sum < 0 ? -1 : start;
    }
};