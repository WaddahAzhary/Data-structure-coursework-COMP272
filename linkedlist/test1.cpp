#include<iostream>
using namespace std;

struct node {
    int data; 
    node *prev;
    node *next;
};

getNewNode (int i){
    node *newNode = new node; //allocate a dynamic memory in the heap
    newNode->data = i;
    newNode->prev = NULL;
    newNode->next = NULL;
}

InsertAtHead(int i){
    if (head == NULL){
        head =  
    }
}

node *head = NULL;

int main (){
    
    return 0;
}