/*
 * Created by iaddas, 10/1
 */

#include "oct_1_6.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    // Right before the program quits, ownership of array space is given up
    // (but contents don't change)

    /*
     * Pointers ->
     * int *ptr
     * The * denotes that this a pointer of specified type
     *
     * - Does the exact same thing as a regular variable
     * - EXCEPT, when using *ptr, it takes what is stored at &ptr, and hops to
     * memory location of that variable (ptr = 140; *ptr = location 140 -> 75;)
     * - ptr = 106 -> *ptr = 15 -> at location 106, 15 is the value
     * - Essentially, pointers are special variables where the value stored
     * is pointing to that memory location
     * - Like any variable, should be initialized before use (especially
     * because it points to something else)
     * - The type specifies how many bytes to read and extract from that
     * memory location
     * - You can say ptr = new (type) to manually allocate a memory location
     * (which essentially finds the available bytes and ptr points to that open space)
     * (this prevents ptr pointing to a random location that may or may not
     * be available)
     * - When the program exits, however, it does not de-allocate that memory space
     * from new (type) statement
     * - Proper de-allocation: delete ptr;
     * - This will free up whatever memory space was taken up by ptr
     * - For the most part, if you want to change value of ptr, delete ptr (so
     * that the current pointer de-allocates that location so it is not lost
     * forever)
     * - Allocation quits when execution ends (everything is de-allocated again)
     */

    double *ptr(new double);
    *ptr = 1.1;
    cout << "pointer is at: " << &ptr << " - pointer points to: " <<
        ptr << " and has a value of: " << *ptr << endl;

    delete ptr;

    /*
     * Pointers to create arrays ->
     *
     * - ptr = new double[20];
     * - This statement essentially creates an array of free space of 160 bytes,
     * such that cout << [output]; where output is the address of the start of the array
     * - Ex: cout << ptr; prints 110, and 110 is the address of the start of an array
     * - You can then use it such ptr[index] = value;, like any normal array
     * - This creates a dynamic array that must be managed by the user
     * - Dynamic because you can delete [] ptr; and re-allocate with a new size with
     * ptr = new double[21];
     *
     * - When sending to function, func(ptr) sends ptr as call-by-value
     * - int* ptr and int *ptr is low-key different, but I still need to take longer
     * to get that part (just different by interpretation)
     * - Function prototype should look like (func int* &ptr)
     * - If you don't, ptr comes as call-by-value, and then allocates a DIFFERENT
     * memory location for the array, while the ptr in main still points to
     * a memory location with garbage
     * - You can use call-by-value when reading from the array, but call-by-reference
     * should be used when changing the structure of ptr in some way (initializing
     * and resizing)
     */

    return 0;
}