// main.c
// Arthur Knapp
// AK146316

// This is a program that will convert text from a formated file into a binary
// file and vice versa. Each line of the file has a string followed by a single tab
// character and a non-negative integer. The program will also find the maximum and
// minimum size string and, the maximum and minimum number then print them to the screen.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "prototypes.h"

int main(int argc, char * argv[])
{
    FILE *inFile;
    FILE *outFile;
    // Input and output file pointers
    int outFileFlag = 0;
    // Flag to close outfile. Set to 1 when commands '-t' and '-b'
    // are used. Flag remains 0 when '-s' is used.
    
    if (argc != THIRD_INDEX && argc != FOUR_ARGS)
    // Check to see if the user entered the wrong number
    // of arguments. If they did, print an error message and
    // close program.
    {
        fprintf(stderr, "Error: Invalid Number Of Arguments\n");
        exit(1);
    }
    
    else if (strcmp(argv[FIRST_INDEX], "-t") == 0 || strcmp(argv[FIRST_INDEX], "-b") == 0)
    // If the flag is either "-t" or "-b"
    {
        if (argc != FOUR_ARGS)
        // Check to see if the user entered the correct number
        // of arguments. If not, print an error message and
        // close program.
        {
            fprintf(stderr, "Error: Invalid Number Of Arguments\n");
            exit(1);
        }
        
        if (strcmp(argv[FIRST_INDEX], "-t") == 0)
        // If the flag is "-t".
        // This means that the input file is a text file and
        // it is going to be converted to a binary file.
        {
            outFileFlag = 1;
            // Set outfile flag to 1 to close the outfile
            
            if ((inFile = fopen(argv[SECOND_INDEX], "r")) == NULL)
            // Check if input file opens. If not, print error
            // message and close program.
            {
                fprintf(stderr, "Error: Input File Did Not Open\n");
                exit(1);
            }
            
            if ((outFile = fopen(argv[THIRD_INDEX], "w")) == NULL)
            // Check if output file opens. If not, print error
            // message and close program.
            {
                fprintf(stderr, "Error: Output File Did Not Open\n");
                exit(1);
            }
            
            textToBinary(inFile, outFile);
            // Call textToBinary function
        }
        
        else
        // If the flag is "-b".
        // This means that the input file is a binary file and
        // it is going to be converted to a text file.
        {
            outFileFlag = 1;
            // Set outfile flag to 1 to close outfile.
            
            if ((inFile = fopen(argv[SECOND_INDEX], "r")) == NULL)
            // Check if input file opens. If not, print error
            // message and close program.
            {
                fprintf(stderr, "Error: Input File Did Not Open\n");
                exit(1);
            }
            
            if ((outFile = fopen(argv[THIRD_INDEX], "w")) == NULL)
            // Check if output file opens. If not, print error
            // message and close program.
            {
                fprintf(stderr, "Error: Output File Did Not Open\n");
            }
            
            binaryToText(inFile, outFile);
            // Call binaryToText function
        }
    }
    
    else if (strcmp(argv[FIRST_INDEX], "-s") == 0)
    // If the argument is "-s"
    {
        if (argc != THIRD_INDEX)
        // Check to see if the user entered the correct number
        // of arguments. If not, print an error message and
        // close program.
        {
            fprintf(stderr, "Error: Invalid Number Of Arguments\n");
            exit(1);
        }
        
        if ((inFile = fopen(argv[SECOND_INDEX], "r")) == NULL)
        // Check if input file opens. If not, print error
        // message and close program.
        {
            fprintf(stderr, "Error: Input File Did Not Open\n");
        }
        
        binaryStats(inFile);
        // Call binaryStats function
    }
    
    else
    // If an incorrect flag was entered, close the program
    {
        fprintf(stderr, "Error: Invalid Flag\n");
        exit(1);
    }
    
    fclose(inFile);
    
    if (outFileFlag == 1)
    // If outFileFlag is 1, close outfile. outFileFlag is only set
    // to 1 when a command is entered that requires an outfile.
    // Program seg faults if this is run when '-s' is called.
    {
       fclose(outFile);
    }
}

