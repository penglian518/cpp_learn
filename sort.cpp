//
// Created by Lian, Peng on 2019-03-03.
//

#include "sort.h"

using namespace std;
using namespace S;

// constructor of the Sort class
Sort::Sort() {
    cout << "\nWelcome to using the Sort module!" << endl;
}

// print array
void Sort::printArray(int arr[], int arrSize){

    for (int i=0; i<arrSize; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}



// merge sort
void Sort::merge(int *arr, int l, int m, int r) {
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // create temp arrays
    int L[n1], R[n2];
    for (i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for (j=0; j<n2; j++){
        R[j] = arr[m+1+j];
    }

    // merge the temp arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] < R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copy the remaining elements in L
    while (i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    // copy the remaining elements in R
    while (j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Sort::mergeSort(int *arr, int l, int r) {
    // sort the elements from l to r in arr (l starts from 0)
    // and rewrite the results to the same section

    if (l<r){
        // find a middle point, r-1 to avoids overflow
        int m = (l+r-1)/2;

        // recursively separate all arr members
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        // merge sorted pieces
        merge(arr, l, m, r);
    }
}



void Sort::swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void Sort::quickSort(int *arr, int low, int high) {
    // sort elements from low to high

    if (low < high){
        // pick the pivot

        int piv = partition(arr, low, high);

        // separately sort before and after elements
        quickSort(arr, low, piv-1);
        quickSort(arr, piv+1, high);

    }
}

int Sort::partition(int *arr, int low, int high) {
    int pivot = arr[high];      // always select high as pivot
    int i = low - 1;            // index of smaller element

    // scan index from low to high-1 (high is the pivot)
    for (int j=low; j<high-1; j++){
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]); // if current element <= pivot, point i to the smaller one (swap i j)
        }
    }

    // after scan, i is the last element in the smaller group,
    // i+1 should be the position for pivot
    // from i+2 to high are elements larger than the pivot
    swap(&arr[i+1], &arr[high]);

    return (i+1);

}