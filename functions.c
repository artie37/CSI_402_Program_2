// functions.c
// Arthur Knapp
// ID: AK146316

// This file contains functions for converting a text file
// to a binary file and a binary file to a text file.

// functions:
// textToBinary: Converts a text file to a binary file. The text file will contain
// a string up to 225 characters followed by a tab and an integer. The binary file
// will contain the length of the string, the string and the integer.

// binaryToText: Converts the binary file to a text file. This function will read from the
// binary file the string size, the string and the integer and write the string and the integer
// to the text file. The converted text file will be identical to the original text file.

// binaryStats: Prints various statistics about the binary file. This function will loop
// through the binary file and find the string of maximum and minimum length, and will find
// the maximum and minimum number. Next, the function will print the maximum and minimum string
// and, the maximum and minimum number.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "externs.h"
#include "constants.h"

void textToBinary(FILE *inFile, FILE *outFile)
{
    unsigned char string[STRING_SIZE];
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
        // Insert length of the string to unsigned char
        fwrite(&strLength, sizeof(strLength), 1, outFile);
        // Write the length of the string to the binary file
        fwrite(&string, (int)strLength, 1, outFile);
        // Write string to binary file
        fwrite(&num, sizeof(num), 1, outFile);
        // Write int to binary file
    }
}

void binaryToText(FILE *inFile, FILE *outFile)
{
    unsigned char string[STRING_SIZE];
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
        // Read char string length from binary file and store it in char
        // 'strLength'. Return 0 if there is nothing to read.
        
        if (size == 0)
        // If size == 0, there is nothing more to read.
        // Break out of loop to avoid printing the last string
        // and int twice.
        {
            break;
        }
        
        for (i = 0; i < (STRING_SIZE); i++)
        // For loop to clear all characters out of the
        // char array. Loop runs for values 0 - 255
        {
            string[i] = '\0';
            // Insert null character into current array index
        }
        
        fread(&string, (int)strLength, 1, inFile);
        // Read string from binary file and store it in char array 'string'
        
        string[NULL_INDEX] = '\0';
        // Insert terminating character at the end of the char array
        
        fread(&num, sizeof(num), 1, inFile);
        // Read int from file and store it in 'num'.
        
        fprintf(outFile, "%s\t%lu\n", string, num);
        // Write the string and the int to the text file.
    }
}

void binaryStats(FILE *inFile)
{
    unsigned char string[STRING_SIZE];
    // Initialize character array to hold string from file
    unsigned char maxString[STRING_SIZE];
    // Initialize character array to hold string from file
    unsigned char minString[STRING_SIZE];
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
    int maxSize = 0;
    // Initialize int variable for max string
    int minSize;
    // Initialize int variable for min size
    unsigned int maxNum = 0;
    // Initialize int variable for max number
    unsigned int minNum;
    // Initialize int variable for min number
    int strFlag = 0;
    // Initialize int variable for min string flag
    int numFlag = 0;
    // Initialize int variable for min num flag
    
    while (size != 0)
        // While loop to loop through binary file. If size of
        // what was read is 0, end loop.
    {
        size = fread(&strLength, sizeof(strLength), 1, inFile);
        // Read char string length from binary file and store it in char
        // 'strLength'. Return 0 if there is nothing to read.
        
        if (size == 0)
        // If size == 0, there is nothing more to read.
        // Break out of loop to avoid printing the last string
        // and int twice.
        {
            break;
        }
        
        for (i = 0; i < (STRING_SIZE); i++)
        // For loop to clear all characters out of the
        // char array. Loop runs for values 0 - 255
        {
            string[i] = '\0';
            // Insert null character into current array index
        }
        
        fread(&string, (int)strLength, 1, inFile);
        // Read string from binary file and store it in char array 'string'
        
        string[NULL_INDEX] = '\0';
        // Insert terminating character at the end of the char array
        
        fread(&num, sizeof(num), 1, inFile);
        // Read int from file and store it in 'num'.
        
        if (((int)strLength) >= maxSize)
        // Runs if the current strings length is greater than
        // the max string size.
        {
            strcpy(maxString, (char *)string);
            // Copies the max string into a char array that prints the max string
            maxSize = (int)strLength;
            // Insert the size of the current string into maxSize
            
            if (strFlag == 0)
            // Runs if the current string is the first string.
            // Puts the current string size into minSize to test minSize.
            {
                minSize = maxSize;
                // Insert current size into minSize
                strFlag = 1;
                // Set flag to 1
            }
        }
        
        if (((int)strLength) <= minSize)
        // Runs if the current strings length is less than
        // the min string size.
        {
            strcpy(minString, (char *)string);
            // Copies the min string into a char array that prints the min string
            minSize = (int)strLength;
            // Insert the size of teh current string into minSize
        }
        
        if (((int)num) >= maxNum)
        // Runs if the current number is greater than the max number
        {
            maxNum = (int)num;
            // Insert current number into maxNum
            
            if (numFlag == 0)
            // Runs if the current number is the first number.
            // Puts the current number size into minNum to test minNum.
            {
                minNum = maxNum;
                // Insert current number into minNum
                numFlag = 1;
                // Set flag to 1
            }
        }
        
        if (((int)num) <= minNum)
        // Runs if the current number is less than the min number.
        {
            minNum = (int)num;
            // Insert the current number into min number.
        }
    }
    
    printf("Max String: %s\n", maxString); fflush(stdout);
    // Prints max string
    printf("Min String: %s\n", minString); fflush(stdout);
    // Prints min string
    printf("Max Number: %lu\n", maxNum); fflush(stdout);
    // Prints max number
    printf("Min Number: %lu\n", minNum); fflush(stdout);
    // Prints min number
}