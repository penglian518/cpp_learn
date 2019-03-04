//
// Created by Lian, Peng on 2019-03-03.
//

#ifndef CPP_LEARN_LINKEDLIST_H
#define CPP_LEARN_LINKEDLIST_H

#include <iostream>

namespace L{
    struct Node {
        int data;
        struct Node *next;
    };


    class linkedlist {
    private:
        Node *head, *tail;

    public:
        linkedlist();

        void createNode(int value);
        void insert_start(int value);
        void insert_position(int pos, int value);
        void delete_start();
        void delete_end();
        void delete_position(int pos);
        int length();
        void display();

    };

}


#endif //CPP_LEARN_LINKEDLIST_H
