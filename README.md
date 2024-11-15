# **Indian Railway Train Management System**

## **Overview**

This program allows the management of railway stations, lines, and train scheduling, where users can add stations, lines, and trains to the stations and validate train timings based on constraints. The program includes options for:

- **Adding stations**.
- **Adding lines to stations**.
- **Adding trains to specific lines at specific times**.
- **Validating train times**.

## **Building the Program**

To build and compile the program, follow the instructions below.

### **Requirements**

- A C++ compiler (e.g., `g++`).
- **Make** utility for building the project.

### **Compilation Steps**

1. **Navigate to the project directory**: Go to the directory where the source files are located (e.g., `main.cpp`, `Station.cpp`, `Platform.cpp`, `Line.cpp`).

2. **Build the program using `make`**: In the terminal or command prompt, run the following command:

   ```bash
   cd ./MT24119
   make
This will compile the source files and link them into the executable main_shared.exe (or similar). It will also generate a shared library (librailway.so) and a static library (librailway.a).

3. **Running the program**: After successful compilation, you can run the program by executing:
   ```bash
   ./main_shared.exe

### **Makefile Overview**
- Makefile provided in the project handles the compilation and linking process. It defines the build commands for shared libraries (`librailway.so`), static libraries (`librailway.a`), and the final executable (`main_shared.exe`).

- It compiles all `.cpp` files into object files and links them together to create the required output.


## **Input File Format**
The program doesn't require external input files by default. Instead, all input is provided interactively through the command-line interface (CLI). However, the structure of user input must follow the specified format.

### **Interactive User Inputs**
1. **Station ID**: When adding a station, you will be prompted to enter a station ID in string format.
   
2. **Line ID**: When adding a line to a station, you will be asked to provide the Line ID.
   
3. **Number of Lines**: When adding lines to a station, you will be prompted for the number of lines you want to add (up to a specified maximum).

4. **Train Time**: When adding a train, the program will prompt you to enter the train time in the `hh:mm AM/PM` format.
   
5. **Train Type**: You will also be asked to specify whether the train is a "`Through`" or "`Stopping`" train. Enter either `1` for Through or `2` for Stopping.
   
## Output Example
Here’s an example of how the program will interact with you during execution:

```
Main Menu:
1. Add Station
2. Add Line to Station
3. Add Train
4. Exit
Enter your choice: 1
Enter Station ID: s1
Station s1 added.

Main Menu:
1. Add Station
2. Add Line to Station
3. Add Train
4. Exit
Enter your choice: 2
Enter Station ID to add lines: s1
Enter number of lines to add: 2
Enter Line ID for line 1: l1
Line l1 added to Station s1.
Enter Line ID for line 2: l2
Line l2 added to Station s1.

Main Menu:
1. Add Station
2. Add Line to Station
3. Add Train
4. Exit
Enter your choice: 3
Enter Station ID: s1
Enter Line ID: l1
Enter train time (in hh:mm AM/PM format): 10:30 AM
Enter Train Type (1 for Through, 2 for Stopping): 1
Train time validated.
Train at 10:30 AM added successfully.

Main Menu:
1. Add Station
2. Add Line to Station
3. Add Train
4. Exit
Enter your choice: 3
Enter Station ID: s1
Enter Line ID: l1
Enter train time (in hh:mm AM/PM format): 10:35 AM
Enter Train Type (1 for Through, 2 for Stopping): 1
Train time validated.
Train at 10:35 AM added.

Main Menu:
1. Add Station
2. Add Line to Station
3. Add Train
4. Exit
Enter your choice: 4
Exiting program. Goodbye!
```
## **Test User Program**

- Run the `test_program.exe` by executing:
   ```bash
   ./test_program.exe

- **Output**

```bash
  === Railway Library Test Program ===
Testing valid data...
Adding Station STN001...
Station STN001 added successfully.
Adding 2 lines to Station STN001...
Line L1 added to Station STN001.
Line L2 added to Station STN001.
Adding trains to Line L1...
Train time validated.
Train at 10:30 AM added.
terminate called after throwing an instance of 'std::invalid_argument'
  what():  Train timing violates constraints. Conflict with existing train at 10:30 AM (Through)
```


## **Notes** ##
- `Input Validation`: All user inputs are validated to ensure that the station ID, line ID, train time, and train type follow the correct format. If an invalid input is entered (e.g., entering letters instead of numbers or incorrect time format), the program will prompt the user to re-enter the correct value.

- `Memory Management`: The program dynamically allocates memory for stations and lines, which is properly cleaned up before the program exits.