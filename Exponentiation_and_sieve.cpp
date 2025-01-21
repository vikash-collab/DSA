#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

vector<bool> Sieve(int n){  
    vector<bool>sieve(n+1, true);
    sieve[0] = sieve[1] = false; 

    for(int i=2; i * i <= n; i++){ // Optimization 2
        if(sieve[i]==true){
          //  int j = i * 2;
            int j = i*i; // Optimization 1
            while(j<=n){
                sieve[j] = false;
                j += i;
            }
        }
    }           
    return sieve; 
}

vector<bool> segmentedSeive(int L, int R){
    vector<bool>sieve = Sieve(sqrt(R));
    vector<int>basePrimes;
    for(int i=0; i<sieve.size(); i++){
        if(sieve[i]){
            basePrimes.push_back(i);
        }
    }

    vector<bool>segSieve(R-L+1, true);
    if(L==1 || L==0){
        segSieve[L] = false;
    }

    for(auto prime: basePrimes){
        int first_mul = (L/prime) * prime;
        if(first_mul < L){
            first_mul += prime;
        }  
        int j = max(first_mul, prime*prime);
        while(j<=R){
            segSieve[j - L] = false;
            j += prime;
        }
    }  
    return segSieve;
}



int main(){

    // vector<bool>sieve = Sieve(25);

    // for(int i = 2; i<=25; i++){
    //     if(sieve[i]==true){
    //        cout<<i<<" ";
    //     }
    // }

    int L = 110;
    int R =  130;
    vector<bool>sS = segmentedSeive(L, R);

    for(int i=0; i<sS.size(); i++){
        if(sS[i]){
            cout<<i+L<<" ";
        }
    }

    return 0;
}




























//////////////  exponentiation

// int fastExponentiation(int a, int b){

//     int  ans = 1;
//     while(b>0){
//         if(b & 1){
//         ans = ans * a;
//         }
//        a = a * a;

//       b>>= 1;
//     }
//   return ans;
// }

// int slowExponentiation(int a, int b)
// {
//   int ans = 1;
//     for(int i=0; i<b; i++){
//        ans = ans * a;
//     }
//   return ans;
// }// O(b)

// int main(){
//   cout<<slowExponentiation(5,4)<<endl;
//   cout<<fastExponentiation(2,11)<<endl;
//   return 0;
// }