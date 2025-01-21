#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int Value){
        this->data = Value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertBST(Node* &root, int data){
      if(root == NULL){
        root = new Node(data);
        return root;
      }

      if(data > root->data){
        root->right = insertBST(root->right, data);
      }
      else{
        root->left = insertBST(root->left, data);
      }
    return root;
}

void createBST(Node* &root){
     cout<<"Enter data: "<<endl;
     int data;
     cin>>data;

     while(data != -1){
         root = insertBST(root, data);
         cout<<"enter data :"<<endl;
         cin>>data;
     }
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    

    while(!q.empty()){
        Node* temp = q.front();                           // galti
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data << " ";

            if(temp->left != NULL){         // galti kare
                q.push(temp->left);        // galti kare
            }
            if(temp->right != NULL){          // galti kare
                q.push(temp->right);          // galti kari
            }
        }

    }
}



int getKthSmallestElement(int arr[], int n, int k){
    priority_queue<int> pq;
    //first k elemnt ko process kro
    for(int i=0; i<k; i++){
        int element = arr[i];
        pq.push(element);
    }
    // remaining element ko tabhi insert karege jab vo root se chote hoge
    for(int i=k; i<n; i++){
        int element = arr[i];
        if(element < pq.top()){
            pq.pop(); // form the top element
            pq.push(element);
        }
    }
    return pq.top();
}

int getKthGreatestElement(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    //first k element ko process kro
    for(int i=0; i<k; i++){
        int element = arr[i];
        pq.push(element);
    }
    // remaining element ko tabhi insert karoge jab vo root se bda hoga
    for(int i=k; i<n; i++){
        int element = arr[i];
        if(element > pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}

// class Info{
//     public:
//     int maxVal = INT_MIN;
//     bool isHeap = true;
//     Info(int a, int b){
//         this->maxVal = a;
//         this->maxVal = b;
//     }
// };

// Info checkMaxHeap(Node* root){
//     // base case
//     if(root==NULL){
//         Info temp;
//         temp.maxVal = INT_MIN;
//         temp.isHeap = true;
//         return temp
//     }

//     if(root->left == NULL && root->right == NULL){
//         Info temp;
//         temp.maxval = root->data;
//         temp.isHeap = true;
//         return temp;
//     }

//     Info leftAns = checkMaxHeap(root->left);
//     Info rightAns = checkMaxHeap(root->right);

//     if(root->data > leftAns.maxval && root->data > rightAnsmaxvak && 
//         leftAns.isHeap && rightAns.isHeap){
//        Info ans;
//        ans.maxVal = root->data;
//        ans.isHeap = true;
//        return ans;
//     }
//     else{
//         Info ans;
//         ans.maxVal = max(root->data, max(leftAns.maxVal, right.maxVal));
//         ans.isHeap = false;
//         return ans;
//     }

// }

void storeInorderTraversal(Node* root, vector<int>&inorder){
    if(!root) return;
    //LNR
    storeInorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    storeInorderTraversal(root->right, inorder);
}

void replaceUsingPostOrder(Node* root, vector<int>&inorder, int &index){
    if(!root) return;

    //LRN
    replaceUsingPostOrder(root->left, inorder, index);
    replaceUsingPostOrder(root->right, inorder, index);
    root->data = inorder[index++];
}

Node* convertBSTIntoMaxHeap(Node* root){
    // step:1 store inorder
    vector<int> inorder;
    storeInorderTraversal(root, inorder);

    // replace the node values with the stored inorder values, using the postOrder traversal
    int index = 0;
    replaceUsingPostOrder(root, inorder, index);
    return root;
}


int main(){
    Node* root = NULL;
    createBST(root);
                             // 100 50 150 40 60 110 200 20 -1
    cout<<"Printintg BST: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    root = convertBSTIntoMaxHeap(root);
    cout<<"Printing the Heap: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;




    

    



    // int arr[] = {3,7,4,5,6,8,9};
    // int n = 7;
    // int k = 2;

    // cout<<"Kth largest element: "<<getKthGreatestElement(arr, n, k)<<endl;
    
    // cout<<"Kth Smallest Element: "<<getKthSmallestElement(arr, n, k)<<endl;


    // // create Min Heap  (type, container, comparator)
    // priority_queue<int, vector<int>, greater<int> > pq;
    // // insertion
    // pq.push(100);
    // pq.push(90);
    // pq.push(80);
    // pq.push(70);

    // // // create Max-Heap   default
    // // priority_queue<int> pq;
    // // //insertion
    // // pq.push(10);
    // // pq.push(20);
    // // pq.push(30);
    // // pq.push(40);
    // // pq.push(50);


    // cout<<"Top Element of Heap: "<<pq.top()<<endl;
    // pq.pop();
    // cout<<"Top Element of Heap: "<<pq.top()<<endl;
    // cout<<"Size of Heap: "<<pq.size()<<endl;
    // if(pq.empty()){
    //     cout<<"Heap is empty "<<endl;
    // }
    // else{
    //     cout<<"Heap in not empty."<<endl;
    // }

    return 0; 
}