/*
 * Ezra Addas, CSCE 240
 * Created 9/11, 11:58PM
 * Project 1
 */

#include <iostream>

using namespace std;

/* Default argument rules:
 *
 * 1. After first instance of default value, everything to the right must have
 * a default value
 *
 * 2. Default value initialization can either be in function prototype or definition
 * (prototype preferred), not both
 *
 * 3.
 */

int func(int x, int y=0, int z=3);

/* Recursion */
// Best for problems with no easy solution,
// but has algorithm for reducing said problem
int rMyPower(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return (base * rMyPower(base, exponent-1));
    }
}

/*
 * Better Way to Make Functions: Header file
 * Put prototypes in ".h" header file, so using #include
 * "header file (full file location)" will make it so that it
 * uses the library attached
 *
 * Header files better for sharing with other devs to see functions,
 * classes, etc. without seeing source code (prevent copying while still sharing)
 *
 * <> means look in standard libraries and find specific thing
 *
 * All prototypes go in .h, definitions in .cpp, and main stays simple
 */