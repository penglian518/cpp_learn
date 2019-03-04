//
// Created by Lian, Peng on 2019-02-27.
//

/*
 * https://beginnersbook.com/2017/08/c-plus-plus-tutorial-for-beginners/
 */

#ifndef CPP_LEARN_OPP_CLASS_H
#define CPP_LEARN_OPP_CLASS_H

#include <iostream>     // header in standard library
#include <cmath>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>


namespace T {
    // show tutorial
    class Tutorial{
    public:
        // constructor
        Tutorial();
        void showBasic();
    };


    // class Demo
    class Demo {
    private:
        int num;
        char ch1;
    public:
        // constructor of Demo
        Demo(int num=0, char ch1='A');

        // member functions
        void setMyValues(int num, char ch1);
        void displayValues();
        int getNum(){ return num;};
        char getChar(){ return ch1;};

        // destructor of Demo
        ~Demo();
    };

    // class Math
    class Math {
    private:
        float num1;
        float num2;
        float num3;

    public:
        // constructor
        Math();
        // member func
        float ADD (float num1, float num2);             // ADD func
        float ADD (float num1, float num2, float num3); // polymorphism of ADD func, both 2 or 3 numbers will work.

        friend class Math1;                             // friend allows class Math1 to access to the private data

    };


    // Math1 is a class that inheritance from Math
    class Math1 : public Math {

    public:
        // constructor
        Math1();
        // member function
        float MULTIPLY (float num1, float num2);
        float SUM(float num1, float num2, float num3);

    };


    // structure
    struct RGB {
        short r{0};
        short g{0};
        short b{0};
    };

    // a function to assign value to the structure
    RGB setRGB(short r, short g, short b);
    // a function to print the structure
    void printRGB(RGB s1);

    // enumeration
    enum direction {East, West, North, South};


    class display{
    public:
        display();
        void show(std::vector<int> l);
        void show(std::deque<int> l);
        void show(std::list<int> l);
        void show(std::map<std::string, std::string> l);
        void show(std::set<int> l);
    };




    // for eight queens problem
    class eightQ{
    private:
        int COL[8] = {};
        int ROW[8] = {};
    public:
        eightQ();   // constructor
        bool testSolution(int col[8], int row[8]);
        void findSolutions();
        void findSolutionsPermutation();

    };




}
#endif //CPP_LEARN_OPP_CLASS_H
