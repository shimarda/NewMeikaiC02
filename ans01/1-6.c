#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int level;
    int max;
    int inp;

    do {
        printf("レベルを選択 : (1) 1 ~ 9 (2) 1 ~ 99 (3) 1 ~ 999 (4) 1 ~ 9999 :");
        scanf("%d", &level);
    } while (level != 1 && level != 2 && level != 3 && level != 4);

    switch (level) {
        case 1:
            max = 9;
            break;
        case 2:
            max = 99;
            break;
        case 3:
            max = 999;
            break;
        case 4:
            max = 9999;
            break;
    }

    int ans = rand() % max + 1;

    int counter = 0;

    int width = max;

    while (width > 1) {
        counter++;
        width = width / 2;
    }

    printf("回答回数は%dです。\n", counter);

        do {
        printf("答えはいくら? : ");
        scanf("%d", &inp);

        counter--;

        if (ans > inp) {
            printf("もっと大きい\n");
        } else if (ans < inp) {
            printf("もっと小さい\n");
        }
    } while (ans != inp && counter > 0);

    if (ans != inp) {
        printf("不正解\n");
    } else {
        printf("正解\n");
    }
    printf("答えは %d \n", ans);
    return 0;
}