#include "tutorial.h"
#include "sort.h"
#include "linkedlist.h"
#include "graph.h"
#include "tree.h"

// namespace
using namespace T;
using namespace S;
using namespace L;
using namespace G;
using namespace TREE;
using namespace std;


// global variables
char gVar = 'A';


char myFunc(char gVar = 'B') {
    //char gVar = 'B';
    return gVar;
}


/*
 * 9) functions
 *      return_type function_name (parameters) {
 *          ...
 *      }
 *
 *      if defining func before main(), no need to do declaration;
 *      if defining after main(), have to declare the function first!
 */
// Declearing the function sum
int sum(int, int);

// Factorial function for testing recursive function
int factorial(int n){
    if (n<=1){
        return 1;
    } else {
        return n * factorial(n-1);
    }
}


// the main function. 'int' means it will return an integer. That's why should return 0 at the end.
int main() {
    std::cout << "Hello, World!" << std::endl;

    // Global variables
    cout << "Display me!"; // cout - an object belongs to iostream, which displays the content between double quotes.
    cout << "Global variables: " << gVar << endl;
    char gVar = 'Z';
    cout << "Changed global variables: " << gVar << endl;
    cout << "Changed global variables by functions: " << myFunc('C') << endl << endl;

    // call self defined functions
    cout << "Sum of int (2,5): " << sum(2, 5) << endl;
    cout << "Call functions in cmath pow(2,10): " << pow(2, 10) << endl << endl;

    // recursive function
    int num1 = -789;
    int num2;
    //cout << "Enter a number: ";
    //cin >> num2;
    num2 = 5;
    cout << "Factorial of entered number: " << factorial(num2) << endl << endl;



    /*
     * 12) class
     */
    Tutorial tut;
    tut.showBasic();


    Demo obj;                           //init the obj with class Demo
    obj.displayValues();
    obj.setMyValues(23, 'A');
    obj.displayValues();
    cout << obj.getNum() << endl;
    cout << obj.getChar() << endl;


    Math1 calc;
    cout << "The add up of " << num1 << " and " << num2 << " is: " << calc.ADD(num1, num2) << endl;
    cout << "The times of " << num1 << " and " << num2 << " is: " << calc.MULTIPLY(num1, num2) << endl;
    cout << "The sum of " << num1 << " and " << num2 << " and 23 is: " << calc.SUM(num1, num2, 23) << endl;

    RGB s1, s2;
    s1.r = 20;
    s1.g = 100;
    cout << "Struct s1: " << s1.r << " " << s1.g << " " << s1.b << endl;

    RGB s3 = setRGB(11, 32, 34);
    printRGB(s2);
    printRGB(s3);

    // enumeration
    direction dir;
    dir = South;
    cout << "The direction is: " << dir << "\n";
    printf("The direction is: %s, %d\n\n", "a", num1);


    // eight queens problem
    eightQ obj2;
    //obj2.findSolutions();                 // traversal all the possible solutions, time consuming!
    //obj2.findSolutionsPermutation();      // consider all permutations with columns and rows


    // Sorts functions
    Sort mySort;
    // merge sort
    int arr[9] = {2,3,6,4,1,0,9,10,-1};
    printf("Initial array: \n");
    mySort.printArray(arr, sizeof(arr)/sizeof(arr[0]));
    mySort.mergeSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    printf("After merge sort from 0 to n-1: \n");
    mySort.printArray(arr, sizeof(arr)/sizeof(arr[0]));

    // quick sort
    int arr1[9] = {2,3,6,4,1,0,9,10,-1};
    mySort.quickSort(arr1, 0, sizeof(arr1)/sizeof(arr1[0])-1);
    printf("After quick sort from 0 to n-1: \n");
    mySort.printArray(arr1, sizeof(arr1)/sizeof(arr1[0]));

    // bubble sort
    int arr2[9] = {2,3,6,4,1,0,9,10,-1};
    mySort.bubbleSort(arr2, sizeof(arr2)/sizeof(arr2[0]));
    printf("After bubble sort from 0 to n-1: \n");
    mySort.printArray(arr2, sizeof(arr2)/sizeof(arr2[0]));

    // insertion sort
    int arr3[9] = {2,3,6,4,1,0,9,10,-1};
    mySort.insertionSort(arr3, sizeof(arr3)/sizeof(arr3[0]));
    printf("After insertion sort from 0 to n-1: \n");
    mySort.printArray(arr3, sizeof(arr3)/sizeof(arr3[0]));

    // heap sort
    int arr4[9] = {2,3,6,4,1,0,9,10,-1};
    mySort.heapSort(arr4, sizeof(arr4)/sizeof(arr4[0]));
    printf("After heap sort from 0 to n-1: \n");
    mySort.printArray(arr4, sizeof(arr4)/sizeof(arr4[0]));

    // interpolation search
    int idx = mySort.interpolationSearch(arr4, sizeof(arr4)/sizeof(arr4[0]), 6);
    printf("Found 6 at %d from the upper sorted list.\n", idx);



    /* Linked list */
    // create object
    linkedlist l;

    // create a list
    l.createNode(5);
    l.createNode(10);
    l.createNode(7);
    l.createNode(3);
    l.createNode(4);
    l.createNode(6);
    l.createNode(9);
    l.createNode(11);

    // test the function
    printf("The list is: \n");l.display();
    l.insert_start(2);
    printf("Insert at start: \n");l.display();
    l.insert_position(2, 1);
    printf("Insert after position 2: \n");l.display();
    l.delete_start();
    printf("Delete the 1st node: \n");l.display();
    l.delete_end();
    printf("Delete the last node: \n");l.display();
    l.delete_position(4);
    printf("Delete the middle node (4th): \n");l.display();
    printf("The length of the list: %d\n", l.length());


    /* Graph */
    // init the graph
    Graph g(4);
    // add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // display the graph
    g.showGraph();
    // list breadth fist traversal, start from 2
    g.BFS(2);
    g.DFS(2);

    /* Tree */
    Tree t;
    // build a tree
    Tree::Node *root = t.addNode(10);                       //                10
    root->left = t.addNode(2);                              //            2       10
    root->right = t.addNode(10);                            //         20   1         -25
    root->left->left = t.addNode(20);                       //                       3    4
    root->left->right = t.addNode(1);
    root->right->right = t.addNode(-25);
    root->right->right->left = t.addNode(3);
    root->right->right->right = t.addNode(4);
    // display a tree
    t.display(root);
    // find all deepth
    printf("Deepth for all nodes:\n");
    t.allDepth(root);
    // find min deepth
    printf("The min deepth is %d.\n", t.minDepth(root));
    // find the max path sum
    printf("The max path sum is: %d. SHOULD be 42!!!\n", t.maxPathSum(root));
    // tree is full BST or not
    t.isFullBST(root) ? printf("IS full BST.\n"):printf("Is NOT full BST.\n");

    // arrary can be represented as BST
    //int arr5[] = {40, 30, 35, 80, 100};
    int arr5[] = {40, 30, 35, 20, 80, 100};
    printf("The init arr is: \n");
    for (auto i : arr5) {
        printf("%d ", i);
    }
    printf("\n");
    t.canRepresentBST(arr5, sizeof(arr5)/sizeof(arr5[0])) ? printf("True!\n"):printf("False!\n");


    // build a BST tree
    Tree::Node *root1 = t.addNode(8);                        //                 8
    root1->left = t.addNode(3);                              //            3       10
    root1->right = t.addNode(10);                            //         1    6         14
    root1->left->left = t.addNode(1);                        //             4  7     13
    root1->left->right = t.addNode(6);
    root1->left->right->left = t.addNode(4);
    root1->left->right->right = t.addNode(7);
    root1->right->right = t.addNode(14);
    root1->right->right->left = t.addNode(13);
    t.display(root1);                   // display a tree

    Tree::Node *tn;
    tn = t.searchBST(root1, 7);
    printf("Found node %d from BST tree.\n", tn->data);
    tn = t.insertBST(root1, 9);
    printf("After insert 9:\n");
    t.display(root1);                   // display a tree
    tn = t.deleteBST(root1,9);
    printf("After delete 9:\n");
    t.display(root1);                   // display a tree


    return 0; // 0 successful, 1 failed
}


// Defining the function sum
int sum(int num1, int num2) {
    return num1 + num2;
}

