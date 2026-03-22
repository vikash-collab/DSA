# coding 

## Take input when Size is Fixed
#include<bits/stdc++.h>  // eske under c++ ki saare library include hoti h
using namespace std;

int main(){
    int n;
    cin>>n;
    // int arr[n];  // primitive array
    vector<int>arr;  // dynamic array
    
    for(int i=0; i<n; i++){
        // cin>>arr[i];
        int num;
        cin>>num;
        arr.push_back(num);
    }
  
    for(int a: arr){
        cout<<a<<" ";
    } 
    return 0;
}


## Take Input when Size  don't know (not fixed )
### CASE:1 SPACES
#include<bits/stdc++.h>  // eske under c++ ki saare library include hoti h
using namespace std;

int main(){
    
string s;    
getline(cin, s);          // "1 2 3 4 5 6 7 8"     when SPACES

stringstream ss(s);      // '1' '2' '3' '4' '5' '6' '7' '8'

vector<int>arr;
string temp;
while(getline(ss, temp, ' ')){    // ek-ek kar temp me character add ho jayega
    int num = stoi(temp);    // string to int
    arr.push_back(num);
}

for(int a: arr){
    cout<<a<<" ";
}   
    return 0;
}

### CASE:2 COMMAS
#include<bits/stdc++.h>  // eske under c++ ki saare library include hoti h
using namespace std;

int main(){
string s;    
getline(cin, s);          // "1,2,3,4,5,6,7,8"     when COMMAS

stringstream ss(s);      // '1' ',' '2' ',' '3' ',' '4' ',' '5' 

vector<int>arr;
string temp;
while(getline(ss, temp, ',')){    // ek-ek kar temp me character add ho jayega
    int num = stoi(temp);    // string to int
    arr.push_back(num);
}


for(int a: arr){
    cout<<a<<" ";
}
    
    return 0;
}

### CASE3: [ ] OR  { }

#include<bits/stdc++.h>  // eske under c++ ki saare library include hoti h
using namespace std;

int main(){
    
string s;    
getline(cin, s);          // "[1,2,3,4,5,6,7,8]"     when Bracket && Commas

if(s.front()=='[' && s.back()==']'){
    s = s.substr(1, s.length()-2);
}

stringstream ss(s);      // '1' ',' '2' ',' '3' ',' '4' ',' '5' 

vector<int>arr;
string temp;
while(getline(ss, temp, ',')){    // ek-ek kar temp me character add ho jayega
    int num = stoi(temp);    // string to int
    arr.push_back(num);
}


for(int a: arr){
    cout<<a<<" ";
}
    
    return 0;
}



