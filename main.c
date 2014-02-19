// Arthur Knapp
// AK146316

// This is a program that will convert text from a formated
// file into a binary file and vice versa. Each line of the
// file has a string followed by a single tab character and
// a non-negative integer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

int main(int argc, char * argv[])
{
    if (argc != THIRD && argc != FOUR)
    // Check to see if the user entered the wrong number
    // of arguments. If they did, print an error message and
    // close program.
    {
        fprintf(stderr, "Error: Invalid Number Of Arguments\n");
        exit(1);
    }
    
    else if (strcmp(argv[FIRST], "-t") == 0 || strcmp(argv[FIRST], "-b") == 0)
    // If the argument is either "-t" or "-b"
    {
        if (argc != FOUR)
        // Check to see if the user entered the correct number
        // of arguments. If not, print an error message and
        // close program.
        {
            fprintf(stderr, "Error: Invalid Number Of Arguments\n");
            exit(1);
        }
        
        // proceed with program
    }
    
    else if (strcmp(argv[FIRST], "-s") == 0)
    // If the argument is "-s"
    {
        if (argc != THIRD)
        // Check to see if the user entered the correct number
        // of arguments. If not, print an error message and
        // close program.
        {
            fprintf(stderr, "Error: nvalid Number Of Arguments\n");
            exit(1);
        }
        
        // proceed with program
    }
    
    else
    // If an incorrect flag was entered, close the program
    {
        fprintf(stderr, "Error: Invalid Flag\n");
        exit(1);
    }
}

