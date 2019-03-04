//
// Created by Lian, Peng on 2019-03-03.
//

#include "linkedlist.h"

using namespace std;
using namespace L;

// constructor
linkedlist::linkedlist() {
    head = NULL;
    tail = NULL;

    printf("\nWelcome to use the linked list module!\n");
}

// create a new node
void linkedlist::createNode(int value){
    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;

    // if it is the fist node
    if (head == NULL){
        head = temp;        // set current node to head node
        tail = temp;        // set current node to last node
        //temp = NULL;
    } else {
        tail->next = temp;    // add temp to last node's next
        tail = temp;          // set the current node to last node
    }
}

// insert as head
void linkedlist::insert_start(int value){
    Node *temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
}

// insert after position
void linkedlist::insert_position(int pos, int value){
    int len = length();

    if (pos == 0) {
        insert_start(value);
    } else if (pos < len){
        int i = 0;
        Node *temp = head;
        Node *temp_current = new Node;

        temp_current->data = value;

        // slide to pos
        while (i<pos-1){
            temp = temp->next;
            i += 1;
        }
        temp->next = temp_current;
        temp_current->next = temp+1;
    } else {
        createNode(value);
    }
}


void linkedlist::delete_start(){
    Node *temp = new Node;
    temp = head;
    head = head->next;
    delete temp;
}

void linkedlist::delete_end(){
    Node *temp = head;
    Node *pre = new Node;

    while (temp->next != NULL){
        pre = temp;
        temp = temp->next;
    }

    pre->next = NULL;
    tail = pre;
    delete temp;

}

// delete ith node
void linkedlist::delete_position(int pos){
    int len = length();

    if (pos <= 1){
        delete_start();
    } else if (pos >= len) {
        delete_end();
    } else {
        Node *temp = head;
        Node *current = new Node;

        int i = 1;

        while(i<pos-1){
            temp = temp->next;
            i += 1;
        }

        current = temp->next;
        temp->next = current->next;

        delete current;

    }
}


//TODO
// unique
// sort

// get length
int linkedlist::length(){
    Node *temp = head;

    int i = 0;
    while (temp != NULL){
        temp = temp->next;
        i += 1;
    }
    //printf("%d\n", i);
    return i;
}

// display the list
void linkedlist::display(){
    Node *temp = head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
