#include "tutorial.h"
#include "sort.h"
#include "linkedlist.h"

// namespace
using namespace T;
using namespace S;
using namespace L;
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
    int arr[9] = {2,3,6,4,1,0,9,10,-1};
    printf("Initial array: \n");
    mySort.printArray(arr, sizeof(arr)/sizeof(arr[0]));
    mySort.mergeSort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
    printf("After merge sort from 0 to n-1: \n");
    mySort.printArray(arr, sizeof(arr)/sizeof(arr[0]));

    int arr1[9] = {2,3,6,4,1,0,9,10,-1};
    printf("Initial array: \n");
    mySort.printArray(arr1, sizeof(arr1)/sizeof(arr1[0]));
    mySort.quickSort(arr1, 0, sizeof(arr1)/sizeof(arr1[0])-1);
    printf("After quick sort from 0 to n-1: \n");
    mySort.printArray(arr1, sizeof(arr1)/sizeof(arr1[0]));


    // Linked list
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





    return 0; // 0 successful, 1 failed
}


// Defining the function sum
int sum(int num1, int num2) {
    return num1 + num2;
}

