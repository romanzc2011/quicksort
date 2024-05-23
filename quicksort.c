#include <stdio.h>
#include <stdlib.h>

void swap(int a[], int pos1, int pos2);
void printArray(int a[], int length);
int partition(int a[], int low, int upper);
void quickSort(int a[], int low, int upper);
int N;

int main(int argc, char *argv[])
{
    int pivot_index;
    if(argc != 9)
    {
        fprintf(stderr, "usage: %s 1 2 3 4 5 6 7 8\n", argv[0]);
        return 1;
    }

    // VARIABLES
    N = argc-1;
    int i;
    int a[N];
    
    // Create array from args ###################################################
    // Put args into an array
    for(i=0; i < N; i++)
    {
        a[i] = atoi(argv[i+1]);
    }

    // Perform quicksort
    quickSort(a, 0, N-1);
    printArray(a, N);    

    return 0;
}

// ##############################################################################
// FUNCTIONS
// ##############################################################################
void printArray(int a[], int length)
{
    int i;
    for(i=0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// swap function, swap pos1 and pos2
void swap(int a[], int pos1, int pos2)
{
    int temp;
    temp = a[pos1];
    a[pos1] = a[pos2];
    a[pos2] = temp;
}

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int pivot_index = start - 1;
    
    for(int i=start; i < end; i++)
    {
        if(a[i] <= pivot)
        {
            pivot_index++;
            swap(a, pivot_index, i);
        }
    }

    swap(a, pivot_index+1, end);
    pivot_index++;

    return pivot_index;
}

void quickSort(int a[], int low, int upper)
{
    int middle;

    if(low < upper)
    {
        middle = partition(a, low, upper);
        quickSort(a, 0, middle-1);
        quickSort(a, middle+1, upper);
    }

}
