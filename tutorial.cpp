//
// Created by Lian, Peng on 2019-02-27.
//

#include "tutorial.h"  // header in local directory

using namespace T;
using namespace std;


/*
 * 1) Constructor
 *  a. constructor has the same name with the class
 *  b. constructor doesn't have a return type, member function has
 *  c. constructor is automatically called
 *  d. if constructor is missing, compiler will generate it
 *  e. parameterized constructor allows to pass arguments while obj creation
 *
 * 2) Destructor
 *  a. has the same name with class, but with a tilde sign (~) in front.
 *  b. only one in the class
 *  c. do not allow parameters
 *  d. no return type
 */

// constructor of Tutorial class
Tutorial::Tutorial() {
    cout << "welcome to the tutorial class!" << endl;
}

void Tutorial::showBasic() {
    /* 1) declaring variables
     *
     * data_type v1=xx, v2=xx;
     *      or
     * data_type v1, v2;
     * v1 = xx;
     * v2 = xx;
     *
     *
     * 2) Data types
     *      Built in data types:
     *          int, char, bool, double, float
     *      User-defined data types:
     *          struct, union, enum
     *      Derived data types:
     *          Array, Function; Pointer
     *
     * 3) Operators
     *      + - * / % = += -= /= %= ++ --
     *      && || ! == != > < >= <=
     *
     * 4) Six bitwise operators:
     *      & compare bits, equal -> 1, else -> 0
     *      | compare bits, either bit is 1 -> 1, else ->0
     *      ^ compare bits, not equal ->1, else ->0
     *      ~ change bits, 1 -> 0, 0 -> 1
     *      << shift bits to left, remove left most and add 0 at the end
     *      >> shift bits to right, remove the end bit and add 0 at the left
     *
     * 5) Ternary operator:
     *      variable num1 = (expression) ? v1 : v2
     *      if the expression result is true, num1 = v1, else num1 = v2
     *
     */
    int num1=20, num2 = 90;
    float num3 = 20.3;      // single precision, 4 bytes
    //double num4 = 20.909; // double precision, 8 bytes
    cout << "num1 + num3 = " << (num1+num3) << endl;

    bool a = true;
    bool b = false;
    cout << "a||b: " << (a||b) << endl;

    int num5 = 11; // 11 = 00001011
    int num6 = 22; // 22 = 00010110
    cout << "num5 & num6: " << (num5 & num6) << endl;
    cout << "num5 | num6: " << (num5 | num6) << endl;
    cout << "num5 ^ num6: " << (num5 ^ num6) << endl;
    cout << "~num5 : " << (~num5) << endl;
    cout << "num5 << 2 : " << (num5 << 2) << endl;
    cout << "num5 >> 2 : " << (num5 >> 2) << endl;


    cout << "num1: " << num1 << "; num2: " << num2 << endl;
    int num7 = (num1 < num2) ? 100 : 200;
    cout << "num7: " << num7 << endl;
    num7 = (num1 > num2) ? 100 : 200;
    cout << "num7: " << num7 << endl;


    /*
     * 6) if statement
     *   a. if (conditions) {
     *          ...
     *      };
     *
     *   b. if (conditions) {
     *          ...
     *      } else {
     *          ...
     *      };
     *
     *   c. if (condition 1) {
     *          ...
     *      } else if (condition 2) {
     *          ...
     *      } else {
     *          ...
     *      };
     *
     *  7) switch (variable or integer expression) {
     *      case constant:
     *          ...
     *          break;
     *      case constant:
     *          ...
     *          break;
     *      default:
     *          ...
     *  };
     */

    if (num1 > num2) {
        cout << "num1 > num2" << endl;
    } else if (num1 == num2) {
        cout << "numb1 == num2 " << endl;
    } else {
        cout << "numb1 < num2 " << endl;
    };


    int i = 2;
    switch (i+1) {
        case 1: cout << "Case 1" << endl; break;
        case 2: cout << "Case 2" << endl; break;
        case 3: cout << "Case 3" << endl; break;
        case 4: cout << "Case 4" << endl; break;
        default: cout << "Default " << endl;
    };


    /*
     * 8) loop
     *    a. for loop
     *       for (init; condition; increment/decrement) {
     *          ...
     *       }
     *       NOTE: It's possible to omit any or all the expressions, but should keep the ";"!
     *
     *    b. while loop
     *       init;
     *       while (condition) {
     *            ...
     *            increment/decrement
     *       }
     *
     *    c. do while loop
     *       do {
     *          ...
     *       } while (condition);
     *
     *    d. continue/break
     *
     *    e. goto (don't use this one)
     *
     *    f. range based for loop
     *      for (range_declaration : range_expression) loop_statement
     *
     */

    /* 10) Multidimensional arrary
    *   int arr[2][3];    // 2*3 elements, 2 rows, 3 columns
    */

    // declear an array, with/without array size are OK.
    int arr[] = {21, 9, 10, 99, 201};
    //int arr[5] = {21, 9, 10, 99, 201};

    //int marr[2][3] = {10, 11, 12, 13, 14, 15};
    int marr[2][3] = {{10, 11, 12}, {13, 14, 15}}; // both ways work

    // vector
    cout << "\n...............Test for std::vector...............\n";

    display prt;                                            // use homemade func to show the variables

    std::vector<int> v1;
    std::vector<int> v2 = {1,2,3,4};                        // init vector

    cout << "The original v2 is: " << endl;
    //for (auto const &i : v2) cout << i << " ";              // iterate with range based for loop
    //cout << endl;
    prt.show(v2);

    //int head = v2.front();                                  // 1st element
    //int tail = v2.back();                                   // last element

    v2.insert(v2.begin(), 0);                               // insert to head
    v2.insert(v2.begin()+3, 7);                             // insert to 4th position
    v2.push_back(8);                                        // insert to back
    cout << "After insert at begin and push back: " << endl;
    //for (auto const &i : v2) cout << i << " ";              // iterate with range based for loop
    //cout << endl;
    prt.show(v2);

    v2.erase(v2.begin()+3);                                 // erase 4th element
    v2.pop_back();                                          // erase last element
    //for (std::vector<int>::iterator it = v2.begin(); it != v2.end(); it++){ // iterate with iterator
    //    cout << *it << " ";
    //}
    //cout << endl;
    prt.show(v2);


    v2[1] = 3;
    v2[4] = 2;                                              // vector not automatically resize!
    cout << "The length of v2 is: " << v2.size() << endl;
    cout << "The capacity of v2 is: " << v2.capacity() << endl;
    //for (auto const &i: v2)
    //    cout << i << " ";
    //cout << endl;
    prt.show(v2);

    v2.resize(10);                                           // resize by hand, resize will add 0s
    v2[4] = 2;
    cout << "The length of v2 is: " << v2.size() << endl;
    cout << "The capacity of v2 is: " << v2.capacity() << endl;
    //for (auto const &i: v2)
    //    cout << i << " ";
    //cout << endl;
    prt.show(v2);

    // Deque (Double end queue)
    cout << "\n...............Test for std::deque...............\n";
    std::deque<int> d = {1,2,3,4};
    d.push_front(0);                                         //similar to vector, but has push_front
    d.push_front(1);                                         // and pop_front
    d.pop_front();
    d.insert(d.begin()+3, 9);
    //for (auto const &i : d) cout << i << " ";
    //cout << endl;
    prt.show(d);


    // list
    cout << "\n...............Test for std::list...............\n";
    std::list<int> l = {1,3,3,3,2,4};
    std::list<int> l2 = {9,7,8,5,3,2,1, 11};
    l.push_front(0);                                        // insert head
    //l.insert(l.begin()+3, 8);                               // insert to 4th
    l.push_back(9);                                         // intert to tail
    prt.show(l);
    l.erase(l.begin());
    //l.splice(l.begin(), l2);
    //cout << "after splice:\n";
    //prt.show(l);
    l.remove(9);
    cout << "after remove 9:\n";
    prt.show(l);
    l.merge(l2);
    cout << "after merge l2:\n";
    prt.show(l);
    l.sort();
    cout << "after sort:\n";
    prt.show(l);
    l.unique();                                             //unique doesn't work, when after merge??
    cout << "after unique:\n";
    prt.show(l);
    l.reverse();
    cout << "after reverse:\n";
    prt.show(l);

    // map
    cout << "\n...............Test for std::map...............\n";
    std::map<string, string> m;
    m.insert(pair<string, string>("key1", "value1"));       // insert string pair to map
    m["k2"] = "v2";
    string value = m.at("key1");                            // get the values of key1
    cout << "the value at key1 is: " << value << endl;
    prt.show(m);
    m.erase("key1");                                        // erase key1, value1
    prt.show(m);
    bool exists = (m.find("key1") != m.end());              // find if an element exist
    cout << exists << endl;


    // set
    cout << "\n...............Test for std::set...............\n";
    std::set<int> s = {1,3,3,3,2,4};
    s.insert(20);                                        // insert
    prt.show(s);

    s.erase(3);
    prt.show(s);
    exists = (s.find(21) != s.end());
    cout << "21 is in s? " << exists << endl;

    // stack    First-in Last-out !
    cout << "\n...............Test for std::stack...............\n";
    std::stack<int> st;
    st.push(19);                                        // insert
    st.push(20);                                        // insert
    st.push(21);                                        // insert
    st.pop();                                           // pop the last one

    cout << "The size of the stack is: " << st.size() << endl;
    cout << "The top of the stack is: " << st.top() << endl;

    // queue    First-in First-out!
    cout << "\n...............Test for std::queue...............\n";
    std::queue<int> q;
    q.push(19);                                        // insert
    q.push(20);                                        // insert
    q.push(21);                                        // insert
    q.pop();                                           // pop the first one

    cout << "The size of the queue is: " << q.size() << endl;
    cout << "The head of the queue is: " << q.front() << endl;
    cout << "The tail of the queue is: " << q.back() << endl;


    cout << "\n...............Test for loops...............\n";
    cout << "for loop" << endl;
    for (int i=0; i<5; i++) {
        cout << arr[i] << endl;
    };

    cout << "while loop" << endl;
    i = 0;
    while (i < 5) {
        cout << arr[i] << endl;
        i += 1;
    }

    cout << "do while loop" << endl;
    i = 0;
    do {
        cout << arr[i] << endl;
        i += 1;
    } while (i < 3);
    cout << "What if you print something not in the array?" << endl;
    cout << arr[6] << endl;

    cout << "nested for loop to show elements in a 2D array" << endl;
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            cout << "marr["<<i<<"]["<<j<<"]:" <<marr[i][j]<<endl;
        }
    }


    // String object
    string str = "This is a string";
    str.push_back('!');
    cout << "init string: " << str << endl;
    cout << "String with PUSH back (!):" << str << endl;
    str.pop_back();
    cout << "String with POP back (!):" << str << endl;


    /* 11) Pointer
    *   data_type *pointer_name, var; // declear
    *   *pointer_name = &var;         // assign the address of var to the pointer
    *
    *   Pointer is much useful when combine with array.
    */
    int *p, var=101;
    p = &var;   // if var is an array, just use p = var;
    cout << "Address of var: " << &var << endl;
    cout << "Address of var: " << p << endl;
    cout << "Address of p: " << &p << endl;
    cout << "Value of p: " << *p << endl;

    // Traversing the array using pointers
    int *pa;
    int arr1[5] = {1,2,3,4,5};
    pa = arr1; // assignment the address of the array to the pointer.
    for (int i=0; i<5; i++) {
        cout << "arr1[" <<i<< "] = " << *pa << endl;
        pa++;
    };

}





// constructor of class Demo
Demo::Demo(int num, char ch1){
    cout << "This is the constructor of Demo" << endl;
    this->num = 1;
    this->ch1 = 'B';
}

// member funcs in class Demo
void Demo::setMyValues(int num, char ch1) {
    this->num = num;
    this->ch1 = ch1;
}

// member funcs in class Demo
void Demo::displayValues() {
    cout << "Num: " << num << endl;
    cout << "Char: " << ch1 << endl;
}

// destructor of class Demo
Demo::~Demo() {
    cout << "This is the destructor of Demo" << endl;

}





// constructor of Math
Math::Math() {
    cout << "Welcome to use the Math module!" << endl;
}

float Math::ADD(float num1, float num2){
    return num1 + num2;
}

float Math::ADD(float num1, float num2, float num3) {
    return num1 + num2 + num3;
}


Math1::Math1(){
    cout << "Welcome to use the Math1 module!" << endl;
}

float Math1::MULTIPLY(float num1, float num2) {
    return num1 * num2;
}

float Math1::SUM(float num1, float num2, float num3) {
    return num1 + num2 + num3;
}






// a function to assign value to the structure
RGB T::setRGB(short r, short g, short b) {
    RGB s;
    s.r = r;
    s.g = g;
    s.b = b;
    return s;
}
// a function to print the structure
void T::printRGB(RGB s1){
cout << "printRGB: " << s1.r << " " << s1.g << " " << s1.b << endl;
};





// constructor of display
display::display(){
}

void display::show(std::vector<int> l){
    for (auto const i : l) cout << i << " ";
    cout << endl;
}

void display::show(std::deque<int> l){
    for (auto const i : l) cout << i << " ";
    cout << endl;
}

void display::show(std::list<int> l){
    for (auto const i : l) cout << i << " ";
    cout << endl;
}

void display::show(std::map<std::string, std::string> l){
    //for (auto const i : l) cout << i << " ";
    for (std::map<string, string>::iterator it = l.begin(); it != l.end(); it++ ){
        cout << it->first << " : " << it->second << endl;
    }
}

void display::show(std::set<int> l){
    for (auto const i : l) cout << i << " ";
    cout << endl;
}





// for eight queens problem
eightQ::eightQ(){
    // constructor
}

bool eightQ::testSolution(int col[8], int row[8]){
    // given a solution, test it is validate or not
    int results[8] = {};

    for (int i=0; i<8; i++){
        int c = col[i];
        int r = row[i];

        // check against other queens
        int check[8] = {};
        for (int j=0; j<8; j++){
            if (j!=i){
                if (c==col[j]||r==row[j]||abs(c-col[j])==abs(r-row[j])){
                    check[j] = 0;
                    break;
                } else {
                    check[j] = 1;
                }
            }
        }

        // sum the results
        int Rc=0;
        for (auto i: check) Rc+=i;

        // if no confict with others, this queen is ok.
        if (Rc==7){
            results[i] = 1;
        } else {
            results[i] = 0;
        }
    }


    // sum the results
    int R=0;
    for (int i=0; i<8; i++){
        R += results[i];
    }

    // if all queens are no confictions, this solution is ok.
    if (R==8){
        return true;
    } else {
        return false;
    }
}

void eightQ::findSolutions(){
    // init the columns
    for (int i=0; i<8; i++){
        this->COL[i] = i;
    }

    printf("All the solutions for 8 Queens problem are:\n");
    int counter = 0;

    // generate all the possible solutions.
    for (int i0=0; i0<8; i0++){
        for (int i1=0; i1<8; i1++){
            for (int i2=0; i2<8; i2++){
                for (int i3=0; i3<8; i3++){
                    for (int i4=0; i4<8; i4++){
                        for (int i5=0; i5<8; i5++){
                            for (int i6=0; i6<8; i6++){
                                for (int i7=0; i7<8; i7++){
                                    this->ROW[0] = i0;
                                    this->ROW[1] = i1;
                                    this->ROW[2] = i2;
                                    this->ROW[3] = i3;
                                    this->ROW[4] = i4;
                                    this->ROW[5] = i5;
                                    this->ROW[6] = i6;
                                    this->ROW[7] = i7;

                                    if (this->testSolution(this->COL, this->ROW)){
                                        printf("%d, %d,%d,%d,%d,%d,%d,%d,%d\n", counter, ROW[0],ROW[1],ROW[2],ROW[3],ROW[4],ROW[5],ROW[6],ROW[7]);
                                        counter +=1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


void eightQ::findSolutionsPermutation() {
    // init the columns and rows
    for (int i=0; i<8; i++){
        this->COL[i] = i;
        this->ROW[i] = i;
    }

    printf("All the solutions for 8 Queens problem are:\n");
    int counter = 0;

    // sort first 8 elements of ROW;
    sort(this->ROW, this->ROW+8);

    // enumerate all the possible permutations of ROW;
    do {
        if(this->testSolution(this->COL, this->ROW)){
            printf("%d, %d,%d,%d,%d,%d,%d,%d,%d\n", counter, ROW[0],ROW[1],ROW[2],ROW[3],ROW[4],ROW[5],ROW[6],ROW[7]);
            counter +=1;
        }
    } while (next_permutation(this->ROW, this->ROW+8));


}





