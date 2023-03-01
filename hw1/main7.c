#include <stdio.h>
int main() {
    char a[] = "10011110";
    int num = 0;
    for (int i = 0; a[i] != '\0'; i++) {
        num = num * 2 + (a[i] - '0');
    }
    printf("%X\n", num);
    return 0;
}
