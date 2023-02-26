/*Q2,b: This problem asked for swapping two adjacent elements in a list by adjusting only the links
 (and not the data) using doubly linked list. I devided my solution to several functions to simplfy 
 my code and improve its readablitiy. I had a bug in the swapAdjacent() function and I was able to fix
 it using the debugger. The bug was that after swapping the two nodes the third node prev pointer
 wasn't updated. Also, I found drawing a diagram and following the debugger helpful (and time 
 consuming as well :))*/
 
#include <iostream>
using namespace std;

struct node {
    int data; 
    node *prev;
    node *next;
};

node *head = NULL; 

node* getNewNode (int i){
    node *newNode = new node;  //allocate a dynamic memory in the heap
    newNode->data = i;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int i){
    node *newNode = getNewNode(i);
    if (head == NULL){    //addressing inserting the first node in the list.
        head =  newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;    
}

void swapAdjacent() {
    node *temp = head;
    while (temp != NULL && temp->next!=NULL ) {
        node *temp1 = temp;
        node *temp2 = temp->next;
         if(temp2->next != NULL){
            temp2->next->prev = temp1;
        }
        temp1->next = temp2->next;
        temp2->prev = temp1->prev;
        if (temp1->prev != NULL) {
            temp1->prev->next = temp2;
        }
        temp1->prev = temp2;
        temp2->next = temp1;
       
        if (temp == head) {
            head = temp2;
        }
       
        temp = temp->next;
    }
}

void display (){
    node *temp = head;
    while (temp != NULL){
        cout  <<temp->data << '\t';
        temp = temp->next;    
    }
    cout << '\n';
}

int main (){
    InsertAtHead(8); 
    InsertAtHead(4);
    InsertAtHead(12);
    InsertAtHead(3);
    InsertAtHead(-8);
    InsertAtHead(7);
    cout << "The original list is: " << endl;
    display();
    swapAdjacent();
    cout << "The list after swapping the adjacent elements is: " << endl;
    display();
       
    return 0;
}