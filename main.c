#include <stdio.h>
#include <stdlib.h>

void GenerateArray(double A[], size_t n);
void ShuffleArray(double A[], size_t n);
void PrintArray(double A[], size_t n);
void CheckIsSorted(double A[], size_t n);

int main(int argc, const char * argv[]) {
    int const numberscount = 1000;
    double arraytosort[numberscount] = {};
    GenerateArray(arraytosort, numberscount);
    PrintArray(arraytosort, numberscount);
    CheckIsSorted(arraytosort, numberscount);
    ShuffleArray(arraytosort, numberscount);
    CheckIsSorted(arraytosort, numberscount);
    
    return 0;
}

void GenerateArray(double A[], size_t n)
{
    double startnumber = 0.01;
    double step = 1.42;
    for (int i = 0; i < n; ++i) {
        double number = startnumber + step*i;
        A[i] = number;
    }
}

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

void PrintArray(double A[], size_t n)
{
    for (int i = 0; i < n; ++i) {
        printf("\n%f, ", A[i]);
    }
}

void CheckIsSorted(double A[], size_t n)
{
    for (int i = 0; i < n; ++i) {
        if(i == n - 1)
        {
            continue;
        }
        if(A[i+1] < A[i])
        {
            printf("Array is not sorted\n");
            return;
        }
    }
    printf("Array is sorted\n");
}


void TopDownMergeSort(double A[], double B[], size_t n)
{
}
