#include<iostream>
using namespace std;

class Heap{
    public:
    int *arr;
    int capacity;
    int size;
    Heap(int capacity){
        this->arr = new int[capacity];
        this->capacity = capacity;
        // size = current number of elements in heap
        this->size = 0;
    }

    void insert(int val){
        if(size == capacity){
            cout<<"Heap is overflow:"<<endl;
            return;
        }
        // size increase kar jaega
        size++;
        int index = size;
        arr[index] = val;

        // take value to its correct position
        while(size > 1){
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]){
                swap( arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    void printHeap(){
        cout<<"Printing Heap  elements are:"<<endl;
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    int deleteFromHeap(){
        int answer = arr[1];  // store value of the answer of that deleted element
        // replacement
        arr[1] = arr[size];
        // last element ko uski original position se
        size--;
        
        int index = 1;
    
        while(index < size){
            int leftIndex = 2*index;       
            int rightIndex = 2*index + 1;

            // find out karna hai, sabse bda kon Hai
            int largestIndex = index;
            //  check left child
            if(leftIndex <= size && arr[largestIndex] < arr[leftIndex]){
                largestIndex = leftIndex;
            } 
            if(rightIndex <= size && arr[largestIndex] < arr[rightIndex]){
                largestIndex = rightIndex;
            }

            // no change
            if(index == largestIndex){
                break;
            }
            else{
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
        }
        return answer;
    }
};

void heapify(int *arr, int n, int index){
    int leftIndex = 2*index;
    int rightIndex = 2*index + 1;
    int largestKaIndex = index;
    
    // teno me se max lao
    if(leftIndex <= n && arr[leftIndex] > arr[largestKaIndex]){
        largestKaIndex = leftIndex;
    }
    if(rightIndex <= n && arr[rightIndex] > arr[largestKaIndex]){
        largestKaIndex = rightIndex;
    }

    // after these 2 condition largestKaIndex will be pointing towards largest elemnt among 3
    if(index != largestKaIndex){
        swap(arr[index], arr[largestKaIndex]);
        // ab recursion sambhal lega
        index = largestKaIndex;
        heapify(arr, n, index);
    }
}

void bulidHeap(int *arr, int n){

    for(int index = n/2; index>0; index--){
        heapify(arr, n, index);
    }
}

void HeapSort(int arr[], int n){
    while(n != 1){
        swap(arr[1], arr[n]);
        n--;
        heapify(arr, n, 1);
    }
}


 

int main(){
    int arr[] = {-1, 5, 10, 12, 15, 20, 25};
    int n = 6;

    bulidHeap(arr, n);
    
    cout<<"Printing elements before Heap sort : "<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    HeapSort(arr, n);

    cout<<"Printing elements after the Heap Sort: "<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;





    // Heap h(20);
    // // insertion
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // h.printHeap();

    // int ans = h.deleteFromHeap();
    // cout<<"Answer: "<<ans<<endl;

    // h.printHeap();
    return 0;
}