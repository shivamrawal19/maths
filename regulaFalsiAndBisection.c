#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x) {
    return (x*x*x) - x - 11;
}

float mabs(float x) {
    if (x > 0) {
        return x;
    } else {
        return (-x);
    }
}

void main() {
    float a, b, c;
    int i=1;
    printf("Enter lower bound : ");
    scanf("%f", &a);
    printf("Enter upper bound : ");
    scanf("%f", &b);
    printf("| It no |  lb          |  ub          | mid p        | f(x)         |\n");
    printf("---------------------------------------------------------------------\n");

    while( mabs( a-b ) > 0.00001 ) {
        c = (a+b) / 2;
        float temp = f(c);
        printf("| %5d  | %12.10f | %12.10f | %12.10f | %12.10f |\n", i, a, b, c, temp);
        i++;
        if ( f(a) * f(c) < 0 ) {
            b = c;
        } else if ( f(c) * f(b) < 0 ) {
            a = c;
        } else if ( f(c) == 0 ) {
            printf("%f is the required root", c);
            break;
        }
    }
    printf("root is : %f", c);
    //float temp = mabs(871.9845678);
    //printf("%f", temp);
}
