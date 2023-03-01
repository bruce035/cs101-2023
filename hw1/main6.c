#include <stdio.h>
#include <string.h>
char* convert_digit(char digit)
{
    char* roman[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    int index = digit - '0';
    if (index < 1 || index > 9) {
        return "";
    }
    return roman[index];
}
int main()
{
    char input[] = "81c8g8u168";
    int input_length = strlen(input);

    for (int i = 0; i < input_length; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            printf("%s ", convert_digit(input[i]));
        } else {
            printf("%c", input[i]);
        }
    }
    return 0;
}
