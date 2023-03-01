#include <stdio.h>
int main() {
    char str[] = "AABBBCCCCddd";
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    int count = 1;
    for (int i = 1; i <= len; i++) {
        if (str[i] == str[i-1]) {
            count++;
        } else {
            printf("%c%d", str[i-1], count);
            count = 1;
        }
    }
    return 0;
}
