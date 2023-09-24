#include <iostream>
#include "MatrixMath.h"

using namespace std;

int main() {
    long double matA[10][10], matB[10][10];
    int RmatA, CmatA, RmatB, CmatB, num = 0;

    cout << "Please enter dimensions of Matrix A:" << endl;
    cin >> RmatA >> CmatA;
    cout << "Please enter dimensions of Matrix B:" << endl;
    cin >> RmatB >> CmatB;
    cout << "Please enter values of Matrix A:" << endl;
    inpoutmat(matA, 1, RmatA, CmatA);
    cout << "Please enter values of Matrix B:" << endl;
    inpoutmat(matB, 1, RmatB, CmatB);

    do {
        cout << "Please choose operation type (1: A+B, 2: A-B, 3: AxB, 4: |A|, 5: |B|, 6: quit):" << endl;
        cin >> num;
        if (num > 0 && num < 8) {
            switch (num) {
                case 1:
                    if (CmatA == CmatB && RmatA == RmatB) {
                        calc(matA, matB, 1, RmatA, CmatA, RmatB, CmatB);
                    } else {
                        cout << "The operation you chose is invalid for the given matrices." << endl;
                    }
                    break;
                case 2:
                    if (CmatA == CmatB && RmatA == RmatB) {
                        calc(matA, matB, 2, RmatA, CmatA, RmatB, CmatB);
                    } else {
                        cout << "The operation you chose is invalid for the given matrices." << endl;
                    }
                    break;
                case 3:
                    if (CmatA == RmatB) {
                        mult(matA, matB, RmatA, CmatA, RmatB, CmatB);
                    } else {
                        cout << "The operation you chose is invalid for the given matrices." << endl;
                    }
                    break;
                case 4:
                    if (RmatA == CmatA) {
                        if (RmatA == 1) {
                            cout << matA[0][0] << endl;
                        } else {
                            cout << determinant(matA, RmatA) << endl;
                        }
                    } else {
                        cout << "The operation you chose is invalid for the given matrices." << endl;
                    }
                    break;
                case 5:
                    if (RmatB == CmatB) {
                        if (RmatB == 1) {
                            cout << matB[0][0] << endl;
                        } else {
                            cout << determinant(matB, RmatB) << endl;
                        }
                    } else {
                        cout << "The operation you chose is invalid for the given matrices." << endl;
                    }
                    break;
                case 6:
                    cout << "Thank you!";
                    return 0;
                    break;
            }
        } else {
            cout << "Please enter a number from 1 to 7" << endl;
        }
    } while (num != 6);

    return 0;
}
