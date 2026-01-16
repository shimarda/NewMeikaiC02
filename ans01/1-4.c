#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int ans = (rand() % 333)*3 + 3;
    int inp;
    int num = 6;

    do {
        printf("答えはいくら? : ");
        scanf("%d", &inp);

        // 以下の場合3の倍数以外が入力されると直ちに終了
        if (inp % 3 != 0) {
            break;
        }
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