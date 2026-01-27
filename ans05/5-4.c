#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAGE 10
#define LEVEL_MIN 3
#define LEVEL_MAX 20

int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;

    do {
        if ((c2 = clock()) == (clock_t)-1)
            return 0;
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

void reverse_str(char *x)
{
    char tmp;
    int len = strlen(x);

    for (int i = 0; i < len / 2; i++) {
        tmp = x[i];
        x[i] = x[len - i - 1];
        x[len - i - 1] = tmp;
    }
    
}

int main(void)
{
    int level;
    int success = 0;
    const char ltr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int digit;

    srand(time(NULL));

    printf("英語記憶トレーニング\n");

    do {
        printf("挑戦するレベル (%d ~ %d) : ", LEVEL_MIN, LEVEL_MAX);
        scanf("%d", &level);
    } while (level < LEVEL_MIN || LEVEL_MAX < level);

    printf("%d桁の英字を逆順に記憶しましょう\n", level);

    time_t start = time(NULL);

    for (int stage = 0; stage < MAX_STAGE; stage++) {
        char mstr[LEVEL_MAX + 1];
        char x[LEVEL_MAX * 2];

        for (int i = 0; i < level; i++) {
            mstr[i] = ltr[rand() % strlen(ltr)];
        }
        mstr[level] = '\0';

        digit = rand() % level;

        printf("先頭から%d桁目の数字は何ですか\n", digit + 1);

        printf("%s", mstr);
        fflush(stdout);
        sleep(125 * level);

        printf("\r%*s\r入力せよ : ", level, "");
        scanf("%s", x);

        reverse_str(x);

        if (memcmp(&mstr[digit], x, sizeof(char)) != 0)
            printf("間違いです。\a\n");
        else {
            printf("正解です。\n");
            success++;
        }
    }
    time_t end = time(NULL);

    printf("%d回中%d回成功しました。\n", MAX_STAGE, success);
    printf("%.1f秒でした。\n", difftime(end, start));
}