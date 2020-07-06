#include<stdio.h>
#include<conio.h>

void main() {

    int n, i;
    float x[100], y[100];
    float sx = 0, sy = 0, sxy = 0, sx2 = 0, sy2 = 0;
    float a, b;

    printf("Enter the no of samples : ");
    scanf("%d", &n);

    printf("");

    for (i = 0; i < n; i++) {
        printf("x[%d] : ", i+1);
        scanf("%f", &x[i]);
        printf("y[%d] : ", i+1);
        scanf("%f", &y[i]);

        sx += x[i];
        sy += y[i];
        sx2 += x[i] * x[i];
        sy2 += y[i] * y[i];
        sxy += x[i] * y[i];

        printf(" ");
    }

    a = ( sy - ( ( ( n * sxy ) - ( sx * sy ) ) / ( ( n * sx2 ) - ( sx * sx ) ) ) ) / n;
    b = ( ( n * sxy ) - ( sx * sy ) ) / ( ( n * sx2 ) - ( sx * sx ) );

    printf("a : %f", a);
    printf("b : %f", b);

}
