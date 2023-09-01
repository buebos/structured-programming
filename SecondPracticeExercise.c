#include <stdio.h>
#include <string.h>

int main()
{
    char operation[20];
    float value1;
    float value2;
    float result;
    int isSum = 0;
    int isMultiply = 0;

    printf("Type the operation to run (ADD, MULTIPLY): ");
    scanf("%s", &operation);

    isSum = strcmp(operation, "ADD") == 0;
    isMultiply = strcmp(operation, "MULTIPLY") == 0;

    if (isSum != 1 && isMultiply != 1)
    {
        printf("ERROR: Unknown operation");
        return 1;
    }

    printf("Type value 1: ");
    scanf("%f", &value1);
    printf("Type value 2: ");
    scanf("%f", &value2);

    if (isSum == 1)
    {
        printf("The result of ADD is: %f", value1 + value2);
    }
    else
    {
        printf("The result of MULTIPLY is: %f", value1 * value2);
    }

    return 0;
}