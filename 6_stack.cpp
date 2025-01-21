#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(int *arr, int size){
    vector<int>ans(size);
    stack<int>st;
    st.push(-1);  

    for(int i=size-1; i>=0; i--){
        int curr = arr[i];
        // ans find karo curr ke liye
        while(st.top()>=curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

vector<int> prevSmallerElement(int *arr, int size){
    vector<int>ans(size);
    stack<int>st;
    st.push(-1);

    for(int i=0; i<size; i++){
        int curr = arr[i];
        while(st.top()>= curr){
            st.pop();
        }
        ans[i] = st.top();

        st.push(curr);      
    }
    return ans;
}



int main(){

    int arr[5] = {1, 4, 6, 2, 3};
    int size = 5;

    vector<int>next(size);

    cout<<"next Smaller Elements"<<endl;
    next  = nextSmallerElement(arr, size);
    for(auto at: next){
        cout<<at<<" ";
    }cout<<endl;

    vector<int>prev(size);

    cout<<"Prev Smaller Elements: "<<endl;
    prev = prevSmallerElement(arr, size);
    for(auto at: prev){
        cout<<at<<" ";
    }cout<<endl;

    return 0;
}



