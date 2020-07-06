#include<stdio.h>
#include<conio.h>

int n;
float a[100][100];
float b[100];

// this will find the row having max number in column
int nonZeroRow(int columnNo) {

    int i;

    for (i = 0; i < n; i++) {
        if ( a[i][columnNo] != 0 ) {
            return i;
        }
    }

    return 0;

}

void show() {

    int i, j;

    printf("+--                      --+  +--      --+\n");

    for (i = 0; i < n; i++) {

        printf("|  ");

        for (j = 0; j < n; j++) {
            printf("%6.2f  ", a[i][j]);
        }
        printf("|  |  %6.2f  |\n", b[i]);
    }

    printf("+--                      --+  +--      --+\n");

}

// simple row multiply operation r1(4)
void sr(int row, float noToMultiply) {

    int i, j;

    for (j = 0; j < n; j++) {
        a[row][j] = a[row][j] * noToMultiply;
    }

    b[row] = b[row] * noToMultiply;

    show();
    printf(" R%d ( %f ) \n\n", (row+1), noToMultiply);

}

// row multiplication and addition operation r12(-2)
void mr(int baseRow, int operationRow, float noToMultiply) {

    int i, j;

    for (j = 0; j < n; j++) {
        a[operationRow][j] = a[operationRow][j] + ( a[baseRow][j] * noToMultiply );
    }

    b[operationRow] = b[operationRow] + ( b[baseRow] * noToMultiply );

    show();
    printf(" R%d%d ( %f ) \n\n", (baseRow+1), (operationRow+1), noToMultiply);
}

// change / swap operation r12
void cr(int baseRow, int operationRow) {

    int i;

    float temp[100];

    for (i = 0; i < n; i++) {
        temp[i] = a[operationRow][i];
    }

    for (i = 0; i < n; i++) {
        a[operationRow][i] = a[baseRow][i];
    }

    for (i = 0; i < n; i++) {
        a[baseRow][i] = temp[i];
    }

    show();
    printf(" R%d%d \n\n", (baseRow+1), (operationRow+1));
}

void main() {

    int i, j;

    printf("Enter no of variables : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Equation %d\n", (i));
        for (j = 0; j < n; j++) {
            printf("a%d : ", (j));
            scanf("%f", &a[i][j]);
        }
        printf("b : ");
        scanf("%f", &b[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%6.2f a%d ", a[i][j], (j+1));
            if (j != n-1) {
                printf("* ");
            }
        }
        printf("= %6.2f\n", b[i]);
    }


    // logic part

    // first make location 00 => 1
    if ( a[0][0] == 0 ) {
        cr( 0, nonZeroRow(0) ); // r12 // swap rows
    }

    sr( 0,     1.0 / a[0][0] ); // r1 ( 1 / a11 )
    mr( 0, 1, -1.0 * a[1][0] ); // r12 ( a21 )
    mr( 0, 2, -1.0 * a[2][0] ); // r12 ( a31 )

    if ( a[1][1] == 0 ) {
        cr( 1, nonZeroRow(1) ); // r21 // swap rows
    }

    sr( 1,     1.0 / a[1][1] ); // r2 ( 1 / a22 )
    mr( 1, 0, -1.0 * a[0][1] ); // r21 ( a12 )
    mr( 1, 2, -1.0 * a[2][1] ); // r23 ( a32 )

    if ( a[2][2] == 0 ) {
        cr( 2, nonZeroRow(2) ); // r32 // swap rows
    }

    sr( 2,     1.0 / a[2][2] ); // r3 ( 1 / a33 )
    mr( 2, 0, -1.0 * a[0][2] ); // r31 ( a13 )
    mr( 2, 1, -1.0 * a[1][2] ); // r32 ( a23 )

    printf("b1 : %f", b[0]);
    printf("b2 : %f", b[1]);
    printf("b2 : %f", b[2]);

    // for (i = 0; i < n; i++) {
    //     for (j = 0; j < n; j++) {
    //         if (j == 0) {
    //             sr( i, 1.0 / a[i][i] );
    //         } else {
    //             // mr( i, j-1, -1.0 * a[][] )
    //         }
    //     }
    // }

}
