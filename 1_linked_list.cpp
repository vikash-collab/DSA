# include<iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;

    Node(){
        cout<<"We are inside the default constructor"<<endl;
        this->next = NULL;
    }

    Node(int data){
        cout<<"We are inside the para. constructor"<<endl;
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        cout<<"Destructor called for: "<< this->data <<endl;
    }
}; 


void printLL(Node* head){
    Node* temp = head;

    while(temp!= NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }

    cout<<endl;
}

int getLength(Node* head){
    Node* temp = head;
    int length=0;
    while(temp!=NULL){
        ++length;
        temp = temp->next;
    }

    return length;
}


void insertAtHead(Node* &head, Node* &tail, int data){

    if(head == NULL){
        // empty LL

        // create node
        Node* newNode = new Node(data);
        //update head
        head = newNode;
        tail = newNode;
    }
    else{
    //create new node
    Node* newNode = new Node(data);
    // attach new node to head
    newNode->next = head;
    // Update head
    head = newNode;

    }

}

void insertAtTail(Node* &head, Node* &tail, int Data){
    if(head == NULL){
        // Empty node
        // step1. create  node
        Node* newNode = new Node;
        // step2. sigle node hai list me to
        // head & tail ko ispar point karva do
        head = newNode;
        tail = newNode;
    }
    else{
        // non-Empty node
        //step1. create node
        Node* newNode = new Node(Data);
        //step2. tail node ko attach karo new node se
        tail->next = newNode;
        // step3. update tail
        tail = newNode;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int Data, int position){

    int length = getLength(head);

    if(position <= 1){
        insertAtHead(head, tail, Data);
    }
    else if(position > length){
       insertAtTail(head, tail, Data);
    }
    else{
        // insert at middle of the list

        //step1: create new node
        Node* newNode = new Node(Data);

        // step2. traverse curr/prev to position
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1){
            prev = curr;
            curr = curr->next;
            --position;
        }

        // step3. attach prev->next  to  newNode
        prev->next = newNode;

        // step4. attach newNode->next to curr  
        newNode->next = curr; 
    }
}


void deleteNode(Node* &head, Node* &tail, int position){
    //empty list
    if(head == NULL){
        cout<<"Can't be delete, because LL is Empty."<<endl;
        return;
    } 
    
    if(head == tail){
        // single element
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return ;
    }
    

    int len = getLength(head);

    // delete from head
    if(position == 1){
      // first node ko delete kardo
      Node* temp = head;
      head  = head->next;  // or temp->next;
      temp->next = NULL;
      delete temp;        
    }
    else if(position == len){
      // last node ko dlete kardo
    
    // find prev
      Node* prev = head;
       while(prev->next != tail){
        prev = prev->next;
       }
      // prev node ka link null karo
       prev->next = NULL;
      // node delete karo 
       delete tail;
      // update tail 
       tail = prev;
    }
    else{
      // moddle me koi node ko delete karo

      // step1: set prev/ curr pointers
      Node* prev = NULL;
      Node* curr = head;
      while(position != 1){
        position--;
        prev = curr;
        curr = curr->next;
      }

      // step2: prev ke next me curr ka next add karo
      prev->next = curr->next;

      //step3: node isolate kardo
      curr->next = NULL;

      //step4: delete node
      delete curr;
    }
}



int main(){

    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtHead(head, tail, 50);
    // insertAtHead(head, tail, 40);
    // insertAtHead(head, tail, 30);
    // insertAtHead(head, tail, 20);
    // insertAtHead(head, tail, 10);

    cout<<"Before deletion of node: "<<endl;
    printLL(head);
    cout<<"Length of  the LL: "<<getLength(head)<<endl; 
    // cout<<"Before head => : "<<head->data<<endl;
    cout<<"Before tail=> : "<<tail->data<<endl;
    deleteNode(head, tail, 1);
    cout<<"After deletion of node:"<<endl;
    cout<<"After Length of  the LL: "<<getLength(head)<<endl; 
    // cout<<"after head => : "<<head->data<<endl;
    cout<<"After tail=> : "<<tail->data<<endl; // cause error??????
    printLL(head);

    
    


    // printLL(head);

    // insertAtPosition(head, tail, 4000, 3);
    // printLL(head);






    // // creation of node
    // // Node a;   

    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);
    // Node* tail = fifth;

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // // linked list create ho chuki hai

    // Node* head = first;

    // printLL(head);

    // cout<<"Length of LL is: "<<getLength(head)<<endl;

    // insertAtTail(head, tail, 500);
    // printLL(head);


 
return 0;
}