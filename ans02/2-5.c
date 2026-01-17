#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    printf("視野拡大安産トレーニング開始!!\n");
    time_t start = time(NULL);

    double sum = 0;

    for (int stage = 0; stage < 10; stage++) {

        
        int a = 10 + rand() % 90;
        int b = 10 + rand() % 90;
        int c = 10 + rand() % 90;
        int n = rand() % 17;

        printf("%d%*s+%*s%d%*s+%*s%d：", a, n, "", n, "", b, n, "", n, "", c);

        time_t start = time(NULL);

        do {
            int x;
            scanf("%d", &x);
            if (x == a + b + c)
                break;
            printf("\a違います。再入力してください。 : ");
        } while (1);

        time_t end = time(NULL);
        double t = difftime(end, start);
        printf("第%d回 %.1f秒かかりました。\n", stage + 1, difftime(end, start));
        sum += t;
    }


    printf("平均%.1f秒でした。\n", sum / 10);

    return 0;
}
