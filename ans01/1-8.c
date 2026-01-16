#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE 10

int main(void)
{
    srand(time(NULL));

    int ans = rand() % 1000;
    int no;

    int num[MAX_STAGE];
    int stage = 0;

    printf("0~999の整数を当てよう!!\n\n");

    for (int i = stage; i > 0; i--) {
        printf("残り%d回。いくつかな : ", MAX_STAGE - stage);
        scanf("%d", &no);
        num[stage++] = no;

        if (no > ans)
            printf("もっと小さい\a\n");
        else if (no < ans)
            printf("もっと大きい\a\n");
        if (no == ans || stage >= MAX_STAGE) break;
    }

    if (no != ans)
        printf("残念。正解は%dでした\a\n", ans);
    else {
        printf("正解です\n");
        printf("%d回で当たりました\n", stage);
    }

    puts("\n--- 入力履歴 ---");
    for (int i = 0; i < stage; i++) {
        if (num[i] - ans != 0)
            printf("%2d : %4d %+4d\n", i + 1, num[i], num[i] - ans);
        else {
            printf("%2d : %4d %4d\n", i + 1, num[i], num[i] - ans);
        }
    }
    return 0;
}