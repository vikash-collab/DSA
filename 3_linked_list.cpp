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


bool checkLoop(Node* &head){

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow){
            return true;
        }
    }
    return false;
}

Node* getStartingPointOfLoop(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow){
            break;
        }
    }

    // yha per pahuch ne ka matlab ha fast slow meet kar chuke hai
    slow = head;
    
    // slow & fast -> 1 step
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

void removeLoop(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(fast == slow){
            break;
        }
    }


    // yha per pahuch ne ka matlab ha fast slow meet kar chuke hai
    slow = head;
    
    // slow & fast -> 1 step
    while(fast != slow){
        fast = fast->next;
        slow = slow->next;
    }
    // start point
    Node* startPoint = slow;

    Node* temp = fast;  // = startPoint
    while(temp->next != startPoint){
        temp = temp->next;
    }

    temp->next = NULL;
}


Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void addOne(Node* & head){
    // reverse
    head = reverse(head);
    // add 1
    int carry = 1;
    Node* temp = head;
    while(temp->next != NULL){
        int totalSum = temp->data + carry;
        int digit= totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;
        temp = temp->next;

        if(carry == 0){
            break;
        }
    }
    
    // process last node
    if(carry != 0){
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum / 10;

        temp->data = digit;
        if(carry != 0){
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
    }

    //reverse
    head = reverse(head);
    
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    // insertAtHead(head, tail, 90);
    // insertAtHead(head, tail, 77);
    // insertAtTail(head, tail, 10);
    
    addOne(head);
    printLL(head);


    // tail->next = head->next;
    
    // // printLL(head);
    // cout<<getStartingPointOfLoop(head)->data<<endl;

    // removeLoop(head);
    // printLL(head);

    return 0;
}