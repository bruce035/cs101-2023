#include <stdio.h>

int main() {
    char a[] = "Hallo";
    int len = 0;
    while (a[len] != '\0') {
        len++;
    }
    for (int i = 0; i < len / 2; i++) {
        char tmp = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = tmp;
    }
    printf("%s", a);
    return 0;
}
