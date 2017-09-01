/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // displays error message if 2 or 3 command line arguments are not present
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // converts command line argument from string to integer
    int n = atoi(argv[1]);

    // The initializer function srand48() sets the high order 32-bits of Xi to the argument seedval.
    //if 3 command line arguments are present then the thirs argument is used to initialise drand() 
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    else
    {
        srand48((long) time(NULL));
    }

    // print the fist n pseudorandom numbers using the drand48() funcnction by multiplying with limit specified at the beginning
    //of the program and then it is type casted to integer
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
