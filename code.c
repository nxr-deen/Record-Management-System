#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "file.txt"
#define RECORD_SIZE sizeof(Record)

typedef struct {
    int id;          // Unique identifier for search
    char name[50];   // Name of the person
    int age;         // Age of the person
} Record;

void init_tnof() {
    FILE *file = fopen(FILENAME, "wb"); // Open file for writing in binary mode
    if (!file) {
        perror("Unable to create file");
        return;
    }
    fclose(file);
    printf("File initialized successfully.\n");
}

void insert_tnof() {
    FILE *file = fopen(FILENAME, "ab"); // Open file in append mode
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Record record;
    printf("Enter ID: ");
    scanf("%d", &record.id);
    printf("Enter Name: ");
    scanf("%s", record.name);
    printf("Enter Age: ");
    scanf("%d", &record.age);

    fwrite(&record, RECORD_SIZE, 1, file);
    fclose(file);
    printf("Record inserted successfully.\n");
}

void search_tnof() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);

    Record record;
    while (fread(&record, RECORD_SIZE, 1, file) == 1) {
        if (record.id == id) {
            printf("Record found - ID: %d, Name: %s, Age: %d\n", record.id, record.name, record.age);
            fclose(file);
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
    fclose(file);
}

void delete_tnof() {
    FILE *file = fopen(FILENAME, "rb+");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);

    Record record;
    while (fread(&record, RECORD_SIZE, 1, file) == 1) {
        if (record.id == id) {
            fseek(file, -RECORD_SIZE, SEEK_CUR); // Move file pointer to start of the record
            Record emptyRecord = {0, "", 0};    // Empty record to overwrite the deleted record
            fwrite(&emptyRecord, RECORD_SIZE, 1, file);
            fclose(file);
            printf("Record with ID %d deleted successfully.\n", id);
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
    fclose(file);
}

void show_all_tnof() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\nAll Records (excluding empty):\n");
    Record record;
    int found = 0;

    while (fread(&record, RECORD_SIZE, 1, file) == 1) {
        if (record.id != 0) { // Display only non-empty records
            printf("ID: %d, Name: %s, Age: %d\n", record.id, record.name, record.age);
            found = 1;
        }
    }

    if (!found) {
        printf("No records found.\n");
    }

    fclose(file);
}

void affichage_tnof() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    printf("\nRaw File Content (including empty records):\n");
    Record record;

    while (fread(&record, RECORD_SIZE, 1, file) == 1) {
        printf("ID: %d, Name: %s, Age: %d\n", record.id, record.name, record.age);
    }

    fclose(file);
}

void display_menu() {
    printf("\nChoose an option:\n");
    printf("1. Initialize File\n");
    printf("2. Insert Record\n");
    printf("3. Search Record\n");
    printf("4. Delete Record\n");
    printf("5. Show All Records (excluding empty)\n");
    printf("6. Show Raw File Content (affichage)\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            init_tnof();
            break;
        case 2:
            insert_tnof();
            break;
        case 3:
            search_tnof();
            break;
        case 4:
            delete_tnof();
            break;
        case 5:
            show_all_tnof();
            break;
        case 6:
            affichage_tnof();
            break;
        case 7:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
