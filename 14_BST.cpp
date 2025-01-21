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

void preOrder(Node* root){
    if(root == NULL){
        return; 
    }

    // NLR
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);    
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    // LNR
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    // LRN
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}


Node* minValue(Node* root){
    if(root == NULL){
        cout<<" NO MIN Value: ";
        return NULL;
    }

    Node* temp = root;

    while(temp->left != NULL){       // mistake
        temp = temp->left;
    }

    return temp;
}

Node* maxValue(Node* root){
    if(root == NULL){
        return NULL;
    }

    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

bool searchInBST(Node* root, int target){
     if(root == NULL){
        return false;
     }
     
     // 1- case muje solve karna tha
     if(root->data==target){
        return true;
     }
     
     bool leftAns = false;     // focus
     bool rightAns = false;    // focus

     if(root->data > target){
        leftAns = searchInBST(root->left, target);
     }
     else{
        rightAns = searchInBST(root->right, target);
     }

     return leftAns || rightAns;
}



Node* deleteFromBST(Node* root, int target){                 // most Important
    // target ko dhundo
    // target ko delete karo

    if(root == NULL){
        return NULL;
    }

    if(root->data == target) {
        //ab delete karege
        // use 4 cases

        if(root->left == NULL && root->right == NULL){
            // 1 case-> leaf node
            delete root;
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            // 2 case-> left Non NULL and right NULL
            Node* childSubTree = root->left;
            delete root;
            return childSubTree; 
        }
        else if(root->left == NULL && root->right != NULL){          // galti
            // 3 case-> left NULL and right Non NULL
            Node* childSubTree = root->right;
            delete root;
            return childSubTree;
        }
        // 4 case -> left Non NULL and right Non NULL
        else{
            // a -> left subtree ki max value lao
            Node* maxi = maxValue(root->left);              // galti
            // replacement
            root->data = maxi->data;
            // delete actual left maxi wali node
            root->left  = deleteFromBST(root->left, maxi->data);        // galti
            return root;
        }
    }
    else if(root->data > target){
        // left me chalo
        root->left = deleteFromBST(root->left, target);       // updated tree dega bcz root->left store kiya  //galti
    }
    else{
        // right me chalo
        root->right = deleteFromBST(root->right, target);                // galti 
    }                                                                    
    return root;
}



int main(){

    Node* root = NULL;
    createBST(root);

    cout<<"level Order Traversal: "<<endl; 
    levelOrderTraversal(root);
    
    // cout<<"preOrder: "<<endl;
    // preOrder(root);
    // cout<<endl;
    // cout<<"Inorder: "<<endl;
    // inOrder(root);
    // cout<<endl;
    // cout<<"Postorder: "<<endl;
    // postOrder(root);
    // cout<<endl;
    

    // Node* minNode  = minValue(root);
    // if(minNode == NULL){
    //     cout<<"there is noNode in tree, so no min Value."<<endl;
    // }
    // else{
    //     cout<<"Min Value: "<<minNode->data<<endl;
    // }


    // Node* maxNode = maxValue(root);
    // if(maxNode == NULL){
    //     cout<<"there is noNode in tree, so no max Value."<<endl;
    // }
    // else{
    //     cout<<"Max Value: "<<maxNode->data<<endl;
    // }


    int target;
    cout<<"Enter the value of Target: "<<endl;
    cin>>target;

    while(target != -1){
        deleteFromBST(root, target);
        cout<<"level Order Traversal: "<<endl; 
        levelOrderTraversal(root);
        cout<<"Enter the value of Target: "<<endl;
        cin>>target;
    } 




    // int t;
    // cout<<"enter the target: "<<endl;
    // cin>>t;    
    // while(t != -1){
    //     bool ans = searchInBST(root, t);
    //     if(ans == true){
    //         cout<<"Found"<<endl;
    //     }
    //     else{
    //         cout<<"Not Found"<<endl;
    //     }
    //     cout<<"Enter the target: "<<endl;
    //     cin>>t;
    // }



    return 0;
}



// 50 30 20 25 40  60  70  80 55 -1