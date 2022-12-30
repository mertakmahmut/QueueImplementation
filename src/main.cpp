#include <iostream>

using namespace std;

#define SIZE 10

class Node{
    public:
    int data;
    Node* next;
    Node(int data = 0){
        this->data = data;
        next = NULL;
    }
};

class Queue{
    public:
    Node* root;
    Node* tail;
    int cnt;
    Queue(){
        root = NULL;
        tail = NULL;
        cnt = 0;
    }
    bool isEmpty(){
        return root == NULL;
    }
    bool isFull(){
        return cnt == SIZE;
    }
    void enQueue(int value){
        if(isFull()){
            cout << "Queue if full, you can't add." << endl ;
        }
        else if(isEmpty()){
            root = new Node(value);
            tail = root;
            cnt++;
            cout << "New item added to queue." << endl ;
        }
        else{
            tail->next = new Node(value);
            tail = tail->next;
            cnt++;
            cout << "Item added to tail of queue." << endl ;
        }
    }
    void deQueue(){
        if(isEmpty()){
            cout << "No item to be deleted." << endl ;
        }
        else{
            if(root->next == NULL){
                delete root;
                root = NULL;
                tail = NULL;
                cnt--;
                cout << "The only remaining item is deleted from queue." << endl;
            }
            else{
            Node* temp = root;
            root = root->next;
            delete temp;
            cnt--;
            cout << "Head item is deleted from queue." << endl ;
            }
        }
    }
    void print(){
        system("cls");
        if(isEmpty()){
            cout << "Queue is empty" << endl;
        }
        else{
            cout << "FRONT ";
            Node* temp = root;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << "REAR"<< endl ;
        }
    }
    void reset(){
        if(isEmpty()){
            cout << "Queue is empty." << endl ;
        }
        else{
        while(!isEmpty()){
            deQueue();
        }
        system("cls");
        cout << "All nodes are deleted. "  << endl ;

        }
    }
    void sizeQ(){
        cout << "Size: " << cnt << endl ;
    }
};

void findMax(Queue a){
    system("cls");
    Node* temp = a.root;
    int max1 = temp->data;
    for(int i=0 ; i<a.cnt ; i++){
        if(max1 <= temp->data){
            max1 = temp->data;
        }
        temp = temp->next;
    }
    cout << "Max item is: " << max1 << endl ;
}

int main()
{
    Queue q;
    int choice, value;
    while(1){
        cout << "1- enqueue" << endl ;
        cout << "2- dequeue" << endl ;
        cout << "3- print" << endl ;
        cout << "4- reset" << endl ;
        cout << "5- size" << endl ;
        cout << "6- FIND MAX" << endl ;
        cout << "0- exit" << endl ;
        cout << "Choice: " ;
        cin>>choice;
        switch(choice){
            case 1: cout << "Number: " ;
                cin >> value;
                q.enQueue(value); break;
            case 2: q.deQueue(); break ;
            case 3: q.print(); break;
            case 4: q.reset(); break;
            case 5: q.sizeQ(); break;
            case 6: findMax(q); break;
            case 0: return 0; break;
        }
    }



    return 0;
}
