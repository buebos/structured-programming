#include <stdio.h>
#include <string.h>

int main() {
    const char CONST_CHAR_ARR[] = "abcde";
    /** Always initialize strings, it's a good practice to avoid unexpected
     *  issues
     *  NOT_THIS: char fiveChars[5]; WRONG!!!
     *  USE_THIS:
     */
    char fiveChars[5] = "";

    printf("CONST_CHAR_ARR = %s\n", CONST_CHAR_ARR);
    printf("fiveChars = %s\n", fiveChars);
    printf("fiveChars is empty string = %d\n", strcmp(fiveChars, "") == 0);

    /**
     * If the user input it's more than 4 characters (1 extra because of the
     * string null terminator) it will cause a buffer overflow writting
     * adjascent memory for the other chars. In most cases adjascent memory
     * will be the CONST_CHAR_ARR location
     */
    printf("Assign value to fiveChars: ");
    scanf("%s", fiveChars);

    printf("fiveChars = %s\n", fiveChars);
    printf("CONST_CHAR_ARR = %s\n", CONST_CHAR_ARR);

    return 0;
}