/*
 To use this app for large arrays, you should increase stack size in your compiler flags
 */

#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"
#include "quick_sort.h"

void GenerateArray(double A[], size_t n);
void ShuffleArray(double A[], size_t n);
void PrintArray(double A[], size_t n);
void CheckIsSorted(double A[], size_t n);

void TestMergeSort(double A[], size_t n);
void TestQuickSort(double A[], size_t n);

int main(int argc, const char * argv[]) {
    int const numberscount = 1000;
    double arraytosort[1000];

    TestMergeSort(arraytosort, numberscount);
    TestQuickSort(arraytosort, numberscount);

    return 0;
}

void TestMergeSort(double A[], size_t n)
{
    printf("Testing Merge sort algorithm...\n");
	GenerateArray(A, n);
	CheckIsSorted(A, n);
	ShuffleArray(A, n);
	CheckIsSorted(A, n);
	MergeSort(A, 0, n - 1);
	CheckIsSorted(A, n);
}

void TestQuickSort(double A[], size_t n)
{
    printf("Testing Quick sort algorithm...\n");
	GenerateArray(A, n);
	CheckIsSorted(A, n);
	ShuffleArray(A, n);
	CheckIsSorted(A, n);
    QuickSort(A, 0, n-1);
	CheckIsSorted(A, n);
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
