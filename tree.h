//
// Created by Lian, Peng on 2019-03-05.
//

#ifndef CPP_LEARN_TREE_H
#define CPP_LEARN_TREE_H

#include <stdio.h>
#include <list>
#include <stack>
#include <climits>

namespace TREE{
    class Tree {

    public:
        Tree();             //constructor

        // node of the tree
        struct Node{
            int data;
            struct Node *left, *right;
        };

        // create a node
        Node *addNode(int data) {

            Node *temp = new Node;
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;

            return temp;
        }

        void display(Node *root);               // display a tree
        void deepFistUtil(Node *root);
        void breadthFistUtil(Node *root);
        void allDepth(Node *root, int d=1);     // find all depth
        int minDepth(Node *root);               // find minimium depth
        int pathSum(Node *root, int sum);
        int maxPathSum(Node *root);             // find maxmium path sum
        bool isFullBST(Node *root);
        bool canRepresentBST(int arr[], int n); // arr can represent BST or not

    };

}


#endif //CPP_LEARN_TREE_H
