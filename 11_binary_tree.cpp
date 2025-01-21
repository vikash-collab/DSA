#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// it return root node of the created tree
Node* createTree() {
    cout<< "enter the value: "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    // step1: create node
    Node* root = new Node(data);

    //step2: create left subtree
        // cout<<"left  of Node : "<<root->data<<endl;
    root->left = createTree();

    //step3: create right subtree
        // cout<<"right of Node: "<<root->data<<endl;
    root->right = createTree();
    return root;
}


void preOrderTraversal(Node* root){
    // base case
    if(root == NULL){
        return;
    }
    // N L R
    // N
    cout<< root->data << " ";
    // L
    preOrderTraversal(root->left);
    // R
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node* root){
    // L N R
    // base case
    if(root == NULL){
        return;
    }
    // L
    inOrderTraversal(root->left);
    // N
    cout<< root->data << " ";
    // R
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    // L R N
    // base case
    if(root == NULL){
        return;
    }
    // L
    postOrderTraversal(root->left);
    // R
    postOrderTraversal(root->right);
    // N
    cout<< root->data << " ";
}


void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);

    //asli traversal start karte hai
    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        cout<<front->data<<" ";

        if(front->left != NULL){
            q.push(front->left);
        }
        if(front->right != NULL){
            q.push(front->right);
        }
    }
}


void levelOrderTraversal2(Node* root){    // Null push real lot
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    //asli traversal start karte hai
    while(!q.empty()){
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
               q.push(NULL);
            }
        }
        else{
            // valid node vala case
            cout<<front->data<<" ";

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }
    }
}



int main(){
    Node* root =  createTree();
    // cout<<root->data<<endl;

// 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1 for input can take

    cout<<"printing preorder: ";
    preOrderTraversal(root);
    cout<<endl;

    cout<<"printing inOrder: ";
    inOrderTraversal(root);
    cout<<endl;

    cout<<"printing postOrder: ";
    postOrderTraversal(root);
    cout<<endl;

    cout<<"Level Order: ";
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"Level Order: "<<endl;
    levelOrderTraversal2(root);
    cout<<endl;



    return 0;
}
