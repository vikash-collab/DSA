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


// convert this BST into a sorted Doubly Linked List
void convertBSTtoDLL(Node* root, Node* &head){
    if(root == NULL){
        return;
    }
    // RNL
    // R                           
    convertBSTtoDLL(root->right, head);

    // N                           // right => as next and left => as prev
       // attaching next pointer of current node to head of LL
    root->right = head;
    if(head != NULL){
        head->left = root;
    }
    head = root;

    // L
    convertBSTtoDLL(root->left, head);
}

void  printLinkedList(Node* head){
    Node* temp = head;
    cout<<"Linked List is: "<<endl;
    while(temp!=NULL){
        cout<<temp->data<<"<->";
        temp = temp->right;
    }cout<<endl;
}


// convert Doubly Linked List to  BST
Node* convertDLLtoBST(Node* &head, int n){     // n => number of node    // galti pass by reference of head nhi karna
    // base case                                                         // taaki backtrack karte samay fir se pichle node per na aaye 
    if(head == NULL || n<=0){
        return NULL; 
    }

    // LNR
    // L
    cout<<"Solving left part: "<<endl;
    Node* leftSubtree = convertDLLtoBST(head, n/2);
  
    // N
    cout<<"creating current Node: "<<head->data<<endl;
    Node* root = head;
    root->left = leftSubtree;
      // head update
    head = head->right;                     // galti
    
    // R
    cout<<"Solving right part : "<<endl;
    Node* rightSubtree = convertDLLtoBST(head, n-(n/2)-1);
    root->right = rightSubtree;
    return root;
} 


int main(){

    
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    

    first->right = second;
    second->left = first;
    second->right = third;
    third->left = second;

    Node* head = first;

    Node* root = convertDLLtoBST(head, 3);

    levelOrderTraversal(root);


     

    // int inorder[] = {10, 20, 30, 40, 50, 60, 70};
    // int size = 7;
    // int start = 0;
    // int end = size - 1;
    // Node* root = bstFromInorder(inorder, start, end);

    // levelOrderTraversal(root);
    
    // Node* Head = NULL;
    // convertBSTtoDLL(root, Head);
    // printLinkedList(Head);

    return 0;
}





