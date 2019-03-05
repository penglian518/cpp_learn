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


// quick sort
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


// bubble sort
void Sort::bubbleSort(int *arr, int n) {
    for (int i=0; i<n-1; i++){                  // can be i<n
        for (int j=0; j<n-i-1; j++){            // can be j<n-1
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}


// insertion sort
void Sort::insertionSort(int *arr, int n) {
    for (int i=1; i<n; i++){
        int key = arr[i];                       // pick out the ith element
        int j = i - 1;                          // init j to be the left one of the ith element

        // in the left part of arr, if any element smaller than key, shift it to right by 1
        while (j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;                         // put back the ith element
    }

}



// heap sort
void Sort::heapSort(int *arr, int n) {
    // build heap
    for (int i = n/2-1; i>=0; i--){
        heapify(arr, n, i);
    }

    // one by one extract an element from the heap
    for (int i=n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);             // move current root to end
        heapify(arr, i, 0);                 // call max heapify on the reduced heap
    }
}

void Sort::heapify(int *arr, int n, int i) {
    int largest = i;                        // init the largest
    int l = 2*i + 1;                        // left = 2*i + 1
    int r = 2*i + 2;                        // right = 2*i + 2

    // if left child is larger, mark it as root
    if (l < n && arr[l] > arr[largest]){
        largest = l;
    }

    // if the right child is larger than largest so far, mark it as root
    if (r < n && arr[r] > arr[largest]){
        largest= r;
    }

    // if the root is changed, swap the root with the largest one
    if (largest != i){
        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);
    }

}



// interpolation search
int Sort::interpolationSearch(int *arr, int n, int x){

    int lo = 0, hi = n-1;

    // search from lo to hi
    while (lo <= hi && x >= arr[lo] && x<= arr[hi]){

        // terminate the searching
        if (lo == hi) {
            if (arr[lo] == x){
                return lo;
            } else {
                return -1;
            }
        }

        // calculate the next searching position
        int pos = lo + ((hi - lo)/(arr[hi]-arr[lo])) * (arr[x] - arr[lo]);

        // check if found the x
        if (arr[pos] == x){
            return pos;
        }

        // shrink the searching range
        if (arr[pos] < x){
            lo = pos + 1;
        } else {
            hi = pos - 1;
        }
    }

    return -1;          // found nothing
}


