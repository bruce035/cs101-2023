#include <stdio.h>
#include <ctype.h>
int main() {
    char str[] = "ad-9c9dqd";
    char result[sizeof(str)] = {0};
    int j = 0; 
    for (int i = 0; str[i] != '\0'; i++) { 
        if (isdigit(str[i]) || str[i] == '-') { 
            result[j++] = str[i]; 
        }
    }
    printf("Output: %s\n", result); 
    return 0;
}
