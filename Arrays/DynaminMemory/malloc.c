#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Dynamic memory allocation using malloc

    /* 
        malloc() function is used to allocate memory at runtime. 
        Syntax: void *malloc(size_t size);
        It allocates the memory block of the given size 
        and returns a pointer of type void which can be casted 
        into pointer of any form.

        If allocation fails, it returns NULL.
    */

   /*
        Free() function is used to deallocate the memory.
        Syntax: void free(void *ptr);
        Deallocates the memory previously allocated by malloc, calloc, or realloc.

        It does not change the value of the pointer, that is it still points to the same memory location.
   */

    int *p , *q;
    int i;
    p = (int *)malloc( 5 * sizeof(int)) ; // 5 * 4 bytes = 20 bytes
    p[0] = 1, p[1] = 3, p[2] = 5, p[3] = 7, p[4] = 9;
    q = (int *)malloc(10 * sizeof(int)); // 10 * 4 bytes = 40 bytes
    for (i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    printf("Elements of q array\n");
    for( i=0 ; i < 5 ; i++)
    {
        printf("%d\n", q[i] );
    }
    printf("\n");

    free(p); // deallocate the memory
    p = q ; // p points to q
    q = NULL; 
    printf("Elements of p array\n");
    for( i=0 ; i < 5 ; i++)
    {
        printf("%d\n", p[i] );
    }
    printf("\n");

    return 0;
}