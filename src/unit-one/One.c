#include <stdio.h>
#include <math.h>

int main()
{
    /**
     * First exercise; area of circle
     */
    float PI = 3.141592653589793;
    float radius = 0.0;
    float area = 0;
    /**
     * Second exercise; display greeting and username
     */
    char name[100];
    /**
     * Third exercise; ecuation resolution
     */
    float a;
    float b;
    float c;
    float result;

    /** First exercise */
    printf("Type the radius of the circle: ");
    scanf("%f", &radius);
    area = PI * pow(radius, 2);
    printf("Area is: %lf", area);

    /** Second exercise */
    printf("\nType your name: ");
    scanf("%s", name);
    printf("Welcome %s to structured programming course\n", name);

    /** Third exercise */
    printf("Type value of a: ");
    scanf("%f", &a);
    printf("Type value of b: ");
    scanf("%f", &b);
    printf("Type value of c: ");
    scanf("%f", &c);
    result = pow((a + b) / c, 2);
    printf("Operation result: %0.3lf", result);

    return 0;
}
