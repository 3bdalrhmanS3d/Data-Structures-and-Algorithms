#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room
{
    int roomNumber;
    char status[10];// "Occupied" or "Available"
    char customerName[50];
    char checkInDate[15];
    char checkOutDate[15];
};

struct Array
{
    struct Room *room ;
    int size;
    int length;
};

void SaveToFile(struct Array *arr)
{
    FILE *file = fopen("hotel_data.txt","w") ;
    if( !file )
    {
        printf("Error saving data.\n");
        return;
    }

    fwrite(arr->room, sizeof(struct Room), arr->length, file);
    fclose(file);
    printf("Data saved successfully.\n");
}

void LoadFromFile(struct Array *arr) 
{
    FILE *file = fopen("hotel_data.txt", "r");
    if (!file) 
    {
        printf("No saved data found.\n");
        return;
    }
    arr->length = fread(arr->room, sizeof(struct Room), arr->size, file);
    fclose(file);
    printf("Data loaded successfully.\n");
}

void DisplayRooms(struct Array arr)
{
    printf("Room List:\n");
    for(int i =0; i < arr.length; i++)
    {
        printf("Room %d: %s\n", arr.room[i].roomNumber, arr.room[i].status);
        if (strcmp(arr.room[i].status, "Occupied") == 0) 
        {
            printf("\tCustomer: %s\n", arr.room[i].customerName);
            printf("\tCheck-in: %s\n", arr.room[i].checkInDate);
            printf("\tCheck-out: %s\n", arr.room[i].checkOutDate);
        }
    }
}

int IsRoomNumberUnique(struct Array *arr, int roomNumber) 
{
    for (int i = 0; i < arr->length; i++) 
    {
        if (arr->room[i].roomNumber == roomNumber) 
        {
            return 0; // Not unique
        }
    }
    return 1; // Unique
}

void AddRoom(struct Array *arr, int roomNumber) 
{
    if (!IsRoomNumberUnique(arr, roomNumber)) 
    {
        printf("Room number already exists.\n");
        return;
    }

    if (arr->length == arr->size) 
    {
        arr->size *= 2;
        arr->room = realloc(arr->room, arr->size * sizeof(struct Room));
        if (!arr->room) 
        {
            printf("Memory allocation failed.\n");
            return;
        }
    }
    arr->room[arr->length].roomNumber = roomNumber;
    strcpy(arr->room[arr->length].status, "Available");
    arr->length++;
    printf("Room %d added successfully.\n", roomNumber);
}

void UpdateRoomStatus(struct Array *arr, int roomNumber, const char *status) {
    for (int i = 0; i < arr->length; i++) {
        if (arr->room[i].roomNumber == roomNumber) 
        {
            strcpy(arr->room[i].status, status);

            if (strcmp(status, "Occupied") == 0) 
            {
                printf("Enter customer name: ");
                scanf("%s", arr->room[i].customerName);
                printf("Enter check-in date (DD/MM/YYYY): ");
                scanf("%s", arr->room[i].checkInDate);
                printf("Enter check-out date (DD/MM/YYYY): ");
                scanf("%s", arr->room[i].checkOutDate);
            } 
            else 
            {
                memset(arr->room[i].customerName, 0, sizeof(arr->room[i].customerName));
                memset(arr->room[i].checkInDate, 0, sizeof(arr->room[i].checkInDate));
                memset(arr->room[i].checkOutDate, 0, sizeof(arr->room[i].checkOutDate));
            }

            printf("Room %d status updated to %s.\n", roomNumber, status);
            return;
        }
    }
    printf("Room %d not found.\n", roomNumber);
}

void DeleteRoom(struct Array *arr, int roomNumber) 
{
    for (int i = 0; i < arr->length; i++) 
    {
        if (arr->room[i].roomNumber == roomNumber) 
        {
            for (int j = i; j < arr->length - 1; j++) 
            {
                arr->room[j] = arr->room[j + 1];
            }
            arr->length--;
            printf("Room %d deleted successfully.\n", roomNumber);
            return;
        }
    }
    printf("Room %d not found.\n", roomNumber);
}

void SearchAvailableRooms(struct Array arr) {
    printf("Available Rooms:\n");
    for (int i = 0; i < arr.length; i++) {
        if (strcmp(arr.room[i].status, "Available") == 0) {
            printf("Room %d\n", arr.room[i].roomNumber);
        }
    }
}

void ClearScreen() {
    system("cls"); // Clear screen on Windows
}

int main(int argc, char *argv[])
{
    struct Array hotel;
    hotel.size = 20;
    hotel.length=0;
    hotel.room = (struct Room*)malloc(hotel.size * sizeof(struct Room) );
    
    int choice, roomNumber;
    char status[10];

    while (1) {
        ClearScreen(); // Clear the screen at the start of the loop
        printf("\nHotel Management System\n");
        printf("1. View All Rooms\n");
        printf("2. Add Room\n");
        printf("3. Update Room Status\n");
        printf("4. Delete Room\n");
        printf("5. Search Available Rooms\n");
        printf("6. Save Data\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                DisplayRooms(hotel);
                break;
            case 2:
                printf("Enter room number to add: ");
                scanf("%d", &roomNumber);
                AddRoom(&hotel, roomNumber);
                break;
            case 3:
                printf("Enter room number to update: ");
                scanf("%d", &roomNumber);
                printf("Enter new status (Available/Occupied): ");
                scanf("%s", status);
                UpdateRoomStatus(&hotel, roomNumber, status);
                break;
            case 4:
                printf("Enter room number to delete: ");
                scanf("%d", &roomNumber);
                DeleteRoom(&hotel, roomNumber);
                break;
            case 5:
                SearchAvailableRooms(hotel);
                break;
            case 6:
                SaveToFile(&hotel);
                break;
            case 7:
                SaveToFile(&hotel);
                printf("Exiting program.\n");
                free(hotel.room);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
        printf("\nPress Enter to continue...");
        getchar(); // Capture the newline left by the previous input
        getchar(); // Wait for user to press Enter
    }

    return 0 ;
}