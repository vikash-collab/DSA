#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertInBST(Node* root, int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }

    if(root->data > data){
        // left me jaao
        root->left = insertInBST(root->left, data);
    }
    else{
        // right me jaao
        root->right = insertInBST(root->right, data);
    }
    return root;
}

void createBST(Node* &root){
    int data;
    cout<<"Enter the Data: "<<endl;
    cin>>data;

    while(data != -1){
        root = insertInBST(root, data);
        cout<<"Enter the Data: "<<endl;
        cin>>data;
    }
}


void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
           cout<<endl;
            if(!q.empty()){
             q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left != NULL){
                q.push(temp->left);
            }
            if(temp->right != NULL){
                q.push(temp->right);
            }
        }
    }
}



Node* bstFromInorder(int inorder[], int s, int e){
    // base case
    if(s > e){
        return NULL;
    }

    // 1 case solve karna hai
    int mid =   (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    // baaki sarre ke liye
    root->left = bstFromInorder(inorder, s, mid-1);

    root->right = bstFromInorder(inorder, mid+1, e);

    return root;
}



// Node* bstFromInorder(int inorder[], int s, int e){
//     // base case
//     if(s > e){
//         return NULL;
//     }

//     // 1 case solve karna h
//     int mid = s + (e-s)/2;
//     int element = inorder[mid];
//     Node* root = new Node(element);

//     // Bakki recursion
//     root->left = bstFromInorder(inorder, s, mid-1);

//     root->right = bstFromInorder(inorder, mid+1, e);

//     return root;
// }


int main(){

    int inorder[] = {10, 20, 30, 40, 50, 60, 70};
    int size = 7;
    int start = 0;
    int end = size-1;

    Node* root = bstFromInorder(inorder, start, end);
    levelOrderTraversal(root);
    
    return 0;   
}

