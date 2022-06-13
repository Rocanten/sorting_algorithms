/*
 To use this app for large arrays, you should increase stack size in your compiler flags
 */

#include <stdio.h>
#include <stdlib.h>

void GenerateArray(double A[], size_t n);
void ShuffleArray(double A[], size_t n);
void PrintArray(double A[], size_t n);
void CheckIsSorted(double A[], size_t n);
void MergeSort(double A[], size_t l, size_t r);
void Merge(double A[], size_t l, size_t m, size_t r);

int main(int argc, const char * argv[]) {
    int const numberscount = 1000;
    static double arraytosort[numberscount] = {};
    GenerateArray(arraytosort, numberscount);
    //PrintArray(arraytosort, numberscount);
    CheckIsSorted(arraytosort, numberscount);
    ShuffleArray(arraytosort, numberscount);
    //PrintArray(arraytosort, numberscount);
    CheckIsSorted(arraytosort, numberscount);
    MergeSort(arraytosort, 0, numberscount-1);
    CheckIsSorted(arraytosort, numberscount);
    //PrintArray(arraytosort, numberscount);
    return 0;
}

// Fills array with some double numbers
void GenerateArray(double A[], size_t n)
{
    double startnumber = 0.01;
    double step = 1.42;
    for (int i = 0; i < n; ++i) {
        double number = startnumber + step*i;
        A[i] = number;
    }
}

// Shuffles array to get random sort
void ShuffleArray(double A[], size_t n)
{
    if(n > 1)
    {
        for (size_t i = 0; i < n; i++) {
            size_t j = ((double)rand() / RAND_MAX) * n;
            double t = A[j];
            A[j] = A[i];
            A[i] = t;
        }
    }
}

// Prints array
void PrintArray(double A[], size_t n)
{
    for (int i = 0; i < n; ++i) {
        printf("\n%f, ", A[i]);
    }
}

// Checks if an array is sorted and prints a message if it is sorted or not
void CheckIsSorted(double A[], size_t n)
{
    for (int i = 0; i < n; ++i) {
        if(i == n - 1)
        {
            continue;
        }
        if(A[i+1] < A[i])
        {
            printf("\nArray is not sorted\n");
            return;
        }
    }
    printf("\nArray is sorted\n");
}

// Merge sort function, is called with recursion
void MergeSort(double A[], size_t l, size_t r)
{
    if(l < r)
    {
        size_t m = l + (r - l) / 2;
        MergeSort(A, l, m);
        MergeSort(A, m + 1, r);
        Merge(A, l, m, r);
        
    }
    
}

// Merge function which compares splited numbers and writes them to final array
void Merge(double A[], size_t l, size_t m, size_t r)
{
    // Calculating number of elements of left array
    size_t n1 = m - l + 1;
    // Calculating number of elements of right array
    size_t n2 = r - m;
    
    size_t i;
    size_t j;
    // First element to fill in final array is the left point
    size_t k = l;
    
    // Creating subarrays
    double L[n1];
    double R[n2];
    
    // Filling left subarray with elements
    for (i = 0; i < n1; i++) {
        L[i] = A[l + i];
    }
    
    // Filling right subarray with elements
    for (j = 0; j < n2; j++) {
        R[j] = A[m + 1 + j];
    }
    
    i = 0;
    j = 0;
    // Comparing numbers and filling final array
    while (i < n1 && j < n2) {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        } else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Filling the rest elements if there are any
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}
