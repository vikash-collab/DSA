#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>&v){
    int n = v.size();
    for(int i=0; i<n; i++){
        cout<<v[i]<<"  ";
    }   
}

void printv(vector<vector<int>>&v)
{
    for(int i=0; i<v.size(); i++){
        cout<<v[i][0]<<" "<<v[i][1]<<endl;
    }   
}

bool mycomp(int &a, int &b)
{                                                     // user or AAp batoge ki kasi sort karna hai 
    return a>b;                       
}


bool mycomp1(vector<int>&a , vector<int>&b){
    // return (a[1]<b[1]);   // increasing order sorting by by second value
    return (a[0]<b[0]);   // increasing order sorting by by first value

    return (a[1]>b[1]);   // decreasing order sorting by by second value
    return (a[0]>b[0]);   // decreasing order sorting by by first value


}


int main(){
    vector<vector<int>>v;
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    for(int i=0; i<n; i++){
        int a, b;
        cout<<"Enter a, b : "<<endl;
        cin>>a>>b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }
    cout<<" your Element: "<<endl;
    printv(v);
    sort(v.begin(), v.end(), mycomp1);
    cout<<"\n Sorting: "<<endl;
    printv(v);







    // vector<int>v;
    // int n;
    // cin>>n;
    // cout<<"Enter the element: "<<endl;
    // for(int i =0; i<n; i++){
    //     int num;
    //     cin>>num;
    //     v.push_back(num);
    // }
    // cout<<"your Element "<<endl;
    // print(v);
    // sort(v.begin(), v.end(), mycomp);              // here mycomp is the custom comparator
    // cout<<"\n Sorting :"<<endl;
    // print(v);
}










