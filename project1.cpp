/*
 * Ezra Addas, CSCE 240
 * Created 9/11, 11:58PM
 * Project 1
 */

#include <iostream>
#include <cmath>

using namespace std;

/*
 * Function: This program will take 3 numeric values from the user
 * continuously until the user quits. These values represent the constants
 * a, b and c in a quadratic equation. The program will then find x1 and x2
 * and print out their values before prompting the user for input again.
 */

// Function prototypes
void SolveQuadratic(int a, int b, int c, int &x1, int &x2);
void PrintSolution(int x1, int x2);
void GetConstants(int &a, int &b, int &c);
bool CheckSolution(int a, int b, int c);

int main(int argc, char** argv) {
    char userOption('j');
    int x1(0), x2(0), a(0), b(0), c(0);

    // Do while loop displays menu of options for what to do next;
    // quits if 'q' is given or prompts user for constants
    // as input and solves if 's' is given; loops back to
    // display menu if neither character is received
    do {
        cout << "Press 's' to solve and 'q' to quit" << endl;
        cin >> userOption;

        if (userOption == 's') {
            GetConstants(a, b, c);
            SolveQuadratic(a, b, c, x1, x2);
        }
    } while (userOption != 'q');
}

// Solves the quadratic equation
void SolveQuadratic(int a, int b, int c, int &x1, int &x2) {

    // Check if the discriminant has real solutions and handle
    // accordingly
    bool hasSolution = CheckSolution(a, b, c);

    if (!hasSolution) {
        cout << "Equation does not have real solutions" << endl;

        return;
    }

    // Otherwise, solve by assigning x1 and x2 to each
    // version of quadratic equation
    x1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);
    x2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a);

    // Print the solution
    PrintSolution(x1, x2);
}

void PrintSolution(int x1, int x2) {

    // Print x1 and x2 in readable manner
    cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
}

// Prompts user to give constants and store in variables a, b and c
void GetConstants(int &a, int &b, int &c) {

    // Take user inputs for a, b and c
    cout << "Enter a, b, and c: " << endl;

    // Runs while loop until integers given (wrong input type may be given)
    while (!(cin >> a >> b >> c)) {
        cout << "Invalid input. Give 3 integers: ";

        // Clear input of invalid line
        cin.clear();

        // Remove bad input from cin
        cin.ignore(10000, '\n');
    }
}

// Checks if the integers given have a real solution
bool CheckSolution(int a, int b, int c) {
    bool hasSolution(true);

    if ((b * b) - (4 * a * c) < 0) {
        hasSolution = false;
    }

    return hasSolution;
}

