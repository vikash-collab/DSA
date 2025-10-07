#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
}

void bubbleSort(vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
}

void selectionSort(vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i; // ith element hi smallest hai
    for (int j = i + 1; j < n; j++) {
      if (v[j] < v[minIndex]) {
        minIndex = j;
      }
    }

    // swap ith and minIndex elements;
    swap(v[i], v[minIndex]);
  }
}

void insertionSort(vector<int> &v) {
  int n = v.size();
  // i = 0, chhod deta hu
  for (int i = 1; i < n; ++i) {
    int key = v[i];
    int j = i - 1;

    // Move elements of arr[0..i-1] that are greater than
    // key to one position ahead of theri current position
    while (j >= 0 && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key; // insertion
  }
}




// simple merge
void merge(int arr[], int start, int mid, int end){
  int leftSize = mid-start+1;
  int rightSize = end-mid;
  
  int *arr1 = new int[leftSize];  // dynamic memory allocation
  int *arr2  = new int[rightSize];
  
  for(int i=0; i<leftSize; i++){
    arr1[i] = arr[start+i];
  }
    
  for(int i=0; i<leftSize; i++){
    arr2[i] = arr[mid+1+i];
  }

  int point1 = 0;
  int point2 = 0;

  int mainPoint = start;

  while(point1<leftSize && point2<rightSize){
    if(arr1[point1]<=arr2[point2]){
      arr[mainPoint] = arr1[point1];
      point1++; mainPoint++;
    }
    else{
      arr[mainPoint] = arr2[point2];
      mainPoint++; point2++;
    }
  }
      
  while(point1<leftSize){
    arr[mainPoint] = arr1[point1];
    point1++; mainPoint++;
  }
        
  while(point2<rightSize){
    arr[mainPoint] = arr2[point2];
    point2++; mainPoint++;
  }
                 
  delete []arr1;
  delete []arr2;
}
                
                
                
// Merge Sort with O(1) Space Complexity
void inplaceMerge(int arr[], int start, int mid, int end){
  // int leftSize = mid-start+1;
  // int rightSize = end-mid;
  
  
  int point1 = start;
  int point2 = mid+1;
  
  while(point1<=mid && point2<=end){
    if(arr[point1]<=arr[point2]){
      point1++;
    }
    else{
      int value = arr[point2];
      int index = point2;
      
      while(index != point1){
        arr[index] = arr[index-1];
        index--;
      }
      arr[point1] = value;
      
      point1++; mid++; 
      point2++;
    }
  }
  
}

void mergeSort(int arr[], int start, int end){
  if(start>=end){
    return;
  }
  
  int mid = (start + end)/2;
  
  mergeSort(arr, start, mid);
  mergeSort(arr, mid+1, end);
  
  inplaceMerge(arr, start, mid, end);
  // merge(arr, start, mid, end);
}



void quickSort(int arr[], int start, int end){
  if(start>=end){
    return;
  }
  
  
  int pivot = end;
  
  int i=start-1; int j=start;
  
  while(i<=j && j<pivot){
    if(arr[j]<arr[pivot]){
      i++;
      swap(arr[j], arr[i]);
    }
    
    j++;
  }
  
  i++;
  swap(arr[i], arr[pivot]);
  
  
  quickSort(arr, start, i-1);
  
  quickSort(arr, i+1, end);
  
}



int main() {
  vector<int> v = {44,33,55,22,11};
  // int arr[] = {160, 70, 60 , 50, 40, 10, 30, 200};
  // int size = 8;
  // mergeSort(arr, 0, size-1);

  // bubbleSort(v);
  // selectionSort(v);
  insertionSort(v);
  print(v);
  return 0;
}