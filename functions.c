// functions.c
// Arthur Knapp
// ID: AK146316

// This file contains functions for converting a text file
// to a binary file and a binary file to a text file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "externs.h"

void textToBinary(FILE *inFile, FILE *outFile)
{
    unsigned char string[255];
    // Initialize character array to hold string from file
    unsigned char strLength;
    // Initialize char variable for the size of the string
    unsigned int num;
    // Initialize int variable to store the number from the file
    
    while (fscanf(inFile, "%s %d", string, &num) == 2)
    // Loop through file while there is a string and
    // an int on a line. Store string and int to be
    // writen to binary file.
    {
        strLength = (unsigned char)strlen(string);
        fwrite(&strLength, sizeof(strLength), 1, outFile);
        fwrite(&string, (int)strLength, 1, outFile);
        // Write string to binary file
        fwrite(&num, sizeof(num), 1, outFile);
        // Write int to binary file
    }
}

void binaryToText(FILE *inFile, FILE *outFile)
{
    unsigned char string[256];
    // Initialize character array to hold string from file
    unsigned int num;
    // Initialize int variable to store the number from the file
    unsigned char strLength;
    // Initialize char variable for the size of the string
    unsigned long size = 1;
    // Initialize long variable to store the size of was read
    // from the file. Set to 1 to enter while loop.
    int i;
    // Initialize int variable to use a loop counter
    
    while (size != 0)
    // While loop to loop through binary file. If size of
    // what was read is 0, end loop.
    {
        size = fread(&strLength, sizeof(strLength), 1, inFile);
        // Read char string size from binary file and store it in char
        // 'strLength'. Return 0 if there is nothing to read.
        
        if (size == 0)
        // If size == 0, there are no more strings to be read.
        // Break out of loop to avoid printing the last string
        // and int twice.
        {
            break;
        }
        
        for (i = 0; i <= 255; i++)
        {
            string[i] = '\0';
        }
        fread(&string, (int)strLength, 1, inFile);
        // Read string from binary file and store it in char array 'string'
        
        string[255] = '\0';
        // Insert terminating character at the end of the char array
        
        fread(&num, sizeof(num), 1, inFile);
        // Read int from file and store it in 'num'.
        
        fprintf(outFile, "%s\t%d\n", string, num);
        // Write the string and the int to the text file.
    }
}

void binaryStats(FILE *inFile, FILE *outFile)
{
    unsigned char string[255];
    // Initialize character array to hold string from file
    unsigned int num;
    // Initialize int variable to store the number from the file
    unsigned long size = 1;
    // Initialize long variable to store the size of was read
    // from the file. Set to 1 to enter while loop.
    int stringLength;
    
    while (size != 0)
        // While loop to loop through binary file. If size of
        // what was read is 0, end loop.
    {
        size = fread(&string, sizeof(string), 1, inFile);
        // Read string from binary file and store it in char array
        // 'string'. Return 0 if there is nothing to read.
        
        if (size == 0)
            // If size == 0, there are no more strings to be read.
            // Break out of loop to avoid printing the last string
            // and int twice.
        {
            break;
        }
        
        string[254] = '\0';
        // Insert terminating character at the end of the char array
        
        fread(&num, sizeof(num), 1, inFile);
        // Read int from file and store it in 'num'.
        
        printf("%s\t%d\n", string, num);
        // Write the string and the int to the text file.
    }
}