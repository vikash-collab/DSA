#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Info{
    public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int Data, int RowIndex, int ColIndex){
        this->data = Data;
        this->rowIndex = RowIndex;
        this->colIndex = ColIndex;
    } 
};

class compare{             // machine know only normal type but we create object so machine does not know how to  and what to compare so we need to write comparator class 
    public:
    bool operator()(Info* a, Info* b){
        return (a->data > b->data);
    }
};

void mergeSortedArray(int arr[][4], int n, int k, vector<int>&ans){

    priority_queue<Info*, vector<Info*>, compare> pq;
    
    
    // 1:step process first k element
    for(int row=0; row < k; row++){
        int element = arr[row][0];
        Info* temp = new Info(element, row, 0);
        pq.push(temp);
    }

    while(!pq.empty()){
        Info* temp = pq.top();
        pq.pop();
        int topData = temp->data;
        int topRow = temp->rowIndex;
        int topCol = temp->colIndex;
        
        // store ans vector
        ans.push_back(topData);

        // next element for same row, jisme se just pop kia h just abhi
        // use insert karna hai
        if(topCol + 1 < n){
            // iska matlab row me abhi element present hai
            Info* newInfo = new Info(arr[topRow][topCol+1], topRow, topCol+1);
            pq.push(newInfo);
        }

    }

}

int main(){

    int arr[3][4] = {
                {1, 4, 8, 11},
                {2, 3, 6, 10},
                {5, 7, 12, 14}
    };
    int n = 4;
    int k = 3;

    vector<int>ans;
    mergeSortedArray(arr, n, k, ans);

    cout<<"Printing Ans array: "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }cout<<endl;

    return 0; 
}