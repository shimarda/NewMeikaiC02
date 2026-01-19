#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int draw;
    int lose;
    int win;
} Score;

char *hd[] = {"グー", "チョキ", "パー"};

void initialize(Score *s)
{
    s->win = s->lose = s->draw = 0;

    srand(time(NULL));

    printf("じゃんけんゲーム開始\n");
}

void janken(int *h_hand, int *c_hand)
{
    *c_hand = rand() % 3;

    do {
        printf("\nじゃんけんポン ...");
        for (int i = 0; i < 3; i++) {
            printf(" (%d)%s", i, hd[i]);
        }
        printf(" : ");
        scanf("%d", h_hand);
    } while (*h_hand < 0 || *h_hand > 2);
}

void update_score(Score *s, int res)
{
    switch (res)
    {
    case 0: s->draw++; 
            puts("引き分けです。");
            break;
    case 1: s->lose++; 
            puts("あなたの負けです。");
            break;
    case 2: s->win++;
            puts("あなたの勝ちです。");
            break;
    }
}

int main(void)
{
    Score score;
    int num = 0;

    initialize(&score);

    printf("何回勝負しますか : ");
    scanf("%d", &num);

    do {
        int human;
        int comp;

        janken(&human, &comp);
        if ((score.win + score.lose + score.draw) % 5 == 0)
            comp = (human + 2) % 3;
        printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

        int judge = (human - comp + 3) % 3;

        update_score(&score, judge);

    } while (score.win < num && score.lose < num);

    printf(score.win == num ? "\nあなたの勝ちです。\n" : "\nあなたの負けです。\n");
    printf("%d勝%d敗%d分けでした\n", score.win, score.lose, score.draw);

    return 0;
}