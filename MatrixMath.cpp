#include "MatrixMath.h"
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

long double result[10][10];

// Function to input or output a matrix
void inpoutmat(long double arr[10][10], int m, int rmax, int cmax) {
    for (int r = 0; r < rmax; r++) {
        for (int c = 0; c < cmax; c++) {
            if (m == 1) {
                cin >> arr[r][c]; // Input matrix values
            } else {
                cout << fixed << setprecision(0) << round(arr[r][c]) << " "; // Output matrix values
            }
        }
        if (m != 1)
            cout << endl;
    }
}

// Function to perform matrix multiplication
void mult(long double arr1[10][10], long double arr2[10][10], int Rarr1, int Carr1, int Rarr2, int Carr2) {
    for (int m = 0; m < 10; m++) {
        for (int n = 0; n < 10; n++) {
            result[m][n] = 0;
        }
    }
    for (int r = 0; r < Rarr1; r++) {
        for (int c = 0; c < Carr2; c++) {
            for (int i = 0; i < Carr1; i++) {
                result[r][c] += ((arr1[r][i]) * (arr2[i][c])); // Matrix multiplication
            }
        }
    }
    inpoutmat(result, 2, Rarr1, Carr2); // Output the result matrix
}

// Function to perform matrix addition or subtraction
void calc(long double arr1[10][10], long double arr2[10][10], int selector, int Rarr1, int Carr1, int Rarr2, int Carr2) {
    for (int r = 0; r < (max(Rarr1, Rarr2)); r++) {
        for (int c = 0; c < (max(Carr1, Carr2)); c++) {
            switch (selector) {
                case 1:
                    result[r][c] = arr1[r][c] + arr2[r][c]; // Matrix addition
                    break;
                case 2:
                    result[r][c] = arr1[r][c] - arr2[r][c]; // Matrix subtraction
                    break;
            }
        }
    }
    inpoutmat(result, 2, max(Rarr1, Rarr2), max(Carr1, Carr2)); // Output the result matrix
}

// Function to calculate the determinant of a matrix
long double determinant(long double arr[10][10], int n) {
    long double sum = 0;
    long double filler[10][10];
    if (n == 2) {
        return ((arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0])); // Base case for 2x2 matrix
    } else {
        for (int x = 0; x < n; x++) {
            int m = 0;
            for (int i = 1; i < n; i++) {
                int k = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    filler[m][k] = arr[i][j]; // Create a submatrix without row x and column x
                    k++;
                }
                m++;
            }
            sum = sum + ((pow(-1, x)) * (arr[0][x]) * (determinant(filler, n - 1))); // Recursive calculation of determinant
        }
    }
    cout << fixed << setprecision(0);
    return round(sum); // Return the determinant
}
