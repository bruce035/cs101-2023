#include <stdio.h>
#include <string.h>
void shift(char str[], int n) {
    int len = strlen(str);
    n = n % len;  
    char temp[n+1];
    strncpy(temp, str, n);
    temp[n] = '\0';
    memmove(str, str+n, len-n);
    strcat(str, temp);
}
int main() {
    char str[] = "ABC123";
    int n = 1;
    printf("Before shifting: %s\n", str);
    shift(str, n);
    printf("After shifting %d positions: %s\n", n, str);
    return 0;
}
