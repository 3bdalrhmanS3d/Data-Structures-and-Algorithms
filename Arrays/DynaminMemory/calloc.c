#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int n ;

    printf("Enter the number of elements: \n");
    
    scanf("%d",&n);
    
    ptr = (int*)calloc(n,sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory not allocated\n");
        exit(1);
    }
    
    printf("Memory successfully allocated using calloc\n");
    for(int i = 0 ; i < n ; i++)
    {
        ptr[i] = i+1;
    }

    printf("The elements of the array are: ");
    
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",ptr[i]);
    }
    printf("\n");
    free(ptr);

    
    return 0;
}