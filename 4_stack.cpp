#include<iostream>
#include<stack>       
using namespace std;


// stack implementation
class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data){
        if(top == size-1){
           cout<<"Stack is Overflow"<<endl;
           return;
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    void pop(){
        if(top==-1){
            cout<<"Stack is Underflow"<<endl;
            return;
        }
        else{
            top--;
        }
    }
    
    bool isempty(){
        if(top==-1)
            return true; // cout<<"Stack is Empty! "<<endl;
        else
           return false; // cout<<"Stack is Non-Empty! "<<endl;

    }

    int getTop(){ 
        if(!(top==-1))
          return arr[top];
        else
          cout<< "Stack is Empty"<<endl;
            
    }

    int getSize(){
        return top+1;
    }

// print funcn is not in original stack
    void Print(){
        cout<<"Stack: ";
        for(int i=0; i<getSize(); i++){
            cout<<arr[i]<<" ";
        } cout<<endl;
    }

};

// Middle Element Access and deletion
void solve(stack<int>&st, int &pos, int &ans){
    // base case
    if(pos==1){
        ans = st.top();      // access middle element
        cout<<"Deletion: "<< st.top()<<endl;     // deleletion of middle element
        st.pop();
        return;
    }
    
    // 1-case solve
    pos--;
    int temp = st.top();
    st.pop();

    // recusive call
    solve(st, pos, ans);

    // backtrack
    st.push(temp);
}

int getMiddleElement(stack<int>&st){
    int size = st.size();
    if(st.empty()){
        return -1;
    }
    else{

        if(size&1){
            size = size/2 + 1;
        }
        else{
            size = size/2;
        }
        int ans = -1;
        solve(st, size, ans);
        return ans;
    }
}

// insert Element at Bottom
void insertAtBottom(stack<int>&st, int element){
    // Base Case
    if(st.empty()){
        st.push(element);
        return;
    } 

    //1 case Solve
    int temp = st.top();
    st.pop();

    // recursife solution
    insertAtBottom(st, element);
    
    // backtrack
    st.push(temp);
}

// reverse of stack 
void reverseStack(stack<int>&st){
    //base case
    if(st.empty()){
        return;
    }

    // 1 case sol
    int temp = st.top();
    st.pop();

    // recursive
    reverseStack(st);

    //backtrack
    insertAtBottom(st, temp);
}


// insert at Sorted order 
void insertSorted(stack<int>&st, int element){
    // base case
    if(st.empty() || element > st.top()){   // yha per katch hai ki jab value stack me sabse chotihai to insert hogi nhi agar empty  case nhi lagate
        st.push(element);
        return;
    }

    // 1 case- Sol
    int temp = st.top();
    st.pop();
    
    // recursive call
    insertSorted(st, element);
    
    // backtrack
    st.push(temp);
}

// sort a Stack
void sortStack(stack<int>&st){
    //base case
    if(st.empty()){
        return;
    }

    // 1 case sol
    int temp = st.top();
    st.pop();

    // recursive call
    sortStack(st);

    // backtrack
    insertSorted(st, temp);
}



int main(){

    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(45);
    st.push(70);
    st.push(80);
    st.push(40);

// sort Stack
    sortStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;     

// inserted sorted
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // st.push(60);
    // st.push(70);
    // st.push(90);
    // insertSorted(st, 25);
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }cout<<endl;   


// reverse of Stack
    // reverseStack(st); 
    // cout<<"After Revese :"<<endl;
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }cout<<endl;


// insertAt Bottom
    // int element = 500;
    // insertAtBottom(st, element);
    //     cout<<"hi-fi:";
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }cout<<endl;


// middle element Access and deletion
    // cout<<"Size Before Deletion: "<<st.size()<<endl;
    // int mid = getMiddleElement(st);
    // cout<< "Middle Element: "<<mid<<endl; 
    // cout<<"Size after deletion: "<<st.size()<<endl;





// reverse ordering
    // string str = "NAMASTE BHARAT";
    // stack<char> st;
    // for(int i=0; i<str.size(); i++){
    //     char ch = str[i];
    //     st.push(ch);
    // }
    // while( !st.empty()){
    //     cout<<st.top();
    //     st.pop();
    // }cout<<endl;
    
    

// stack implementation
    // Stack st(5);
    // st.push(10);
    // st.push(12);
    // st.push(16);
    // st.push(18);
    // st.push(19);
    // st.push(21); // stack is overflow;
    // cout<<"Size of Stack is: "<<st.getSize()<<endl;
    // cout<<"Top Element: "<<st.getTop()<<endl;
    // st.pop();
    // cout<<"Size of Stack is: "<<st.getSize()<<endl;
    // cout<<"Top Elememnt: "<<st.getTop()<<endl;
    // st.Print(); 
    // st.pop();
    // st.pop();
    // st.pop();
    // st.pop();
    // if(st.isempty()){
    //     cout<<"Stack Is Empty."<<endl;
    // }
    // else{
    //     cout<<"Stack is Non Empty."<<endl;
    // }
    // st.pop();   // stack is Underflow
    // st.Print();   


    // stack<int>st;
    // // insert
    // st.push(3);
    // st.push(5);
    // st.push(7);
    // st.push(9);
    // cout<<"Stack Size: "<<st.size()<<endl;


    // // empty check
    // if(st.empty()){
    //     cout<<"Stack is Empty."<<endl;
    // }
    // else{
    //     cout<<"Stack is Non-Empty."<<endl;
    // }

    
    // // Stack Top Element
    // cout<<"Top Element: "<<st.top()<<endl;
    // st.pop();
    // cout<<"Top Element: "<<st.top()<<endl;

    return 0;
}