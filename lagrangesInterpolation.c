#include<stdio.h>
#include<conio.h>
#include<math.h>

void main() {

    float x[100], y[100];
    int noOfSamples = 0;
    int i, j;
    float ux;

    printf("Enter no of samples : ");
    scanf("%d", &noOfSamples);

    for (i = 0; i < noOfSamples; i++) {
        printf("Enter x(%d) : ", i+1);
        scanf("%f", &x[i]);
        printf("Enter y(%d) : ", i+1);
        scanf("%f", &y[i]);
        printf("\n");
    }

    printf("\n\nEnter value to predict the result of : ");
    scanf("%f", &ux);

    float ans = 0;
    float temp = 1;

    for (i = 0; i < noOfSamples; i++) {

        temp = 1;

        for (j = 0; j < noOfSamples; j++) {
            if (i!=j) {
                temp *= (ux-x[j]) / (x[i]-x[j]);
            }
        }

        ans += (temp * y[i]);
    }

    printf("answer is : %f", ans);

}
