#include <time.h>
#include <stdlib.h>
#include <stdio.h>

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
    int max_stage;

    initialize(&score);

    do {
        printf("じゃんけん回数 : ");
        scanf("%d", &max_stage);
    } while (max_stage <= 0);

    char *human_hands = calloc(max_stage, sizeof(char));
    char *comp_hands = calloc(max_stage, sizeof(char));
    int *result = calloc(max_stage, sizeof(int));

    for (int stage = 0; stage < max_stage; stage++) {

        printf("\n第%d回目\n", stage + 1);

        int human;
        int comp;

        janken(&human, &comp);

        printf("私は%sで、あなたは%sです。\n", hd[comp], hd[human]);

        int judge = (human - comp + 3) % 3;
        update_score(&score, judge);

        human_hands[stage % 10] = human;
        comp_hands[stage % 10] = comp;

        result[stage % 10] = judge;

    }

    printf("%d勝%d敗%d分けでした。\n", score.win, score.lose, score.draw);

    printf("\n成績\n");

    for (int stage = 0; stage < max_stage; stage++) {
        printf("第%d回 わたし : %s, あなた : %s ", stage + 1, hd[comp_hands[stage % 10]], hd[human_hands[stage % 10]]);
        
        switch (result[stage - 1])
        {
        case 0: puts("引き分けです。\n");
                break;
        case 1: puts("あなたの負けです。\n");
                break;
        case 2: puts("あなたの勝ちです。\n");
                break;
        }
    }

    free(human_hands);
    free(comp_hands);
    free(result);
    return 0;
}