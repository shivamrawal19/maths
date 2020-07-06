#include<stdio.h>
#include<conio.h>

float f(float x, float y) {
    return y - ( ( 2.0 * x ) / y );
}

void main() {

    float x, y, px, h;
    float n;
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

        y = y + h * f(x, y);

        x = x + h;

        printf("\nx : %f | y : %f", x, y);

    }

    printf("\nFor x : %f => y : %f\n", x, y);

}
