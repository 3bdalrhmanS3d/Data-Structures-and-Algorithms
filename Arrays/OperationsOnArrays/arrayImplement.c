#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    int i;
    
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void Insert_array(struct Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
    else
    {
        printf("Insertion failed: Invalid index.\n");
    }
}

void Delete(struct Array *arr, int index)
{
    int x = 0;
    int i = 0;

    if(index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for(i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
    else
    {
        printf("Deletion failed: Invalid index.\n");
    }
}

void Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(struct Array *arr)
{
    int temp ;
    for(int i =0 ; i < arr->length - 1 ; i++)
    {
        for(int j = 0 ; j < arr->length - 1 - i ; j++)
        {
            if(arr->A[j] > arr->A[j+1])
            {
                Swap(&arr->A[j], &arr->A[j+1]);
            }
        }
    }
}

void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
    else
    {
        arr->size *= 2;
        arr->A = (int *)realloc(arr->A, arr->size * sizeof(int));
        if (arr->A == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        arr->A[arr->length++] = x;
    }
}

int Compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void SortArray(struct Array *arr)
{
    /*
        How qsort works:
        arr->A: Pointer to the array.
        arr->length: Number of elements in the array.
        sizeof(int): Size of each element.
        Compare: Function that compares two elements and determines their order.
    */

    qsort(arr->A, arr->length, sizeof(int), Compare);
}

int main(int argc , char *argv[])
{
    struct Array arr;
    arr.size = 20;
    arr.length = 5;
    arr.A = (int *)malloc(arr.size * sizeof(int));
    
    for(int i = 0; i < 5; i++)
    {
        arr.A[i] = i + 1;
    }
    int choice, index, value;
    
    while(1)
    {
        printf("1. Display\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Bubble Sort\n");
        printf("5. Append\n");
        printf("6. Sort\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Array elements: ");
                Display(arr);
                break;
            case 2:
                printf("Enter the index and value: ");
                scanf("%d %d", &index, &value);
                Insert_array(&arr, index, value);
                break;
            case 3:
                printf("Enter the index: ");
                scanf("%d", &index);
                Delete(&arr, index);
                break;
            case 4:
                BubbleSort(&arr);
                break;
            case 5:
                printf("Enter the value: ");
                scanf("%d", &value);
                Append(&arr, value);
                break;
            case 6:
                SortArray(&arr);
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                
        }
    }
    free(arr.A);
    return 0 ;
}