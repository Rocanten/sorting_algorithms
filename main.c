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
            printf("\nArray is not sorted\n");
            return;
        }
    }
    printf("\nArray is sorted\n");
}


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

void Merge(double A[], size_t l, size_t m, size_t r)
{
    size_t n1 = m - l + 1;
    size_t n2 = r - m;
    
    size_t i;
    size_t j;
    size_t k = l;
    
    double L[n1];
    double R[n2];
    
    for (i = 0; i < n1; i++) {
        L[i] = A[l + i];
    }
    
    for (j = 0; j < n2; j++) {
        R[j] = A[m + 1 + j];
    }
    
    i = 0;
    j = 0;
    
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
