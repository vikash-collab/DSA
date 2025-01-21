#include<iostream>
#include<queue> 
#include<deque> // for Double ended queue(deque)
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
       arr = new int(5);
       this->size = size;
       front = -1;
       rear = -1;
    }

    void push(int data){
        // check is full
        if(rear == size-1){
            cout<<"Queue is Overflow."<<endl;
            return;
        }
        else{
            if(front==-1 && rear==-1){
                // empty case->single Element
                front++; rear++;
            }
            else{
                //normal case
                rear++;
            }
            arr[rear] = data;
        }
    }

    void pop(){
        //Underflow
        if(front == -1 && rear == -1){
            cout<<"Queue is Underflow."<<endl;
            return;
        }
        else{
            if(front == rear){   //empty case:- single element
                arr[front] = -1; front = -1;  
                rear = -1;
            }
            else{
                // normal case
                arr[front] = -1;
                front++;
            }
        }
    }

    bool empty(){
        if(front == -1 && rear==-1){
            return true;
        }
        else{
           return false;
        }
    }
    
    int getSize(){
        // BHul jata hu
        if(front==-1 && rear==-1){
            return 0;
        }
        else
        return (rear-front+1);
    }

    int getfront(){
        if(front==-1){
            cout<<"No Element in Queue, cannot give front Element."<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int getRear(){
        if(rear==-1){
            cout<<"NO Element in Queue, cannot give rear Element."<<endl;
            return -1;
        }
        else{
           return arr[rear];
        }
    }

// print func hota nhi vase 
    void print(){
        cout<<"Printing Queue: "<<endl;
        for(int i=0; i<size; ++i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    } 
};

class Cqueue{   // circular queue
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Cqueue(int size){
        arr = new int(size);
        this->size = size;
        front = -1;
        rear = -1; 
    }

    void push(int val){
        //overflow
        //empty case:- first element
        // circular nature
        // normal flow
        if((front==0 && rear == size-1) || (rear == front-1)){
            cout<<"Overflow"<<endl;
            return;
        }
        else if(front == -1 && rear == -1){  
            front++; rear++;
            arr[rear] = val;
        }
        else if(rear==size-1 && front!=0){
            rear = 0;
            arr[rear] = val; 
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }

    void pop(){
        //Underflow
        //single element
        //circular nature
        //normal flow
        if(front==-1 && rear==-1){
            cout<<"Underflow"<<endl;
        } 
        else if(front==rear){
            arr[front] = -1;
            front = rear = -1;
        }
        else if(front==size-1){
            arr[front] = -1;
            front = 0;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    
    void print(){
        cout<<"Elements are: "<<endl;
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" "; 
        }
        cout<<endl;
    }


};


class Deque{  // Doubly ended queue
    public:
    int *arr;
    int size;
    int front;
    int rear;
    Deque(int size){
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushBack(int val){
        //overflow
        //empty case:- first element
        // circular nature
        // normal flow
        if((front==0 && rear == size-1) || (rear == front-1)){
            cout<<"Overflow"<<endl;
            return;
        }
        else if(front == -1 && rear == -1){  
            front++; rear++;
            arr[rear] = val;
        }
        else if(rear==size-1 && front!=0){
            rear = 0;
            arr[rear] = val; 
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }
    
    void pushFront(int val){
        if((front==0 && rear == size-1) || (rear == front-1)){
            cout<<"Overflow"<<endl;
            return;
        }
        else if(front==-1 && rear==-1){
            front++; 
            rear++;
            arr[front] = val;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;
            arr[front];
        }
        else{
            front--;
            arr[front];
        }
    }


    void popFront(){
        //Underflow
        //single element
        //circular nature
        //normal flow
        if(front==-1 && rear==-1){
            cout<<"Underflow"<<endl;
        } 
        else if(front==rear){
            arr[front] = -1;
            front = rear = -1;
        }
        else if(front==size-1){
            arr[front] = -1;
            front = 0;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }

    void popBack(){
        if(rear==-1 && front==-1){
            cout<<"Underflow"<<endl;
        }
        else if(rear==front){
            arr[rear] = -1;
            rear = -1;
            front = -1;
        }
        else if(rear==0){
            arr[rear] = -1;
            rear = size-1;
        }
        else{
            arr[rear] = -1;
            rear--;
        }
    }

}


int main(){
    Deque dq(5);





    // deque<int>dq;
    // dq.push_back(10);
    // dq.push_front(20);
    // // dq.pop_back();
    // dq.pop_front();

    // cout<<dq.front()<<endl;
    // cout<<dq.back()<<endl;




    // Cqueue q(5);
    // q.print();

    // q.push(10);
    // q.print();

    // q.push(20);
    // q.print();

    // q.push(30);
    // q.print();

    // q.push(40);
    // q.print();

    // q.push(50);
    // q.print();

    // q.pop();
    // q.print();

    // q.pop();
    // q.print();

    // q.push(70);
    // q.print();

    // q.push(90);
    // q.print();



    // Queue q(5);
    // q.print();

    // q.push(10);
    // q.print();

    // q.push(20);
    // q.print();

    // q.push(30);
    // q.print();

    // q.push(40);
    // q.print();
    
    // q.push(50);
    // q.print();

    // cout<<"Size of Queue: "<<q.getSize()<<endl;

    // q.pop();
    // q.print();

    // q.pop();
    // q.print();

    // cout<<"Size of Queue: "<<q.getSize()<<endl;
    // cout<<"Queue is Empty Or not: "<<q.empty()<<endl;
    // cout<<"rear element is: "<<q.getRear()<<endl;

    // q.push(90);  // rear is full, where we push the element
    // q.print();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.print();
    // q.pop();
    // cout<<q.getfront()<<endl;
    // q.pop(); q.print();
    // cout<<"Size of Queue: "<< q.getSize()<<endl; 




    // // creation
    // queue<int>q;

    // //insertion
    // q.push(11);

    // //size
    // cout<<"Size of Queue: "<<q.size()<<endl;

    // //empty
    // if(q.empty()){
    //     cout<<"Queue is Empty."<<endl;
    // }
    // else{
    //     cout<<"Queue is Non-Empty."<<endl;
    // }

    // // remove
    // q.pop();

    // //size
    // cout<<"Size of Queue: "<<q.size()<<endl;

    // q.push(5);
    // q.push(10);
    // q.push(15);
    // cout<<"Front Element of Queue is: "<<q.front()<<endl;  // front element
    // cout<<"Last Element of Queue is: "<<q.back()<<endl;  // rear element

    return 0;
}