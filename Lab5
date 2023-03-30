#include <stdio.h>

int add(int num1, int num2) {
    return num1 + num2;
}
int sub(int num1, int num2) {
    return num1 - num2;
}
int mul(int num1, int num2) {
    return num1 * num2;
}
int div(int num1, int num2) {
        return num1 / num2;
}
int calc(int (*func)(int, int), int num1, int num2) {
    return (*func)(num1, num2);
}
int main() {
    printf("sum = %d\n", calc(add, 4, 2));
    printf("dif = %d\n", calc(sub, 4, 2));
    printf("product = %d\n", calc(mul, 4, 2));
    printf("quotient = %d\n", calc(div, 4, 2));
    return 0;
}
