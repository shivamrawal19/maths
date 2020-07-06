#include<stdio.h>
#include<conio.h>

float f(float x, float y) {
    return (3*x) + y;
}

void main() {

    float x, y, px, h;
    float k1, k2, k;
    int i;

    printf("Enter x : ");
    scanf("%f", &x);

    printf("Enter y : ");
    scanf("%f", &y);

    printf("Enter x to be predicted : ");
    scanf("%f", &px);

    printf("Enter the step size : ");
    scanf("%f", &h);

    for (i = 0; i < (int)( (px-x)/h ) + 1; i++) {

        k1 = h * f(x, y);
        // printf("k1 : %f", k1);
        k2 = h * f(x+h, y+k1);
        // printf("k2 : %f", k2);
        k = 0.5 * ( k1 + k2 );
        // printf("k : %f", k);
        y = y + k;
        x = x + h;

        printf("\nx : %f | y : %f", x, y);

    }

    printf("\nFor x : %f => y : %f\n", x, y);

}
