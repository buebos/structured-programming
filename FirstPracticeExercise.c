#include <stdio.h>
#include <math.h>

int main()
{
    float a;
    float b;
    float c;
    float insideSqrt;

    printf("\n\nType the a term: ");
    scanf("%f", &a);

    printf("Type the b term: ");
    scanf("%f", &b);

    printf("Type the c term: ");
    scanf("%f", &c);

    insideSqrt = pow(b, 2) - 4 * a * c;

    if (insideSqrt > 0)
    {
        float x1 = (-b + sqrt(insideSqrt)) / (2 * a);
        float x2 = (-b - sqrt(insideSqrt)) / (2 * a);

        printf("x1 is: %f", x1);
        printf("\nx2 is: %f", x2);
    }
    else if (insideSqrt < 0)
    {
        float left = -b / (2 * a);
        float right = sqrt(-insideSqrt) / (2 * a);

        printf("The equation requires complex numbers, the first result is the following: %f + i * %f", left, right);
        printf("\nThe equation requires complex numbers, the first result is the following: %f - i * %f", left, right);
    }
    else
    {
        float x = -b / (2 * a);

        printf("The equation has only one result: %f", x);
    }

    return 0;
}