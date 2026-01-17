#include <stdio.h>
#include <stdlib.h>
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

void gput(const char *s, int speed)
{
    for (int i = 0; i < sizeof(s)/sizeof(typeof(s[0])); i++) {
        putchar(s[i]);
        fflush(stdout);
        sleep(speed);
    }
    printf("\n");
}

int main(void)
{
    gput("ABC", 1000);

    return 0;
}