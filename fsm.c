/*****************************************************
# fsm.c - A C program to verify messages using a a protocol for reading messages from any device.
#
# Kavin Parakh, kkp56
# November 2022
#
# gcc 9.4.0
# on GNU/Linux 5.13.0-28-generic x86_64
#***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/* Purpose - Function to valid if the message is follows aldo's protocols.
   Requires - An array of characters 
   Ensures -  Returns a boolean value (True or False) based on the validation */
bool aldo(char input[]) {
    if (input[0] != 'A' || !isdigit(input[1]) || input[strlen(input) - 1] != 'F') {
        return false;
    }
    for(int i = 1; i < strlen(input) - 1; i++) {
        if ((isdigit(input[i]))) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

/* Purpose - Function to valid if the message is follows bar's protocols.
   Requires - An array of characters 
   Ensures -  Returns a boolean value (True or False) based on the validation */    
bool bar(char input[]) {
    if (input[0] != 'B') {
        return false;
    }
    if(strlen(input) <= 3) {
        if ((strcmp(input, "B") == 0) || (strcmp(input, "BHG") == 0)) {
            return true;
        }
	return false;
    }
    else {
        for(int i = 1; i < strlen(input) - 2; i+=3) {
            if (input[strlen(input) - 2] != 'H') {
                return false;
            }
            if (input[strlen(input) - 1] != 'G') {
                return false;
            }
            else if ((input[i] != 'H' || input[i + 1] != 'G' || input[i + 2] != 'X')) {
                return false;
            }
        }
    }
    return true;
}

/* Purpose - Function to valid if the message is follows calma's protocols.
   Requires - An array of characters 
   Ensures -  Returns a boolean value (True or False) based on the validation */  
bool calma(char input[]) {
    if (input[0] != 'C') {
        return false;
    }
    int num_Ts = 0;
    for(int i = 1; i < strlen(input); i++) {
        if (input[i] == 'R' || input[i] == 'T') {
            if (input[i] == 'T') {
                num_Ts += 1;
            }
        }
        else {
            return false;
        }
    }
    if (num_Ts % 2 != 0) {
        return false;
    }
    return true;
}
 
/* Purpose - Function to valid if the message is follows dol's protocols.
   Requires - An array of characters 
   Ensures -  Returns a boolean value (True or False) based on the validation */   
bool dol(char input[]) {
    if (input[0] != 'D') {
        return false;
    }
    if (isdigit(input[1])) {
        if (aldo(input + 3) || calma(input + 3)) {
            return true;
        }
        return false;
    }
    return false;
}

//Main Function
int main(int argc, char *argv[]) {
    FILE *ptr;
    if (argc <= 1) {
        ptr = stdin;
    }
    else {
        ptr = fopen(argv[1], "r");
    }
    if (ptr == NULL) {
        printf("Invalid File name. Try Again.\n");
        exit;
    }
    char line[1024];
    while (fscanf(ptr, "%s", line) == 1) {
        if(line[0] == 'A') {
            if (aldo(line) == true) {
                printf("%s OK\n", line);
            }
            else {
                printf("%s FAIL\n", line); 
            }
        }
        else if(line[0] == 'B') {
            if (bar(line) == true) {
                printf("%s OK\n", line);
            }
            else {
                printf("%s FAIL\n", line); 
            }
        }
        else if(line[0] == 'C') {
            if (calma(line) == true) {
                printf("%s OK\n", line);
            }
            else {
                printf("%s FAIL\n", line); 
            }
        }
        else if(line[0] == 'D') {
            if (dol(line) == true) {
                printf("%s OK\n", line);
            }
            else {
                printf("%s FAIL\n", line); 
            }
        }
        else {
            printf("Invalid Command. Try Again\n");
        }
    }
}
