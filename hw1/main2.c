#include <stdio.h>
int main() {
    char str[] = "A2B3C4d3";
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len; i += 2) {
        for (int j = 0; j < str[i+1] - '0'; j++) {
            printf("%c", str[i]);
        }
    }
    return 0;
}
