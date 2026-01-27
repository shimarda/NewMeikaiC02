#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAGE 10
#define LEVEL_MIN 2
#define LEVEL_MAX 6

int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;

    do {
        if ((c2 = clock()) == (clock_t)-1)
            return 0;
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

int main(void)
{
    int level;
    int max_stage;

    srand(time(NULL));

    printf("プラスワントレーニング開始\n");
    printf("2桁の数値を記憶します。\n");
    printf("1を引いた値を入力してください");

    do {
        printf("挑戦するレベル (%d ~ %d) : ", LEVEL_MIN, LEVEL_MAX);
        scanf("%d", &level);
    } while (level < LEVEL_MIN || LEVEL_MAX < level);

    do {
        printf("トレーニング回数 : ");
        scanf("%d", &max_stage);
    } while (max_stage <= 0);

    int success = 0;
    int *score = calloc(max_stage, sizeof(int));

    time_t start = time(NULL);

    for (int stage = 0; stage < max_stage; stage++) {
        int no[LEVEL_MAX];
        int x[LEVEL_MAX];
        int seikai = 0;

        printf("\n第%dステージ開始\n", stage + 1);



        for (int i = 0; i < level; i++) {
            no[i] = rand() % 90 + 10;
            printf("%d ", no[i]);
        }
        fflush(stdout);
        sleep(300 * level);
        printf("\r%*s\r入力せよ : ", 3 * level, "");
        fflush(stdout);

        for (int i = 0; i < level; i++) {
            printf("%d番目の数 : ", i + 1);
            scanf("%d", &x[i]);
            if (x[i] == -1)
                i = i - 2;
        }

        for (int i = 0; i < level; i++) {
            if (x[i] != no[i] - 1)
                printf("X ");
            else {
                printf("○ ");
                seikai++;
            }
        }
        putchar('\n');

        for (int i = 0; i < level; i++) {
            printf("%2d ", no[i]);
        }

        printf("・・・%d個正解です。\n", seikai);
        score[stage] = seikai;
        success += seikai;
    }
    time_t end = time(NULL);

    printf("%d回中%d回成功しました。\n", level * max_stage, success);

    printf("\n成績\n");
    for (int i = level; i >= 1; i--) {
        for (int stage = 0; stage < max_stage; stage++) {
            if (score[stage] >= 1)
                printf(" ★ ");
            else 
                printf("    ");
        }
        putchar('\n');
    }
    printf("------------------------\n");
    for (int stage = 1; stage <= max_stage; stage++) {
        printf(" %02d ", stage);
    }
    putchar('\n');

    printf("%.1f秒でした。\n", difftime(end, start));

    free(score);
    return 0;
}