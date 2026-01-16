#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int min = rand();
    int max = rand();
    int inp;

    if (min > max) {
        int tmp = min;
        min = max;
        max = tmp;
    }

    int width = max - min + 1;
    int ans = rand() % width + min;

    printf("数は%dから%dの間です。\n", min, max);

    int counter = 0;

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