#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;

    do {
        if ((c2 = clock()) == (clock_t)-1)
            return 0;
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

void telop(const char *s, int direction, int speed, int n)
{
    int str_len = strlen(s);
    int cnt = 0;

    for (int c = 0; c < n; c++) {
        putchar('\r');

        for (int i = 0; i < str_len; i++) {
            if (cnt + i < str_len)
                putchar(s[cnt + i]);
            else
                putchar(s[cnt + i - str_len]);
        }

        fflush(stdout);
        sleep(speed);

        if (direction == 0) {
            if (cnt < str_len - 1)
                cnt++;
            else
                cnt = 0;
        } else {
            if (cnt > 0)
                cnt--;
            else
                cnt = str_len - 1;
        }
    }
}

int main(void) {
    telop("ASDFGH  ", 0, 500, 20);

    return 0;
}

