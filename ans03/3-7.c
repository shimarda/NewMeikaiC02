#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int draw;
    int lose;
    int win;
} Score;

char *hd[] = {"グー", "パー", "チョキ"};

void initialize(Score *s)
{
    s->win = s->lose = s->draw = 0;

    srand(time(NULL));

    printf("じゃんけんゲーム開始\n");
}

void janken(int *h_hand, int *c_hand_0, int *c_hand_1)
{
    *c_hand_0 = rand() % 3;
    *c_hand_1 = rand() % 3;

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

int judge_(int human, int comp0, int comp1)
{
    int g = 0, p = 0, c = 0;
    int hand[] = {human, comp0, comp1};

    for (int i = 0; i < 3; i++) {
        if (hand[i] == 0) g = 1;
        if (hand[i] == 1) p = 1;
        if (hand[i] == 2) c = 1;
    }

    if ( g + p + c != 2) return 0;

    int win;
    if (!g) win = 2;
    else if (!p) win = 0;
    else win = 1;

    if (human == win) {
        return 2;
    } else {
        return 1;
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
        int comp0;
        int comp1;

        janken(&human, &comp0, &comp1);

        printf("私は%sで、彼は%sで、あなたは%sです。\n", hd[comp0], hd[comp1], hd[human]);

        int judge = judge_(human, comp0, comp1);


        update_score(&score, judge);

    } while (score.win < num && score.lose < num);

    printf(score.win == num ? "\nあなたの勝ちです。\n" : "\nあなたの負けです。\n");
    printf("%d勝%d敗%d分けでした\n", score.win, score.lose, score.draw);

    return 0;
}