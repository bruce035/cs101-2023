#include <stdio.h>

int main() {
    char a[] = "-9 8 7 6 5 -4 3 -2 1";
    int nums[10];
    int len = 0;
    // 分割字串
    int num = 0, sign = 1;
    for(int i = 0; a[i]; i++) {
        if(a[i] == '-') {
            sign = -1;
        } else if(a[i] == ' ') {
            nums[len++] = num * sign;
            num = 0;
            sign = 1;
        } else {
            num = num * 10 + (a[i] - '0');
        }
    }
    nums[len++] = num * sign;

    // 冒泡排序（由大到小）
    for(int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - i - 1; j++) {
            if(nums[j] < nums[j+1]) {
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    int k = 4; 
    if(k <= len) {
        printf("第%d大的數是%d\n", k, nums[k-1]);
    }
    return 0;
