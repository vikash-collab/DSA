#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
    stack<int>s;

    // one by one take  front element from queue and push in stack
    while(!q.empty()){
        int frontElement = q.front();
        q.pop();

        s.push(frontElement);
    }

    //one by one take element from stack and push into the queue
    while(!s.empty()){
        int element = s.top();
        s.pop();

        q.push(element);
    }
}

void reverse(queue<int>&q){
    // base case
    if(q.empty()){
        return;
    }

    //1:- case sol
    int temp = q.front();
    q.pop();

    // recursive call
    reverse(q);

    //backtrack
    q.push(temp);
}

void  reversekthPos(queue<int>&q, int k){
    stack<int>s;
    int n = q.size();
    int i=n-k;

    if(k >n || k==0){    
        return;
    }
    
    // push first k element in stack
    while(k>0){
        int temp = q.front();
        q.pop();
        s.push(temp);
        k--;
    }
    
    // push all k element into Queue
    while(!s.empty()){
        int temp = s.top();
        q.push(temp);
        s.pop();
    }

    //pop and push n-k element into queue again
    while(i>0){
        int frontElement = q.front();
        q.pop();
        q.push(frontElement);
        i--;
    }
}

void interLeaveQueue(queue<int>& first){
    queue<int>second;

    //PUSh FIRST half of Queue in SECOND Queue
    int size = first.size();
    for(int i=0; i<size/2; i++){  // implemented on even length
        int temp = first.front();
        first.pop();

        second.push(temp);
    } 

    // Merge both the halves
    // into the original Queue name first
    for(int i=0; i<size/2; i++){
        int temp = second.front();
        second.pop();
        
        first.push(temp);

        temp = first.front();
        first.pop();
        first.push(temp);
    }

}

void printFirstNegative(int *arr, int n, int k){ 
    deque<int> dq;  
    //process first k elements - first window
    for(int index=0; index<k; index++){
       int element = arr[index];
       if(element < 0){
        dq.push_back(index);
       }
    }
    // process remaining windows -> Removal an addition
    for(int index=k; index<n; index++){
       // aage badne se pahle purani window ke answer nikalo 
        if(dq.empty()){
            cout<<"0"<<" ";
        }
        else{
            cout<<arr[dq.front()]<<" ";
        }

        // removal jo bhi index out of range h, usko queue me se remove krdo
        if(index-dq.front() >= k){
            dq.pop_front();
        }

        //Addtion 
        if( arr[index] < 0){
            dq.push_back(index);
        }
    }
    // last window ka answer print kardo
    if(dq.empty()){
        cout<<"0"<<" ";
    }
    else{
            cout<<arr[dq.front()]<<" ";
    }
}

int main(){

    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    int n = 7;
    int k =3;
    printFirstNegative(arr, n, k);
        




    // queue<int>q;
    // q.push(10);
    // q.push(20);
    // q.push(30);
    // q.push(40);
    // q.push(50);
    // q.push(60);


    // interLeaveQueue(q);
   
    // // int k = 3;
    // // reversekthPos(q, k);
    
    // // // reverseQueue(q);
    // // // reverse(q);

    // cout<<"Printing Queue after Reverse: "<<endl;
    // while(!q.empty()){
    //     int element = q.front();
    //     q.pop();
    //     cout<<element<<" ";
    // }cout<<endl;


   return 0;
}