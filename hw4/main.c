#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

void sort(int *arr) {
    for (int k = 0; k < 6-1; k++) {    
        for (int j = 0; j < 6-k-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    } 
}
void generate_lottery_numbers (int *arr) {
    for (int i = 0; i < 7; i++) {
        if (i == 6) {
            arr[i] = rand() % 10 + 1;
        } else {
            arr[i] = rand() % 69 + 1;
        }
        for (int j = 0; j < i; j++) {
            if (i == 6 && arr[j] == arr[i]) {
                arr[i]= rand() % 10 + 1;
            } else if (i < 6 && arr[j] == arr[i]) {
                arr[i]= rand() % 69 + 1;
            }
        }
    }
}
struct LottoRecord {
    int numbers[7];
};

void save_record(struct LottoRecord record) {
    FILE* fp = fopen("record.bin", "ab");
    fwrite(&record, sizeof(record), 1, fp);
    fclose(fp);
}

bool check_match(struct LottoRecord record, int* winning_numbers) {
    int match_count = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (record.numbers[i] == winning_numbers[j]) {
                match_count++;
                break;
            }
        }
    }
    return match_count == 6;
}

void print_matched_records(int* winning_numbers) {
    FILE* fp = fopen("record.bin", "rb");
    if (!fp) {
        printf("尚未有任何紀錄\n");
        return;
    }

    struct LottoRecord record;
    bool has_match = false;
    while (fread(&record, sizeof(record), 1, fp)) {
        if (check_match(record, winning_numbers)) {
            has_match = true;
            printf("[");
            for (int i = 0; i < 6; i++) {
                printf("%02d ", record.numbers[i]);
            }
            printf("%02d", record.numbers[6]);
            printf("] 中獎\n");
        }
    }
    if (!has_match) {
        printf("沒有中獎的彩卷\n");
    }
    fclose(fp);
}

int main() {
    int lottery_numbers[7], n;
    printf("歡迎光臨長庚樂透彩購買機臺\n請問您要買幾組樂透彩 (1 ~ 5): ");
    scanf("%d", &n);
    printf("以爲您購買的%d組樂透組合輸出至lotto.txt\n", n);

    srand((unsigned)time(NULL));
    putenv("TZ=Asia/Taipei");
    tzset();
    time_t curtime = time(NULL);
    asctime(localtime(&curtime));

    FILE* fp = fopen("lotto.txt", "w+");
    fprintf(fp, "======== lotto649 ========\n %s", asctime(localtime(&curtime)));

    for (int i = 1; i <= n; i++) {
        generate_lottery_numbers(lottery_numbers);
        sort(lottery_numbers);
        fprintf(fp, "[%d]: ", i);
        for (int i = 0; i < 7; i++) {
            if (lottery_numbers[i] <= 9) {
                fprintf(fp, "0%d ", lottery_numbers[i]);
            } else {
                fprintf(fp, "%d ", lottery_numbers[i]);
            }
        }
        fprintf(fp, "\n");

        struct LottoRecord record;
        memcpy(record.numbers, lottery_numbers, sizeof(lottery_numbers));
        save_record(record);
    }

    for (int i = n+1; i <= 5; i++) {
        fprintf(fp, "[%d]: -- -- -- -- -- -- --\n", i);
    }
    fprintf(fp, "======== csie@CGU ========\n");
   
    fclose(fp);
    return 0;
}
