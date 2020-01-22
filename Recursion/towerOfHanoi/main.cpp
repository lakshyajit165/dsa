#include <iostream>
using namespace std;
void towerOfHanoi(int n, string from_rod, string to_rod, string aux_rod){

    if(n == 1){
        cout<<"Move disk 1 from rod "<<from_rod<<" to rod "<<to_rod<<endl;
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    cout<<"Move disk "<<n<<" from "<<from_rod<<" to "<<to_rod<<endl;
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
int main() {

    int n = 4;
    towerOfHanoi(4, "A", "C", "B");
    return 0;
}