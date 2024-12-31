
# FSM Protocol Validation Program

## Overview
This repository contains a C program designed to validate messages using predefined protocols (Aldo, Bar, Calma, Dol). The program reads messages from an input file or standard input and determines whether the messages adhere to the respective protocol rules. Each message is processed and validated against its specified protocol, and the results are displayed as either `OK` or `FAIL`.

## Features
- **Protocol Validation**: Supports multiple protocols (Aldo, Bar, Calma, Dol).
- **Flexible Input**: Reads input from files or standard input.
- **User Feedback**: Provides clear validation results for each message.

## Supported Protocols
1. **Aldo**:
   - Starts with `A`.
   - Followed by digits.
   - Ends with `F`.
2. **Bar**:
   - Starts with `B`.
   - Optionally followed by specific patterns such as `B`, `BHG`, or repeating groups `HGX` ending with `HG`.
3. **Calma**:
   - Starts with `C`.
   - Contains only `R` and `T`.
   - The number of `T` characters must be even.
4. **Dol**:
   - Starts with `D`.
   - Followed by a digit.
   - The rest of the message must conform to Aldo or Calma protocols.

## Usage

### Compilation
The program can be compiled using GCC:
```bash
gcc -o fsm fsm.c
```

### Running the Program
#### Input via File
Provide a file containing messages as an argument:
```bash
./fsm input.txt
```
#### Input via Standard Input
Run the program without arguments to read messages from standard input:
```bash
./fsm
```
Enter messages one per line and press `Ctrl+D` (Linux/Mac) or `Ctrl+Z` (Windows) to terminate input.

### Example Input File
```txt
A123F
BHG
CHTTR
D1A456F
```

### Example Output
```txt
A123F OK
BHG OK
CHTTR FAIL
D1A456F OK
```

## Code Structure
- **`aldo`**: Validates messages following Aldo's protocol.
- **`bar`**: Validates messages following Bar's protocol.
- **`calma`**: Validates messages following Calma's protocol.
- **`dol`**: Validates messages following Dol's protocol.
- **`main`**: Reads input and determines the appropriate protocol function for validation.

## Requirements
- GCC 9.4.0 or higher.
- Linux or similar environment.

## Limitations
- Assumes valid inputs for protocols.
- Error handling for unexpected inputs is basic (e.g., invalid commands).

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

## Author
Kavin Parakh  
Drexel University  
November 2022
