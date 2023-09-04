#include <stdio.h>

int main() {
    const float PAY_PER_HOUR = 20;
    const float PAY_PER_EXTRA = 25;
    int hoursWorked = 0;
    float salary = 0;

    printf("How many hours did you work this week? ");
    scanf("%d", &hoursWorked);

    if(hoursWorked < 0){
        printf("Please enter valid amount of hours");
        return 1;
    }

    if (hoursWorked <= 40) {
        salary = PAY_PER_HOUR * hoursWorked;
    } else {
        salary = PAY_PER_HOUR * 40 + PAY_PER_EXTRA * (hoursWorked - 40);
    }

    printf("Your pay this week is: $%0.2f", salary);

    return 0;
}