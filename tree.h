//
// Created by Lian, Peng on 2019-03-05.
//

#ifndef CPP_LEARN_TREE_H
#define CPP_LEARN_TREE_H

#include <stdio.h>

namespace TREE{
    class Tree {

    public:
        Tree();             //constructor

        // node of the tree
        struct Node{
            int data;
            struct Node *left, *right;
        };

        /* create a node
        Tree::Node addNode(int data) {
            Node *temp = new Node;
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            return *temp;
        }
        */

        Tree::Node* addNode(int data);

        // display a tree
        void display(Node *root);
        void deepFistUtil(Node *root);
        void breadthFistUtil(Node *root);
        void allDepth(Node *root, int d=1);
        int minDepth(Node *root);
        int pathSum(Node *root, int sum);
        int maxPathSum(Node *root);

        // binary search tree (BST)
        Tree::Node* searchBST(Node *root, int data);
        Tree::Node* insertBST(Node *root, int data);
        Tree::Node* deleteBST(Node *root, int data);


    };

}


#endif //CPP_LEARN_TREE_H
