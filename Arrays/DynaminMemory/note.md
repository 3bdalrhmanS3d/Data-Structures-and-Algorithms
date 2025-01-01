# C malloc() method

    memory allocation
    used to dynamically allocate a single large block of memory with the specified size. 
    It returns a pointer of type void 
    which can be cast into a pointer of any form. 
    It doesn’t Initialize memory at execution time 
    so that it has initialized each block with the default garbage value initially. 

    Syntax : 
    ptr = ( cast_type* ) malloc( byte-size ) ;

    as  ptr = (int*) malloc(100 * sizeof(int) );
    same 
    naming the type directly
    int *ptr1 = malloc( sizeof(int[100])) ;

    same 
    without repeating the type name
    int *ptr2 = malloc( 100 * sizeof *ptr2 ) ;

    If space is insufficient, allocation fails and returns a NULL pointer.

    ```
    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {

        // This pointer will hold the
        // base address of the block created
        int* ptr;
        int n, i;

        // Get the number of elements for the array
        printf("Enter number of elements:");
        scanf("%d",&n);
        printf("Entered number of elements: %d\n", n);

        // Dynamically allocate memory using malloc()
        ptr = (int*)malloc(n * sizeof(int));

        // Check if the memory has been successfully
        // allocated by malloc or not
        if (ptr == NULL) {
            printf("Memory not allocated.\n");
            exit(0);
        }
        else {

            // Memory has been successfully allocated
            printf("Memory successfully allocated using malloc.\n");

            // Get the elements of the array
            for (i = 0; i < n; ++i) {
                ptr[i] = i + 1;
            }

            // Print the elements of the array
            printf("The elements of the array are: ");
            for (i = 0; i < n; ++i) {
                printf("%d, ", ptr[i]);
            }
        }

        return 0;
    }
    ```

# calloc()

    contiguous (متجاور) allocation 
    allocate the specified number of blocks of memory of the specified type

    very much similar to malloc() but has two different points and these are:
        It initializes each block with a default value ‘0’.
        It has two parameters or arguments as compare to malloc().

    ptr = (cast_type *) calloc ( n , element-size ) ;
        here, n is the no. of elements and element-size is the size of each element.

    as 
        ptr = (int *) calloc(5 , sizeof(int)) ;
        5 blocks of 4 Bytes each is dynamically allocated to ptr 

    If space is insufficient, allocation fails and returns a NULL pointer.

# Free()

    de-allocate the memory. 
    helps to reduce wastage of memory by freeing it.

    Syntax :
        free(ptr) ;

    ```
    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {

        // This pointer will hold the
        // base address of the block created
        int *ptr, *ptr1;
        int n, i;

        // Get the number of elements for the array
        n = 5;
        printf("Enter number of elements: %d\n", n);

        // Dynamically allocate memory using malloc()
        ptr = (int*)malloc(n * sizeof(int));

        // Dynamically allocate memory using calloc()
        ptr1 = (int*)calloc(n, sizeof(int));

        // Check if the memory has been successfully
        // allocated by malloc or not
        if (ptr == NULL || ptr1 == NULL) {
            printf("Memory not allocated.\n");
            exit(0);
        }
        else {

            // Memory has been successfully allocated
            printf("Memory successfully allocated using malloc.\n");

            // Free the memory
            free(ptr);
            printf("Malloc Memory successfully freed.\n");

            // Memory has been successfully allocated
            printf("\nMemory successfully allocated using calloc.\n");

            // Free the memory
            free(ptr1);
            printf("Calloc Memory successfully freed.\n");
        }

        return 0;
    }
    ```

# realloc()
    re-allocation
    change the memory allocation of a previously allocated memory.

    Syntax : 
            ptr = realloc(ptr, newSize);
 
    
# for solve
 
    https://www.examveda.com/c-program/practice-mcq-question-on-memory-allocation/