#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
// Structure to represent a node in linked list
struct Node {
    int data;
    struct Node *next;
};

// Declare head node as global variable
struct Node *head = NULL;

// Function prototypes
void beginsert(int item);
void lastinsert ();  
void randominsert();  
void begin_delete();  
void last_delete();  
void random_delete();  
void display();  
void search();  
void reverse();  
void sort();
int size(); 
void MinMax();

void ClearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    printf("\nPress Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

int main()
{
    int choice = 0;
    while(choice>=0)
    {
        ClearScreen(); // Clear the screen at the start of the loop
        printf("Linked List Operations\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a random position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from a random position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Min MAX\n");
        printf("10. Reverse\n");
        printf("11. Sort\n");
        printf("12. Size\n");
        printf("13. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        int item,LinkedLen ;
        switch(choice)
        {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&item);
                beginsert(item);
                pause();
                break;
            case 2:
                lastinsert();
                pause();
                break;
            case 3:
                randominsert();
                pause();
                break;
            case 4:
                begin_delete();
                pause();
                break;
            case 5:
                last_delete();
                pause();
                break;
            case 6:
                random_delete();
                pause();
                break;
            case 7:
                display();
                pause();
                break;
            case 8:
                search();
                pause();
                break;
            case 9:
                MinMax();
                pause();
                break;
            case 10:
                reverse();
                pause();
                break;
            case 11:
                sort();
                display();
                pause();
                break;
            case 12:
                printf("The length of the linked list is: %d\n", LinkedLen = size() );
                pause();
                break;
            case 13:
                printf("Thank you for using the program. Goodbye!\n");
                
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                pause();
        }

    }
    return 0;
}

void beginsert(const int item)
{
    struct Node * ptr ;
    
    ptr = (struct Node *)malloc( sizeof(struct Node));
    if(ptr == NULL)
    {
        printf("Error: Unable to allocate memory\n");
        return;
    }

    ptr->data = item;
    ptr->next = head;
    head = ptr;

    printf("Node inserted at the beginning of the list\n");
}

void display() {
    struct Node *ptr = head;

    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("List elements are: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");

}

void lastinsert()
{
    struct Node *ptr, *temp;
    int item;
    
    ptr = (struct Node *)malloc(sizeof(struct Node));
    if(ptr == NULL)
    {
        printf("Error: Unable to allocate memory\n");
        return;
    }
    
    printf("Enter the value to be inserted: ");
    scanf("%d",&item);

    ptr->data = item;
    ptr->next = NULL;

    // empty list
    if(head == NULL)
    {
        head = ptr;
        printf("Node inserted at the end of the list\n");
        return;
    }

    // هنرووح للاخر ونشاور على اخر نقطة عندنا للنقطة اللي لسه ضيفينها
    temp = head ;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = ptr;
    printf("Node inserted at the end of the list\n");

}

void randominsert() {
    struct Node *ptr, *temp;
    int item, position, i;

    printf("Enter the value to be inserted: ");
    scanf("%d", &item);

    printf("Enter the position to insert the node: ");
    scanf("%d", &position);

    if (position < 1 || position > size() + 1) {
        printf("Error: Invalid position. Valid positions are 1 to %d.\n", size() + 1);
        return;
    }

    if (position == 1) {
        beginsert(item);
        return;
    }

    ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Error: Unable to allocate memory\n");
        return;
    }

    ptr->data = item;
    temp = head;

    for (i = 1; i < position - 1; i++) {
        temp = temp->next;
    }

    ptr->next = temp->next;
    temp->next = ptr;

    printf("Node inserted at position %d\n", position);
}


int size()
{
    int count = 0;
    struct Node *temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void begin_delete()
{
    struct Node *temp;
    
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    printf("Node deleted from the beginning of the list: %d\n", temp->data);
    free(temp);   
}

void last_delete()
{
    struct Node *ptr, *prev;
    
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // one node in the list
    if (head->next == NULL) {
        ptr = head;
        head = NULL; // 
        free(ptr);
        printf("The only node in the list was deleted.\n");
        return;
    }
    
    ptr = head;
    while( ptr->next != NULL )
    {
        prev = ptr;
        ptr = ptr->next;
    }

    prev->next= NULL ;

    printf("Node deleted from the end of the list");
    free(ptr); 
}

void random_delete() {
    struct Node *ptr, *prev;
    int position, i, list_size;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter the position to delete the node: ");
    scanf("%d", &position);

    list_size = size();

    if (position < 1 || position > list_size) {
        printf("Error: Invalid position. Valid positions are 1 to %d.\n", list_size);
        return;
    }

    if (position == 1) {
        begin_delete();
        return;
    }

    if (position == list_size) {
        last_delete();
        return;
    }

    ptr = head;
    for (i = 1; i < position; i++) {
        prev = ptr;
        ptr = ptr->next;  
    }

    prev->next = ptr->next;

    printf("Node deleted from position %d: %d\n", position, ptr->data);
    free(ptr);
}

void sort() 
{
    struct Node *ptr, *temp;
    int swap;
    int swapped;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        ptr = head;
        swapped = 0;

        while (ptr->next != NULL) {
            if (ptr->data > ptr->next->data) {
                swap = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = swap;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    } while (swapped);

    printf("List sorted in ascending order\n");
}

void MinMax()
{
    struct Node *ptr = head;
    int min = head->data, max = head->data;
    
    if (ptr == NULL) {
        printf("List is empty\n");
        return;
    }
    
    while (ptr!= NULL) {
        if (ptr->data < min) {
            min = ptr->data;
        }

        if (ptr->data > max) {
            max = ptr->data;
        }

        ptr = ptr->next;
    }

    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
}

void reverse()
{
    struct Node *prev = NULL, *current = head, *next = NULL;
    
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
    printf("List reversed\n");

    display();
}

void search() {
    struct Node *ptr = head;
    int search_item, position = 1, found = 0;

    printf("Enter the value to search: ");
    scanf("%d", &search_item);

    while (ptr != NULL) {
        if (ptr->data == search_item) {
            found = 1;
            printf("Value %d found at position %d\n", search_item, position);
        }
        ptr = ptr->next;
        position++;
    }

    if (!found) {
        printf("Value %d not found in the list\n", search_item);
    }
}

