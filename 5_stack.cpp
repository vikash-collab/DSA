# include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size){
        this->size = size;
        arr = new int(size);
        top1 = -1;
        top2 = size;        
    }

    void push1(int data){
        if(top2-top1 == 1){
            // no Space is available
            cout<<"OVERFLOW"<<endl;
        }
        else{
            top1++;
            arr[top1] = data;
        }
    }

    void pop1(){
        if(top1 == -1){
            //stack1 is empty
            cout<<"UNDERFLOW"<<endl;
        }
        else{
            arr[top1] = 0;
            top1--;
        }
    }

    void push2(int data){
        if(top2-top1 == 1){
            cout<<"OVERFLOW"<<endl;
        }
        else{
            top2--;
            arr[top2] = data;
        }
    }

    void pop2(){
        if(top2 == size){
            // stack2 is Empty
            cout<<"UNDERFLOW"<<endl;
        }
        else{
            arr[top2] = 0;
            top2++;
        }

    }

    void print(){
        cout<<endl;
        cout<<"top1: "<<top1<<endl;
        cout<<"top2: "<<top2<<endl;
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;

    }
};

bool checkRemoveRedundant(string str){
    stack<char>st;

    for(int i=0; i<str.size(); i++){
        char ch = str[i]; 
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else if(ch==')'){
            int countOperator = 0;
            while(!st.empty() && st.top()!='('){
                if(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){
                    countOperator++;
                }
                st.pop();
            }
            // aap yha per tabhi pahuche ge 
            // jab aap ke stack ka top  per opening bracket ho
            st.pop();

            if(countOperator == 0){
                return true;
            }
        }
    }
    // agar mai yha pahucha
    // iska mtlab har ek braket k pair ke bich me
    // ek operator pkka mila hoga
    return false;
    
}

int main(){

    string  str = "(a *(b)+ c)";

    bool ans = checkRemoveRedundant(str);

    if(ans == true){
        cout<<"Redundant Bracket Present"<<endl;
    } 
    else{
        cout<<"Redundant Bracket Not Present"<<endl;
    }






    // Stack st(5);
    
    // st.print();

    // st.push1(10);
    // st.print();

    // st.push1(20);
    // st.print();

    // st.push2(100);
    // st.print();
    
    // st.push2(200);
    // st.print();

    // st.push1(30);
    // st.print();

    // st.push1(40); // stack is overflow

    // st.pop1();
    // st.print();

    // st.pop1();
    // st.print();

    // st.pop1();  
    // st.print();

    // st.pop1();   // stack1 is underflow
    
    // st.pop2();
    // st.print();

    // st.pop2();
    // st.print();

    // st.pop2();  // stack2 is underflow
    return 0;
}