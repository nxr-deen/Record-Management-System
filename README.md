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

## How to Run

Follow these steps to run the Record Management System on your local machine:

### Step 1: Clone the Repository
### Step 2: Navigate to the Project Directory
### Step 4: Run the Program

## Menu Options
### When you run the program, you will see the following menu:
Choose an option:

1 - Initialize File
2 - Insert Record
3 - Search Record
4 - Delete Record
5 - Show All Records (excluding empty)
6 - Show Raw File Content (affichage)
7 - Exit Enter your choice:


Each option performs a different action within the program:

1. **Initialize File**: Creates or resets the binary file to an empty state.
2. **Insert Record**: Adds a new record with a unique ID, name, and age.
3. **Search Record**: Searches for a record based on the unique ID.
4. **Delete Record**: Marks a record as deleted by overwriting it with an empty record.
5. **Show All Records**: Displays all non-deleted records stored in the file.
6. **Show Raw File Content**: Displays all records, including deleted ones (useful for debugging).
7. **Exit**: Exits the program.


## Use Cases

### 1. Learning File Handling
- Understand how to use file handling (especially binary files) in C to store and manage records.
- Practice basic file operations such as reading, writing, updating, and deleting data.

### 2. CRUD Operations
- Implement basic **Create**, **Read**, **Update**, and **Delete** functionality in a console-based application.
- Gain experience with file-based storage rather than using databases.

### 3. Building Console Applications
- Build simple, interactive C console applications that allow users to perform various actions based on user input.
- Learn how to interact with users through a terminal interface and handle their choices efficiently.

### 4. Debugging with Raw Data
- The "Show Raw File Content" feature can be used to debug or inspect the underlying file contents, even the empty or deleted records.


