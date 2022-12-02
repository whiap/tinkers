#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int p, int q, int r);
void merge_sort(int arr[], int p, int r);
void print_array(int arr[], int N);

int main()
{
    int arr[] = {0,0,0,5,2,4,7,1,3,2,6,0,0,0};
    int N = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, N);
    merge_sort(arr, 3, 10);
    print_array(arr, N);
    return 0;
}

// merge sorted array for arr[p..q], arr[q+1..r]
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int n0 = n1 + n2;
    int L[n1];
    int R[n2];
    for (int i = 0; i < n1; ++i)
    {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; ++j)
    {
        R[j] = arr[q + 1 + j];
    }
    int k = 0, i = 0, j = 0;
    while (k < n0)
    {
        if ((i < n1) && (j < n2))
        {
            if (L[i] < R[j])
            {
                arr[p + k] = L[i];
                ++i;
            }
            else 
            {
                arr[p + k] = R[j];
                ++j;
            }
        }
        else if (i >= n1)
        {
            arr[p + k] = R[j];
            ++j;
        }
        else if (j >= n2)
        {
            arr[p + k] = L[i];
            ++i;
        }
        ++k;
    }
}

void merge_sort(int arr[], int p, int r)
{
    if (p >= r)
    {
        return;
    }
    int q = (p + r) / 2;
    merge_sort(arr, p, q);
    merge_sort(arr, q + 1, r);
    merge(arr, p, q, r);
}

void print_array(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

