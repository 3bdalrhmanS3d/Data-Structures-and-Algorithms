#include <stdio.h>
#include <stdlib.h>

int main(int argc , char *argv[])
{
    int **p; // Pointer to a pointer (2D array)
    int i, j;
    p = (int **)malloc( 3 * sizeof(int *)); // allocate memory for 3 pointers
    for (i = 0; i < 3; i++)
    {
        p[i] = (int *)malloc(4 * sizeof(int)); // allocate memory for 4 integers
    }

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 4; j++)
        {
            p[i][j] =i * 4 + j; // sequential numbers
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", p[i][j] );
        }
        printf("\n");
    } 

    // Free the memory
    for (i = 0; i < 3; ++i) {
        free(p[i]); // Free each row
    }
    free(p); // Free the array of pointers

    return 0 ;
}