#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int ans = rand() % 1000;
    int inp;
    int num = 12;

    if (rand() % 2) {
        ans = -ans;
    };

    do {
        printf("答えはいくら? : ");
        scanf("%d", &inp);
        num--;

        if (ans > inp) {
            printf("もっと大きい\n");
        } else if (ans < inp) {
            printf("もっと小さい\n");
        }
    } while (ans != inp && num > 0);

    if (ans != inp) {
        printf("不正解\n");
    } else {
        printf("正解\n");
    }
    printf("答えは %d \n", ans);
    return 0;
}