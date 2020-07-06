#include<stdio.h>
#include<conio.h>
#include<math.h>

int fact(int x) {
    int i;
    int mul = 1;
    for (i = 1; i <= x; i++) {
        mul *= i;
    }
    return mul;
}

void main() {

    // int i;
    //
    // for (i = 0; i < 225; i++) {
    //     printf("%d - %c\n", i, (char)i);
    // }

    // printf("%c\n", 31);

    float x[100], y[100];
    int noOfSamples = 0;
    int i, j;

    printf("Enter no of samples : ");
    scanf("%d", &noOfSamples);

    for (i = 0; i < noOfSamples; i++) {
        printf("Enter x(%d) : ", i+1);
        scanf("%f", &x[i]);
        printf("Enter y(%d) : ", i+1);
        scanf("%f", &y[i]);
        printf("\n");

    }

    float dy[noOfSamples-1][noOfSamples];

    for (i = 0; i < noOfSamples; i++) {
        for (j = 0; j < noOfSamples-i; j++) {
            if (i == 0) {
                dy[i][j] = y[j];
            } else {
                dy[i][j] = dy[i-1][j+1] - dy[i-1][j];
            }
        }
    }

    for (i = 0; i < noOfSamples; i++) {
        for (j = 0; j < noOfSamples; j++) {
            printf("%f ", dy[i][j]);
        }
        printf("\n");

    }

    printf("-- THE INTERPOLATION TABLE --\n\n");

    printf("+------------+--------------");
    for (i = 0; i < noOfSamples-1; i++) {
        printf("+--------------");
    }
    printf("+\n");

    printf("|         x  |           y  ");
    for (i = 0; i < noOfSamples-1; i++) {
        printf("|         %c%dy  ", 30, i+1);
    }
    printf("|\n");

    printf("+------------+--------------");
    for (i = 0; i < noOfSamples-1; i++) {
        printf("+--------------");
    }
    printf("+\n");

    float fdy[(noOfSamples*2)-1][noOfSamples];

    int dyj = 0;
    int dyj2 = 0;

    for (i = 0; i < (noOfSamples*2)-1; i++) {
        dyj = 0;
        dyj2 = 1;
        for (j = 0; j < noOfSamples; j++) {
            if (i >= j && ((noOfSamples*2-1)-i) >= j && (i % 2 == 0 && j % 2 == 0) ) {
                fdy[i][j] = dy[ dyj ][ ( i - j ) / 2 ];
                dyj += 2;
            } else if ( i >= j && ((noOfSamples*2-1)-i) >= j && (i % 2 == 1 && j % 2 == 1)) {
                fdy[i][j] = dy[ dyj2 ][ ( i - j ) / 2 ];
                dyj2 += 2;
            } else {
                fdy[i][j] = 999;
            }
        }
    }

    int counter = 0;

    for (i = 0; i < (noOfSamples*2)-1; i++) {
        if (i % 2 == 0) {
            printf("|  % 8.3f  ", x[counter]);
            counter++;
        } else {
            printf("|            ");
        }
        for (j = 0; j < noOfSamples; j++) {
            if (fdy[i][j] != 999) {
                printf("|  % 10.4f  ", fdy[i][j]);
            } else {
                printf("|              ");
            }
        }
        printf("|\n");
    }

    printf("+------------+--------------");
    for (i = 0; i < noOfSamples-1; i++) {
        printf("+--------------");
    }
    printf("+\n");



    // equation for finding random value

    float py;

    printf("\n\nEnter value to predict the result of : ");
    scanf("%f", &py);

    printf("\n");

    float p = ( py - x[0] ) / fabs(x[1]-x[0]);

    printf("P = x - x0 / h\n");
    printf("  = %f - %f / %f\n", py, x[0], fabs(x[1]-x[0]));
    printf("  = %f\n", p);

    printf("\n");

    // just printing the equation
    printf("f(x) = y0\n");
    for (i = 0; i < noOfSamples-1; i++) {
        printf("     + ");
        for (j = 0; j <= i; j++) {
            if (j==0) {
                printf("( P");
            } else {
                printf("( P - %d )", j);
            }
        }
        printf(" %c%dy0 )", 30, i+1);

        if (i != 0) {
            printf(" / %d!", i+1);
        }

        printf("\n");
    }

    printf("\n");

    // printing the equation with values
    float finalAns = dy[0][0];
    float intermediateAns;

    printf("f(% 9.4f ) = %6.4f\n", py, dy[0][0]);
    for (i = 0; i < noOfSamples-1; i++) {
        printf("              + ");
        for (j = 0; j <= i; j++) {
            if (j==0) {
                printf("( %6.4f", p);
                intermediateAns = p;
            } else {
                printf("( %6.4f - %d )", p, j);
                intermediateAns *= p-j;
            }
        }
        printf(" %6.4f )", dy[i+1][0]);
        intermediateAns *= dy[i+1][0];

        if (i != 0) {
            printf(" / %d", fact(i+1));
            intermediateAns /= fact(i+1);
        }

        finalAns += intermediateAns;

        printf("\n");
    }


    printf("\n");

    // printing final answer
    printf("f(% 9.4f ) = %f\n", py, finalAns);

}
