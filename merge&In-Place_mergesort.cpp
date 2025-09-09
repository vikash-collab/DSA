#include <iostream>
using namespace std;

// void merge(int arr[], int start, int mid, int end){
//   int leftSize = mid-start+1;
//   int rightSize = end-mid;
  
//   int *arr1 = new int[leftSize];  // dynamic memory allocation
//   int *arr2  = new int[rightSize];
  
//   for(int i=0; i<leftSize; i++){
//     arr1[i] = arr[start+i];
//   }
  
//   for(int i=0; i<leftSize; i++){
//     arr2[i] = arr[mid+1+i];
//   }
  
//   int point1 = 0;
//   int point2 = 0;
  
//   int mainPoint = start;
  
//   while(point1<leftSize && point2<rightSize){
//     if(arr1[point1]<=arr2[point2]){
//       arr[mainPoint] = arr1[point1];
//       point1++; mainPoint++;
//     }
//     else{
//       arr[mainPoint] = arr2[point2];
//       mainPoint++; point2++;
//     }
//   }
  
//   while(point1<leftSize){
//     arr[mainPoint] = arr1[point1];
//     point1++; mainPoint++;
//   }
  
//   while(point2<rightSize){
//     arr[mainPoint] = arr2[point2];
//     point2++; mainPoint++;
//   }
  
  
//   delete []arr1;
//   delete []arr2;
// }


void inplaceMerge(int arr[], int start, int mid, int end){
  
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

int main() 
{   int arr[] = {160, 70, 60 , 50, 40, 10, 30, 200};
    int size = 8;
    mergeSort(arr, 0, size-1);
    
    for(int i=0; i<size; i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}
