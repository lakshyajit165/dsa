#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {

  ll t, k, d0, d1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  while(t--){
    cin>>k>>d0>>d1;

    ll lastDigit = (d0+d1) % 10;
    ll sum = d0 + d1 + lastDigit;

    if(k == 2){
      if((d0 + d1) % 3 == 0)
        cout<<"YES"<<endl;
      else
        cout<<"NO"<<endl;

      // go to the next test case directly(IMP)
      continue;
    }

    ll remDigits = k-3;
    
    while(remDigits > 0){
      if(lastDigit == 6){

        ll sets = remDigits/4;
        sum += sets*20;
        remDigits -= sets*4;

        // for left over digits
        if(remDigits == 1){  // means pattern is like ...248624862
          sum += 2;
         
        }else if(remDigits == 2){ // means pattern is like ...2486248624
          sum += 6;
          
        }else if(remDigits == 3){ // means pattern is like ...24862486248
          sum += 14;
          
        }
          break;
      }else if(lastDigit == 0){
         remDigits = 0;
         break;
      }else{
        // since after the 3rd digit, each digit is the double of its previous acc. to pattern
        lastDigit = (lastDigit * 2) % 10;
        sum += lastDigit;
        remDigits--;
      }
    }
    if(sum % 3 == 0)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}