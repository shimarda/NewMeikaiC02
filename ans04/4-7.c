#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int make_problem(void)
{
    int ans_list[3];
    
    for (int i = 0; i < 3; i++) {
        int j, digit;
        do {
            digit = rand() % 10;
            for (j = 0; j < i; j++) {
                if (digit == ans_list[j])
                    break;
            }
        } while (j < i); 
        ans_list[i] = digit;
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = ans * 10 + ans_list[i];
    }
    printf("%d", ans);
    return ans;
}

int main(void)
{
    srand(time(NULL));

    int ans = make_problem();
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