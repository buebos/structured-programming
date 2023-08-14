#include <stdio.h>
#include <math.h>

int main()
{
    char name[20];
    printf("Enter name: ");
    scanf("%[^\n]s", name);
    printf("Your name is %s.", name);
    return 0;
}