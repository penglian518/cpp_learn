//
// Created by Lian, Peng on 2019-03-05.
//

#include "tree.h"
#include <list>

using namespace std;
using namespace TREE;

Tree::Tree() {
    printf("\nWelcome to use the Tree modeule!\n");

}

void Tree::allDepth(TREE::Tree::Node *root, int d) {
    // recursive traversal
    int deepth = d;

    if (root->left != NULL && root->right != NULL) {
        deepth += 1;
        allDepth(root->left, deepth);
        allDepth(root->right, deepth);
    } else if (root->left != NULL && root->right == NULL){
        deepth += 1;
        allDepth(root->left, deepth);
    } else if (root->left == NULL && root->right != NULL){
        deepth += 1;
        allDepth(root->right, deepth);
    } else {
        printf("%d\n", deepth);
    }
}

int Tree::minDepth(TREE::Tree::Node *root) {
    // recursive traversal

    if (root == NULL){
        return 0;
    }

    if (root->left == NULL && root->right == NULL){
        return 1;
    }

    if (!root->left){
        return minDepth(root->right) + 1;
    } else if (!root->right){
        return minDepth(root->left) + 1;
    } else {
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }

}


int Tree::pathSum(TREE::Tree::Node *root, int sum) {

    /*
    int d = root->data;
    int l = pathSum(root->left, sum);
    int r = pathSum(root->right, sum);
    int max_single = max(max(l, r)+d, d);
    int max_top = max(max_single, l+r+d);
    printf("%d %d\n", d, sum);
    sum = max(sum, max_top);
    */
    //s = max(d, max(d+l, max(d+r, d+l+r)));

    // calculate the sum of all path to this node

    if (root->left == NULL && root->right == NULL) {
        int temp = sum;
        int d = root->data;
        sum = max(temp, temp+d);
        printf("%d %d\n", d, sum);

    }
    if (root->left != NULL && root->right == NULL) {
        int temp = sum;
        int d = root->data;
        int l = pathSum(root->left, temp);
        sum = max(l, l+d);
        printf("%d %d %d\n", d,l, sum);


    }
    if (root->left == NULL && root->right != NULL) {
        int temp = sum;
        int d = root->data;
        int r = pathSum(root->right, temp);
        sum = max(r, r+d);
        printf("%d %d %d\n", d, r, sum);


    }
    if (root->left != NULL && root->right != NULL) {
        int temp = sum;
        int d = root->data;
        int l = pathSum(root->left, temp);
        int r = pathSum(root->right, temp);
        sum = max(temp, max(temp+d, d+max(l, r)));          // bug. if l+r+d will be 43, which means for node 2 it will sum all the sub nodes.
        printf("%d %d %d %d\n", d,l, r, sum);
    }

    return sum;

}


int Tree::maxPathSum(TREE::Tree::Node *root) {
    int sum = 0;

    return pathSum(root, sum);
}



void Tree::deepFistUtil(TREE::Tree::Node *root) {
    // recursive traversal
    printf("%d ", root->data);

    if (root->left != NULL && root->right != NULL){
        deepFistUtil(root->left);
        deepFistUtil(root->right);
    } else if (root->left != NULL && root->right == NULL){
        deepFistUtil(root->left);
    } else if (root->left == NULL && root->right != NULL){
        deepFistUtil(root->right);
    }
}


void Tree::breadthFistUtil(TREE::Tree::Node *root) {
    list<TREE::Tree::Node *> queue;            // queue for the child nodes
    queue.push_back(root);

    while (!queue.empty()) {
        TREE::Tree::Node *s = queue.front();
        queue.pop_front();

        printf("%d ", s->data);

        if (s->left != NULL){
            queue.push_back(s->left);
        }
        if (s->right != NULL){
            queue.push_back(s->right);
        }
    }
    printf("\n");

}

void Tree::display(TREE::Tree::Node *root) {
    printf("Deep first: \n");
    deepFistUtil(root);
    printf("\n");

    printf("Breadth first: \n");
    breadthFistUtil(root);

}



Tree::Node* Tree::addNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


/* Binary search tree (BST) */
Tree::Node* Tree::searchBST(TREE::Tree::Node *root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return searchBST(root->left, data);

    return searchBST(root->right, data);

}

Tree::Node* Tree::insertBST(TREE::Tree::Node *root, int data) {
    if (root == NULL)
        root = Tree::addNode(data);

    if (data < root->data)
        root->left = insertBST(root->left, data);
    else if (data > root->data)
        root->right = insertBST(root->right, data);

    return root;

}

Tree::Node* Tree::deleteBST(TREE::Tree::Node *root, int data) {
    Tree::Node *r = new Tree::Node;
    Tree::Node *l = new Tree::Node;

    if (root == NULL)
        return root;

    if (data < root->data)                                  // find from left
        root->left = deleteBST(root->left, data);
    else if (data > root->data)                             // find from right
        root->right = deleteBST(root->right, data);
    else                                                   // found the node!

        if (root->left == NULL and root->right != NULL)
            r->right = root->right;
            // do something to r
        else if (root->left != NULL and root->right == NULL)
            l->left = root->left;
        else if (root->left == NULL and root->right == NULL)
            free(root);
        else
            r->right = root->right;
            l->left = root->left;


}