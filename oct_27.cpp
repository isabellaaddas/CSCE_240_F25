//
// Created by HUSol on 10/27/2025.
//

/*
 * arr[5] -> array-index notation
 * *(arr + 5) -> pointer-offset notation
 * ^ basically says go 5 units forward of this type of byte (e.g., forward 5 units of 4-byte int)
 * - *arr = *temp --> *(arr + 0) = *(temp + 0)
 *
 * Deep vs shallow copies
 * - Two pointers, *arr and *temp
 * - Final values in temp, need to copy to arr
 * - Deep copy; copy by going through every element and copying from temp to arr
 * - Shallow copy; delete arr and reassign arr to temp so it points to temp instead
 *
 *
 * Objects
 * - No return type for constructor
 * - Always same name of the object
 * - Compiler makes a default constructor with nothing if you don't have one already
 * - No return type for destructor
 * - Only one destructor ever
 */