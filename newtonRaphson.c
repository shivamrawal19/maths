#include<stdio.h>
#include<conio.h>
#include<math.h>

float fd(float x) {
    return (3*x*x) - 1;
}

float f(float x) {
    return (x*x*x) - x - 11;
}

void main() {

    float a, temp;
    int counter = 1;

    printf("Value : ");
    scanf("%f", &a);

    printf("-------------------------------------------------\n");
    printf("|  Iteration No  |  Value of x0  |  Value of x  |\n");
    printf("-------------------------------------------------\n");

    do {

        temp = a;
        a = a - (f(a) / fd(a));
        printf("|  %12d  |  %11.6f  |  %10.6f  |\n", counter, temp, a);
        counter++;

    } while( fabs(temp - a) > 0.0001  );

    printf("-------------------------------------------------\n");

    printf("Answer is : %f", a);

}
