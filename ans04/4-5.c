#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

void make4colors(char ans[], char x[])
{
    int used[8] = {0};

    for (int i = 0; i < N; i++) {
        int j, val;
        do {
            val = rand() % 8;
        } while (used[val]);
        used[val] = 1;
        ans[i] = x[val];
    }
    ans[N] = '\0';
}

int check(const char s[], const char color[])
{
    if (strlen(s) != N)
        return 1;
    
    for (int i = 0; i < N; i++) {
        if (!strchr(color, s[i]))
            return 2;
        for (int j = 0; j < i; j++) {
            if (s[i] == s[j])
                return 3;
        }
    }
    return 0;
}


const char *corr(char s)
{
    switch (s) {
        case 'W': return "白";
        case 'B': return "黒";
        case 'R': return "赤";
        case 'b': return "青";
        case 'Y': return "黄";
        case 'G': return "緑";
        case 'O': return "橙";
        case 'T': return "茶";
    }
}

void judge(const char s[], const char color[], int *hit, int *blow)
{
    *hit = *blow = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i] == color[j]) {
                if (i == j)
                    (*hit)++;
                else
                    (*blow)++;
            }
        }
    }
}

void print_result(int snum, int spos)
{
    if (spos == 4)
        printf("正解です!!");
    else if (snum == 0)
        printf("\tそれらの色は全く含まれません。\n");
    else {
        printf("\tそれらの色中%d個の色が含まれます。\n", snum);

        if (spos == 0)
            printf("\tただし位置もあっている色はありません。\n");
        else
            printf("\tその中の%d個は位置もあっています。\n", spos);
    }
    putchar('\n');
}

void print_names(const char s[])
{
    printf("あなたの入力 : ");
    for (int i = 0; i < N; i++) {
        printf("%c(%s)", s[i], corr(s[i]));
    }
    putchar('\n');
}

int main(void)
{
    srand(time(NULL));

    puts("・マスターマインドをしよう!!");
    puts("　当てるのは、4個の色の並びです。");
    puts("　同じ色が複数含まれることはありません。");
    puts("　黒青茶黄のように連続して入力してください。");
    puts("　スペース文字などを入力してはいけません。");
    printf("入力できる色は次の通りです。 : ");
    printf("W=白, B=黒, R=赤, b=青, Y=黄, G=緑, O=橙, T=茶\n");

    char color[] = "WBRbYGOT";

    char ans[N + 1];
    make4colors(ans, color);

    int hit;
    int blow;
    int try_no = 0;

    time_t start = time(NULL);

    do {
        int chk;
        char buff[10];

        do {
            printf("入力してください : ");
            scanf("%s", buff);

            chk = check(buff, color);

            switch (chk) {
                case 1: puts("きちんと4文字で入力してください。\a"); break;
                case 2: puts("色以外の文字を入力しないでください。\a"); break;
                case 3: puts("同一の色を複数入力しないでください。\a"); break;
            }
        } while (chk != 0);

        try_no++;
        judge(buff, ans, &hit, &blow);
        print_result(hit + blow, hit);
    } while (hit < 4);

    time_t end = time(NULL);

    printf("%d回かかりました。\n所要時間は%.1f秒でした。\n", try_no, difftime(end, start));

    return 0;
}