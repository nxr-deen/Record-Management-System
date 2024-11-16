# Record-Management-System
# Simple Record Management System

This is a simple C program that allows users to manage records stored in a binary file. It provides basic operations such as initializing the file, adding records, searching for records, deleting records, and displaying records in various ways.

---

## Features
1. **Initialize File**: Creates or resets the file to an empty state.
2. **Insert Record**: Adds a new record with a unique ID, name, and age.
3. **Search Record**: Searches for a record by its unique ID.
4. **Delete Record**: Marks a record as deleted by overwriting it with empty values.
5. **Show All Records**: Displays all non-deleted records.
6. **Raw File Content Display**: Displays all records, including empty (deleted) ones, for debugging purposes.

---

## File Format
Each record is stored in binary format with the following structure:
```c
typedef struct {
    int id;          // Unique identifier
    char name[50];   // Name of the person
    int age;         // Age of the person
} Record;
