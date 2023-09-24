#ifndef MATRIXMATH_H
#define MATRIXMATH_H

// Function to input or output a matrix
void inpoutmat(long double arr[10][10], int m, int rmax, int cmax);

// Function to perform matrix multiplication
void mult(long double arr1[10][10], long double arr2[10][10], int Rarr1, int Carr1, int Rarr2, int Carr2);

// Function to perform matrix addition or subtraction
void calc(long double arr1[10][10], long double arr2[10][10], int selector, int Rarr1, int Carr1, int Rarr2, int Carr2);

// Function to calculate the determinant of a matrix
long double determinant(long double arr[10][10], int n);

#endif
