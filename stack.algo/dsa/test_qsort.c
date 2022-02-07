#include <stdio.h>
#include <stdlib.h>

void swap(int v[], int i, int j);

void quicksort(int v[], int left, int right);

int main(int argc, char* argv[])
{
    int sample[] = { 5, 6, 4, 5, 2, 3, 1, 0 };
    int* array = sample;
    int memalloc = 0;
    int N = sizeof(sample) / sizeof(sample[0]);
    if (argc != 1) {
        N = argc - 1;
        array = (int*)malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            array[i] = atoi(argv[i + 1]);
        }
        memalloc = 1;
    }

    for (int i = 0; i < N; i++) {
        fprintf(stdout, "%d\t", array[i]);
    }
    fprintf(stdout, "\n");

    quicksort(array, 0, N - 1);

    if (memalloc) {
        free(array);
    }
    return 0;
}

void swap(int v[], int i, int j)
{
    if (i == j) {
        return;
    }
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void quicksort(int v[], int left, int right)
{
    if (left >= right) {
        return;
    }
    swap(v, left, (left + right) / 2);

    int last = left;
    for (int i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    quicksort(v, left, last - 1);
    quicksort(v, last + 1, right);

    for (int i = left; i <= right; i++) {
        fprintf(stdout, "%d\t", v[i]);
    }
    fprintf(stdout, "\n");
}
