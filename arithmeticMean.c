#include<stdio.h>
#include<conio.h>

void main() {

    float x[100], f[100], fx[100];
    int i, n;
    float sf, sfx;

    printf("Enter no of inputs : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter x%d : ", i+1);
        scanf("%f", &x[i]);
        printf("Enter y%d : ", i+1);
        scanf("%f", &f[i]);
    }

    printf("\n+----------+----------+-----------+");
    printf("\n|    x     +    f     +    fx     |");
    printf("\n+----------+----------+-----------+");
    for (i = 0; i < n; i++) {
        printf("\n|  %6.2f  |  %6.2f  |  %7.2f  |", x[i], f[i], x[i] * f[i] );
        sf += f[i];
        fx[i] = x[i] * f[i];
        sfx += fx[i];
    }
    printf("\n+----------+----------+-----------+");
    printf("\n|          +  %6.2f  +  %7.2f  |", sf, sfx);
    printf("\n+----------+----------+-----------+");

    printf("\n\nA.M = %f", sfx / sf );

}
