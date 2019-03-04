//
// Created by Lian, Peng on 2019-03-03.
//

#ifndef CPP_LEARN_SORT_H
#define CPP_LEARN_SORT_H

#include <iostream>

namespace S{
    class Sort {
    public:
        Sort();             //constructor

        void printArray(int arr[], int arrSize);

        // merge sort
        void mergeSort(int arr[], int l, int r);
        void merge(int arr[], int l, int m, int r);

        // quicke sort
        void swap(int *a, int *b);
        void quickSort(int arr[], int low, int high);
        int partition(int arr[], int low, int high);
    };

}



#endif //CPP_LEARN_SORT_H
