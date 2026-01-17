#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int sleep(unsigned long x)
{
    clock_t c1 = clock(), c2;

    do {
        if ((c2 = clock()) == (clock_t)-1)
            return 0;
    } while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
    return 1;
}

void bput(const char *s, int d, int e, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%s", s);
        fflush(stdout);
        sleep(d);

        for (int j = 0; j < (int)strlen(s) ;j++) {
            printf("\b \b");
            fflush(stdout);
        }
        sleep(e);
    }
}

int main(void)
{
    bput("ABCD", 200, 500, 6);
    return 0;
}