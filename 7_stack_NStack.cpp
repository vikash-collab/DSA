#include<iostream>
#include<stack>
using namespace std;

class NStack{
    int *a, *top, *next;
    int n;   // no. of stack
    int size; // size of  main Array
    int freeSpot = 0; // tells free space in memory
    public:
    
    NStack(int _n, int _s): n(_n), size(_s){
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];
        for(int i=0; i<n; i++){
            top[i] = -1;
        }
        for(int i=0; i<size; i++){
            next[i] = i+1;
        }
        next[size-1] = -1;
    }
    
    // push X into, mth Stack
    bool push(int X, int m){
        if(freeSpot == -1){
            return false;  // stack overflow
        }

        // 1.find index
        int index = freeSpot;

        // 2.update freeSpot
        freeSpot = next[index];

        // 3.insert in array
        a[index] = X;

        // 4.update next
        next[index] = top[m-1];

        //5. update top
        top[m-1] = index;

        return true;
    }

    // pop into mth stack
    int pop(int m){
        if(top[m-1] == -1){
            return false;  // stack underflow
        }


        int index = top[m-1];

        top[m-1] = next[index];
        int popedElement = a[index];

        next[index] = freeSpot;

        freeSpot = index;

        return  popedElement;
    }

    ~NStack(){
        delete[] a;
        delete[] top;
        delete[] next;
    }
};

int main(){

    NStack s(3,6);

    cout<<s.push(10, 1)<<endl;
    cout<<s.push(9, 1)<<endl;
    cout<<s.push(12, 1)<<endl;
    cout<<s.push(21, 2)<<endl;
    cout<<s.push(7, 3)<<endl;

    cout<<"POP Element: "<<s.pop(1)<<endl;
    cout<<"POP Element: "<<s.pop(2)<<endl;
    cout<<"POP Element: "<<s.pop(1)<<endl;

   return 0;
}