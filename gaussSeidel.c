#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() {

    float a[100][100];
    float b[100];
    float temp;
    int i, j, k;
    int noOfVariables, noOfIterations;

    printf("Enter no of variables : ");
    scanf("%d", &noOfVariables);

    for (i = 0; i < noOfVariables; i++) {
        for (j = 0; j < noOfVariables; j++) {
            printf("a%d%d : ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
        printf(" b%d : ", i+1);
        scanf("%f", &b[i]);
        printf("\n");
    }

    printf("No of iterations : ");
    scanf("%d", &noOfIterations);

    float x[noOfVariables];

    for (i = 0; i < noOfVariables; i++) {
        x[i] = 0;
    }

    for (k = 0; k < noOfIterations; k++) {
        for (i = 0; i < noOfVariables; i++) {
            // ox[i] = ( b[i] - ( a[i][1]*x[i] ) - ( a[i][2]*x[i] ) ) / a[i][i];

            temp = b[i];
            printf("%f ", b[i]);

            for (j = 0; j < noOfVariables; j++) {
                if (i!=j) {
                    temp -= ( a[i][j] * x[j] );
                    printf("%f * %f ", a[i][j], x[j]);
                }
            }

            temp /= a[i][i];
            printf(" / %f ", a[i][i]);

            x[i] = temp;
            printf("%f ", x[i]);
        }
        printf("\n");
    }




    // printf("Enter a11 : \n");
    // scanf("%f\n", &a[0][0]);



}
