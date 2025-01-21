# include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }   
    cout<<endl;
}

int getLength(Node* &head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    // LL is Empty
    if(head == NULL){
        head = tail = newNode;
    }
    else{
      // LL is not Empty
      newNode->next = head;
      head->prev = newNode;
      head = newNode;      
    }
}

void insertAtTail(Node* &head, Node* &tail, int data){
    // LL is Empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = tail = newNode;
    }
    else{
    // LL is not Empty
       Node* newNode = new Node(data);
       tail->next = newNode;
       newNode->prev = tail;
       tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position){
    //LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = tail = newNode;
    }
    else{  
        int length = getLength(head);
        if(position == 1){
           insertAtHead(head, tail, data);
        } 
        else if(position == length+1){
           insertAtTail(head, tail, data);
        }
        else{
            // insert in middle
            // step1. create node
            Node* newNode = new Node(data);
            // step2. set prev and curr pointer
            Node* prevNode = NULL;
            Node* currNode = head;
            while(position != 1){
                position--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            //step3. pointers update kar de
            prevNode->next = newNode;
            newNode->prev = prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }

}

void deleteNode(Node* &head, Node* &tail, int position){
    if(head == NULL){
       //LL is empty
        cout<<"can't be deleted because LL is empty. "<<endl;
        return;
    }
    if(head == tail){
        // single element
        Node* temp = head;
        delete tail;        
        head = NULL;
        tail = NULL;
        return;
    }
    int length  = getLength(head);

    if(position == 1){
        // delete from head
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if(position == length){
        // delete from tail
        Node* prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }
    else{
        // delete from middle
        //step1. set prevNode/ currNode/ nextNode pointers
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position != 1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;
        //step2. Update pointers
        prevNode->next = nextNode;
        currNode->prev = NULL; 
        currNode->next = NULL;
        nextNode->prev = prevNode;
        delete currNode;        
    }


}



int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    printLL(head);

    deleteNode(head, tail, 1);
    printLL(head);

    // deleteNode(head, tail, 2);
    // printLL(head);

    // deleteNode(head, tail, 2);
    // printLL(head);

    // cout<<"length of LL: "<<getLength(head)<<endl;

    // deleteNode(head, tail, 1);
    // printLL(head);
    
    // cout<<"length of LL: "<<getLength(head)<<endl;



    // insertAtPosition(head, tail, 1000, 8);
    
    // insertAtTail(head, tail, 1000);
    // printLL(head);

    return 0;   
}