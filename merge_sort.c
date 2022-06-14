#include "merge_sort.h"

void Merge(double A[], size_t l, size_t m, size_t r);


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
    double* L = malloc(n1 * sizeof(double));
    double* R = malloc(n1 * sizeof(double));
    
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
