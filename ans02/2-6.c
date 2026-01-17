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
        int check1 = rand() % 2;
        int check2 = rand() % 2;
        int check3 = rand() % 2;

        char *op1 = "+";
        char *op2 = "+";
        if (check1) 
            op1 = "-";
        if (check2)
            op2 = "-";

        
        printf("%d%*s%s%*s%d%*s%s%*s%d：", a, n, "",op1,  n, "", b, n, "", op2, n, "", c);

        time_t start = time(NULL);

        do {
            int x;
            scanf("%d", &x);
            if (op1 == "-" && op2 == "-") {
                if (x == a - b - c)
                break;
            } else if (op1 == "-") {
                if (x == a - b + c)
                break;
            } else if (op2 == "-") {
                if (x == a + b - c)
                break;
            } else {
                if (x == a + b + c)
                break;
            }
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
