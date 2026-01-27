#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int max(const int x[], int n)
{
    int m = x[0];
    for (int i = 1; i < n; i++) {
        if (x[i] > m) m = x[i];
    }
    return m;
}

int dayofweek(int year, int month, int day)
{
    if (month == 1 || month == 2) {
        year--;
        month += 12;
    }
    return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}

int is_leap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

int monthdays(int year, int month)
{
    if (month-- != 2)
        return mday[month];
    return mday[month] + is_leap(year);
}

int make_calendar(int y, int m, char s[7][22])
{
    int wd = dayofweek(y, m, 1);
    int mdays = monthdays(y, m);
    int weeks = (wd + mdays + 6) / 7;
    char tmp[4];

    sprintf(s[0], "%10d / %02d    ", y, m);

    int k;
    for (k = 1; k < 7; k++) {
        s[k][0] = '\0';
    }
    k = 1;
    sprintf(s[k], "%*s", 3 * wd, "");

    for (int i = 1; i <= mdays; i++) {
        sprintf(tmp, "%3d", i);
        strcat(s[k], tmp);
        if (++wd % 7 == 0)
            k++;
    }

    if (wd % 7 == 0)
        k--;
    else {
        for (wd %= 7; wd < 7; wd++)
            strcat(s[k], "   ");
    }

    while (++k < 7)
        sprintf(s[k], "%21s", "");

    return weeks;
}

void print(char sbuf[3][7][22], int *weeks, int n, int maxweeks)
{
    for (int i = 0; i < n; i++) {
        printf("%s", sbuf[i][0]);
        if (i != n - 1) printf("   ");
    }
    putchar('\n');

    for (int i = 0; i < n; i++) {
            printf(" 日 月 火 水 木 金 土");
            if (i != n - 1) printf("   ");
    }
    putchar('\n');

    for (int i = 0; i < n; i++) {
        printf("----------------------");
        if (i != n - 1) printf("  ");
    }
    putchar('\n');

    for (int row = 1; row <= maxweeks; row++) {
        for (int col = 0; col < n; col++) {
            if (weeks[col] >= row) {
                printf("%s", sbuf[col][row]);
                
            } else {
                printf("                     ");
            }
            if (col != n - 1) printf("  ");
        }
        putchar('\n');
    }
    putchar('\n');
}

void put_calendar(int y1, int m1, int y2, int m2)
{
    int y = y1;
    int m = m1;
    int n = 0; 

    int weeks[3] = {0, 0, 0};
    int maxweeks = 0;

    char sbuf[3][7][22];

    while (y <= y2) {
        if (y == y2 && m > m2) break;
        weeks[n] = make_calendar(y, m, sbuf[n]);
        n++;
        if (n == 3) {
            maxweeks = max(weeks, n);
            print(sbuf, weeks, n, maxweeks);
            n = 0;
        }
        m++;
        if (m == 13 && y < y2) {
            y++;
            m = 1;
        }
    }
    if (n) {
        int maxweeks = max(weeks, n);
        print(sbuf, weeks, n, maxweeks);
    }
}

int main(void)
{
    int y1, m1, y2, m2;

    printf("カレンダーを表示します。\n");

    printf("開始年 : ");scanf("%d", &y1);

    do {
        printf("　　月 : "); scanf("%d", &m1);
    } while (m1 <= 0 || 12 < m1);

    do {
        printf("終了年 : "); scanf("%d", &y2);
    } while (y2 < y1);

    do {
        printf("　　月 : "); scanf("%d", &m2);
    } while (m2 <= 0 || 12 < m2);

    putchar('\n');

    put_calendar(y1, m1, y2, m2);

    return 0;
}