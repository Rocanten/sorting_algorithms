#include "quick_sort.h"

int	 Partition(double A[], int low, int high);
void Swap(double* a, double* b);

void QuickSort(double A[], int low, int high)
{
	if (low < high)
	{
		int pi = Partition(A, low, high);
		QuickSort(A, low, pi - 1);
		QuickSort(A, pi + 1, high);
	}
}

int Partition(double A[], int low, int high)
{
	double pivot = A[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (A[j] < pivot)
		{
			i++;
			Swap(&A[i], &A[j]);
		}
	}
	Swap(&A[i + 1], &A[high]);
	return (i + 1);
}

void Swap(double* a, double* b)
{
	size_t t = *a;
	*a = *b;
	*b = t;
}