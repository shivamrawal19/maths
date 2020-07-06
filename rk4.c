#include<stdio.h>
#include<conio.h>

float f(float x, float y) {
    return x + y;
}

void main() {

    float x, y, px, h;
    float k1, k2, k3, k4, k;
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

        k1 = h * f( x, y );
        printf("\nk1 : %f", k1);
        k2 = h * f( x + (h/2), y + (k1/2) );
        printf("\nk2 : %f", k2);
        k3 = h * f( x + (h/2), y + (k2/2) );
        printf("\nk3 : %f", k3);
        k4 = h * f( x + h, y + k3 );
        printf("\nk4 : %f", k4);

        k = (1.0/6.0) * ( k1 + ( 2 * k2 ) + ( 2 * k3 ) + k4 );

        y = y + k;
        x = x + h;

        printf("\nx : %f | y : %f", x, y);

    }

    printf("\nFor x : %f => y : %f\n", x, y);

}
