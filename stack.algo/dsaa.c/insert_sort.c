#include <stdio.h>
#include <stdlib.h>

void insert_sort(int arr[], int N);
void print_array(int arr[], int N);

int main()
{
    int arr[] = {5,2,4,6,1,3};
    int N = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, N);
    insert_sort(arr, N);
    print_array(arr, N);
    return 0;
}

void insert_sort(int arr[], int N)
{
    for (int j = 1; j < N; ++j)
    {
        int i = j - 1;
        int key = arr[j];
        while (i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            --i;
        }
        arr[i+1] = key;
    }
}

void print_array(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

