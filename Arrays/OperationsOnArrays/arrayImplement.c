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
    }
    arr->length--;
}

void Append(struct Array *arr, int x)
{
    if(arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
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

    Display(arr);
    //Insert_array(&arr, 1, 10);
    //Delete(&arr, 1);
    //Append(&arr, 44);
    Display(arr);
    
    free(arr.A);
    return 0 ;
}