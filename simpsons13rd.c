#include<stdio.h>
#include<conio.h>

void main() {

    printf("________________________\n\n");
    printf("  Simpson's 1/3rd Rule  \n");
    printf("________________________\n\n");

    int n;
    int i;
    float a, b;
    float x[100], y[100];
    float area;
    float h;

    printf("Enter no of elements : ");
    scanf("%d", &n);

    printf("Enter b : ");
    scanf("%f", &b);

    printf("Enter a : ");
    scanf("%f", &a);

    for (i = 0; i < n; i++) {
        printf("\n");
        printf("x[%d] : ", i+1);
        scanf("%f", &x[i]);
        printf("y[%d] : ", i+1);
        scanf("%f", &y[i]);
    }

    h = ( b - a ) / n;

    printf("\nh = ( b - a ) / n");
    printf("\nh = ( %4.2f - %4.2f ) / %d", b, a, n);
    printf("\nh = %f", h);

    printf("\n\ny = h/3 + [ y0 ");
    for (i = 1; i < n-1; i++) {
        if (i % 2 == 2) {
            printf("+ 4(y%d) ", i);
        } else {
            printf("+ 2(y%d) ", i);
        }
    }
    printf("+ y%d ]", n-1);

    printf("\ny = %4.2f/2 + [ %4.2f ", h, y[0]);
    for (i = 1; i < n-1; i++) {
        if (i % 2 == 2) {
            printf("+ 4(%4.2f) ", y[i]);
        } else {
            printf("+ 2(%4.2f) ", y[i]);
        }
    }
    printf("+ %4.2f ]", y[n-1]);

    area = h/2 + y[0];
    for (i = 1; i < n-1; i++) {
        if (i % 2 == 0) {
            area += 4 * y[i];
        } else {
            area += 2 * y[i];
        }
    }
    area += y[n-1];

    printf("\ny = %f", area);

    printf("\n\nArea under the given curve is : %f\n", area);
}
