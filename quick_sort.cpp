#include <iostream>
using namespace std;

// Merge Sort with O(1) Space Complexity
// void inplaceMerge(int arr[], int start, int mid, int end){
//   // int leftSize = mid-start+1;
//   // int rightSize = end-mid;
  
  
//   int point1 = start;
//   int point2 = mid+1;
  
//   while(point1<=mid && point2<=end){
//     if(arr[point1]<=arr[point2]){
//       point1++;
//     }
//     else{
//       int value = arr[point2];
//       int index = point2;
      
//       while(index != point1){
//         arr[index] = arr[index-1];
//         index--;
//       }
//       arr[point1] = value;
      
//       point1++; mid++; 
//       point2++;
//     }
//   }
 
// }



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

int main() 
{   int arr[] = {160, 70, 60 , 50, 40, 10, 30, 200};
    int size = 8;
    
    quickSort(arr, 0, size-1);
    
    for(int i=0; i<size; i++){
      cout<<arr[i]<<" ";
    }
    return 0;
}
